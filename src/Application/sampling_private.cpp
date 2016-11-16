#include "sampling_private.h"
#include "memory.h"

namespace QIU {
namespace PJ0 {
// 采样间隔 - 1(毫秒)
u16 sampling_data_interval = 4;
// 缓冲区第一个数据
u16 sampling_data_first = 0;
// 缓冲区接下来可以用的数据区
u16 sampling_data_next_write = 0;
// 主缓冲区
SamplingData * sampling_data_buffer = 0;
/**
 * 设置底层采样间隔(毫秒)
 */
extern void sampling_data_set_interval(u16 interval) {
	if (interval < SAMPLING_DATA_INTERVAL_MIN) {
		interval = SAMPLING_DATA_INTERVAL_MIN;
	}
	if (interval > SAMPLING_DATA_INTERVAL_MAX) {
		interval = SAMPLING_DATA_INTERVAL_MAX;
	}
	sampling_data_interval = interval - 1;
}
/**
 * 获取当前底层采样间隔
 */
extern u16 sampling_data_get_interval(void) {
	return sampling_data_interval + 1;
}
/**
 * 获取下一个缓存写入指针
 * 仅用于中断！要保证中断在调用了这个函数之后，必须立即把对应的数据进行赋值，否则会出现无法预知的错误。
 * @return 0 获取失败
 */
extern SamplingData * sampling_write_next(void) {
	// 如果缓冲区已经满了
	if (sampling_data_is_full()) {
		return 0;
	}
	// 如果还没有满
	SamplingData * psdata = sampling_data_buffer + sampling_data_next_write;
	sampling_data_next_write++;
	if (sampling_data_next_write >= SAMPLING_DATA_LENGTH_MAX) {
		sampling_data_next_write -= SAMPLING_DATA_LENGTH_MAX;
	}
	return psdata;
}
/**
 * 采样缓冲拥有多少条数据
 * @return 缓冲区中已有的数据条数
 *         如果返回负值，说明缓冲区不可用。
 */
extern s16 sampling_data_length(void) {

	u16 len = sampling_data_next_write;
	if (len < sampling_data_first) {
		len += SAMPLING_DATA_LENGTH_MAX;
	}
	len -= sampling_data_first;
	return len;
}
/**
 * 强制初始化。
 * 包括初始化一个大一些的缓冲，
 * 创建环形缓冲列表等。
 * @return 0 为初始化成功
 *         否则为初始化失败
 */
extern s8 sampling_init_0(void) {
	if (sampling_data_buffer) {
		memory_free(sampling_data_buffer);
		sampling_data_buffer = 0;
	}
	void * p = memory_alloc0_8k();
	if (!p) {
		// 内存不足
		return -1;
	}
	sampling_data_buffer = (SamplingData *) (p);
	sampling_data_first = 0;
	sampling_data_next_write = 0;
	sampling_data_interval = 4;
	return 0;
}

}
}
