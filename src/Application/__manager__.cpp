#include "__manager__.h"
#include "__includes__.h"

namespace QIU {
namespace PJ0 {
// 用于处理数据用的缓冲区
u8* manager_cmd_r_buffer_1k = 0;
u8* manager_cmd_s_buffer_1k = 0;
// 心跳计数
s8 manager_heartbeat_count = 0;
/// 0x00 心跳功能 1S刷新一次
void manager_heartbeat_task_1000ms(void) {
	if (manager_heartbeat_count == 0) {
		led_display(0x80);
	} else {
		led_display(0x40);
		manager_heartbeat_count--;
		// 发送心跳回应
		*manager_cmd_s_buffer_1k = 0x77;
		u32 t_s = t6_timestamp_s;
		u8 pointer = 1;
		u8 datebyte = 0;
		// 时间戳 秒
		datebyte = 0xFF & (t_s);
		*(manager_cmd_s_buffer_1k + pointer++) = datebyte;
		t_s >>= 8;
		datebyte = 0xFF & (t_s);
		*(manager_cmd_s_buffer_1k + pointer++) = datebyte;
		t_s >>= 8;
		datebyte = 0xFF & (t_s);
		*(manager_cmd_s_buffer_1k + pointer++) = datebyte;
		t_s >>= 8;
		datebyte = 0xFF & (t_s);
		*(manager_cmd_s_buffer_1k + pointer++) = datebyte;
		// 若干状态值
		cmd_buffer_send_data(manager_cmd_s_buffer_1k, pointer);
	}
}
/// 0x01 定时发送 50ms发送一份
void manager_sampling_data_send_50ms(void) {
	// 底层采样没有启动
	if (!sampling_is_running) {
		tim6_heartbeat_del_event(0x01);
		return;
	}
	// 心跳停止
	if (manager_heartbeat_count == 0) {
		tim6_heartbeat_del_event(0x01);
		return;
	}
	// 获取最近的记录
	const SamplingData * data = sampling_data_get_last();
	// 获取失败
	if (data == 0) {
		return;
	}
	// 组合数据
	*manager_cmd_s_buffer_1k = 0x69;
	memory_copy(manager_cmd_s_buffer_1k + 1, data, sizeof(SamplingData));
	// 发送数据
	cmd_buffer_send_data(manager_cmd_s_buffer_1k, 1 + sizeof(SamplingData));
}
/**
 * 时间同步功能
 */
inline void manager_0x78_changetime(void) {
	u32 second = 0;
	second |= *(manager_cmd_r_buffer_1k + 4);
	second <<= 8;
	second |= *(manager_cmd_r_buffer_1k + 3);
	second <<= 8;
	second |= *(manager_cmd_r_buffer_1k + 2);
	second <<= 8;
	second |= *(manager_cmd_r_buffer_1k + 1);
	rtc_set_counter(second);
}
/**
 * 心跳是否在维持着
 * @return 心跳是否在维持着
 */
extern s8 manager_heartbeat_is_running(void) {
	return manager_heartbeat_count != 0;
}
/**
 * 管理器主循环
 * 除了主循环以外不得被任何其他方式调用
 */
extern void manager_main_loop_function(void) {
	static s16 st_res;
	//尝试接收命令
	st_res = cmd_buffer_analyze_data(manager_cmd_r_buffer_1k);
	do {
		// 如果没有接收到数据
		if (st_res == 0) {
			break;
		}
		// 如果数据有问题
		if (st_res < 0) {
			// FIXME 没有处理过程
			break;
		}
		// 如果接收到了数据
		switch (*(manager_cmd_r_buffer_1k)) {
		case 0x77: // XXX 0x77 收到心跳请求
			manager_heartbeat_count = 7;
			break;
		case 0x78: // XXX 0x78 时间同步
			// 长度至少为5
			if (st_res > 4) {
				manager_0x78_changetime();
			}
			break;
		case 0x60: // XXX 0x60 底层采样功能停止
			if (sampling_is_running) {
				sampling_stop();
			}
			break;
		case 0x61: // XXX 0x61 底层采样功能启动
			if (!sampling_is_running) {
				sampling_start();
			}
			break;
		case 0x68: // XXX 0x68 串口采样功能停止
			tim6_heartbeat_del_event(0x01);
			break;
		case 0x69: // XXX 0x69 串口采样功能启动
			tim6_heartbeat_add_event(0x01, manager_sampling_data_send_50ms, 50);
			break;
		default:
			// 未知指令
			;
		}
	} while (0);
}
/**
 * 管理器初始化
 * 一旦初始化失败应当立刻进入死循环。
 * @return 0 初始化成功
 *         否则初始化失败
 */
extern s8 manager_init(void) {
	manager_cmd_r_buffer_1k = (u8*) memory_alloc_1k();
	if (!manager_cmd_r_buffer_1k) {
		return -1;
	}
	manager_cmd_s_buffer_1k = (u8*) memory_alloc_1k();
	if (!manager_cmd_s_buffer_1k) {
		return -1;
	}
	// 初始化心跳
	manager_heartbeat_count = 0;
	tim6_heartbeat_add_event(0x00, manager_heartbeat_task_1000ms, 1000);

	// TODO 其他初始化任务
	return 0;
}
}
}
