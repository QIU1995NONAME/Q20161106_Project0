#include "q_signal.h"
#include "memory.h"

namespace QIU {
namespace PJ0 {

/**
 * 这是一个很简单的小型的信号系统
 * 因为单片机本身是单线程的，所以这个信号系统不考虑多线程的同步与异步问题
 * 信号系统中主要的两种属性，使用者 以及其所具有的信号
 * 使用者包括信号源以及信号监听器。每一个使用者都可以注册 发送信号以及监听别的信号
 * 在这个实现(Implementation)中，存储着使用者(s16)，他们的某些信号是否注册(u16)，是否触发(u16)
 */
typedef struct SIGNAL_SOURCE_STRUCT {
	s16 signal_source_id;
	u16 signal_registered;
	u16 signal_triggered;
} Signal;
// 记录包括系统信号源在内的使用者最大数量
// 如果分配1K缓冲 6字节一条记录 则可以容纳170条记录
const s16 MAX_SOURCE_COUNT = 150; // 留出一些富裕
// 记录信号源用的缓冲区ID
Signal * signal_source_list = 0;
// 信号系统初始化是否成功 0为成功 1为失败
s16 signal_sys_status = 1;
// 记录下一个使用者ID
s16 signal_source_next_id = 0;
extern s8 signal_create_source(void) {
	if (signal_source_next_id >= MAX_SOURCE_COUNT) {
		return -1;
	}
	Signal * signal = signal_source_list + signal_source_next_id;
	signal->signal_source_id = signal_source_next_id;
	signal->signal_registered = 0;
	signal->signal_triggered = 0;
	return signal_source_next_id++;
}
extern s8 signal_register(s16 source_id, u16 signal_id) {
	Signal * signal = signal_source_list + source_id;
	// 信号源ID 超出范围
	if (source_id >= MAX_SOURCE_COUNT || source_id < 0) {
		return 0;
	}
	// 信号ID 超出范围
	if (signal_id > 15) {
		return 0;
	}
	// 这个信号源还没有初始化
	if (signal->signal_source_id != source_id) {
		return 0;
	}
	// 信号被注册了
	if (signal->signal_registered & (1 << signal_id)) {
		return 0;
	}
	//验证通过 注册信号
	signal->signal_registered |= (1 << signal_id);
	return 1;
}
extern s8 signal_listen(s16 listener_id, s16 source_id, u16 signal_id) {
	Signal * signal = signal_source_list + source_id;
	Signal * listener = signal_source_list + listener_id;
	// 信号源ID 超出范围
	if (source_id >= MAX_SOURCE_COUNT || source_id < 0) {
		return 0;
	}
	// 监听者ID 超出范围
	if (listener_id >= MAX_SOURCE_COUNT || listener_id < 0) {
		return 0;
	}
	// 信号ID 超出范围
	if (signal_id > 15) {
		return 0;
	}
	// 这个信号源还没有初始化
	if (signal->signal_source_id != source_id) {
		return 0;
	}
	// 监听者不存在
	if (listener->signal_source_id != listener_id) {
		return 0;
	}
	// 信号未被注册
	if (!(signal->signal_registered & (1 << signal_id))) {
		return 0;
	}
	// 无权监听
	if (listener_id != 0 && source_id == 0) {
		return 0;
	}
	// 验证通过 获取信号触发状态
	// 如果没有触发
	if (!(signal->signal_triggered & (1 << signal_id))) {
		return 0;
	}
	// 如果触发了 复位这个信号 并返回1
	signal->signal_triggered &= ~(1 << signal_id);
	return 1;
}
extern s8 signal_trigger(s16 source_id, u16 signal_id) {
	Signal * signal = signal_source_list + source_id;
	// 信号源ID 超出范围
	if (source_id >= MAX_SOURCE_COUNT || source_id < 0) {
		return 0;
	}
	// 信号ID 超出范围
	if (signal_id > 15) {
		return 0;
	}
	// 这个信号源还没有初始化
	if (signal->signal_source_id != source_id) {
		return 0;
	}
	// 信号未被注册
	if (!(signal->signal_registered & (1 << signal_id))) {
		return 0;
	}
	// 如果已经触发
	if (signal->signal_triggered & (1 << signal_id)) {
		return 0;
	}
	//验证通过 触发
	signal->signal_triggered |= (1 << signal_id);
	return 1;
}
extern s8 signal_cancel(s16 source_id, u16 signal_id) {
	Signal * signal = signal_source_list + source_id;
	// 信号源ID 超出范围
	if (source_id >= MAX_SOURCE_COUNT || source_id < 0) {
		return 0;
	}
	// 信号ID 超出范围
	if (signal_id > 15) {
		return 0;
	}
	// 这个信号源还没有初始化
	if (signal->signal_source_id != source_id) {
		return 0;
	}
	// 信号未被注册
	if (!(signal->signal_registered & (1 << signal_id))) {
		return 0;
	}
	// 如果没有触发
	if (!(signal->signal_triggered & (1 << signal_id))) {
		return 0;
	}
	//验证通过 取消
	signal->signal_triggered &= ~(1 << signal_id);
	return 1;
}
extern s8 signal_init(void) {
	do {
		// 0 创建缓冲由于这个缓冲是长期有效的 所以初始化需要刷0
		void * p = memory_alloc0_1k();
		if (p == 0) {
			break;
		}
		signal_source_list = (Signal *) p;
		// 1 创建系统信号源
		signal_source_next_id = 0;
		if (signal_create_source() != 0) {
			break;
		}
		// OK
		signal_sys_status = 0;
	} while (0);
	return signal_sys_status;
}

}
}

