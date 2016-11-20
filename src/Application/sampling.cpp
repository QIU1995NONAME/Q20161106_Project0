#include "sampling_private.h"
#include "memory.h"

namespace QIU {
namespace PJ0 {
/**
 * 移除第一条记录
 */
extern void sampling_data_remove_first(void) {
	// 如果为空，则没有动作
	if (sampling_data_is_empty()) {
		return;
	}
	// 移动指针
	sampling_data_first++;
	if (sampling_data_first >= SAMPLING_DATA_LENGTH_MAX) {
		sampling_data_first -= SAMPLING_DATA_LENGTH_MAX;
	}
}
/**
 * 获取缓冲区第一条记录的指针。
 * 这个函数主要用于向SD卡中写数据用。
 * @return 第一条记录的指针
 */
extern const SamplingData * sampling_data_get_first(void) {
	if (sampling_data_is_empty()) {
		return 0;
	}
	SamplingData * res = sampling_data_buffer + sampling_data_first;
	return res;
}
/**
 * 获取缓冲区最后一条记录的指针。
 * 这个函数主要用于向串口发送数据用。
 * @return 最后一条记录的指针
 */
extern const SamplingData * sampling_data_get_last(void) {
	if (sampling_data_is_empty()) {
		return 0;
	}
	u16 p = sampling_data_next_write;
	if (p == 0) {
		p += SAMPLING_DATA_LENGTH_MAX;
	}
	p--;
	SamplingData * res = sampling_data_buffer + p;
	return res;
}
/**
 * 复制一个采样数据
 * @param dest 数据复制的目标
 * @param src  数据复制的源
 * @return 0    复制成功
 *         否则：复制失败
 */
extern s8 sampling_data_clone(SamplingData * dest, SamplingData * src) {
	if (dest == 0 || src == 0) {
		return 1;
	}
	dest->rtsd_timestamp_s = src->rtsd_timestamp_s;
	dest->rtsd_timestamp_ms = src->rtsd_timestamp_ms;
	dest->rtsd_angle = src->rtsd_angle;
	dest->rtsd_fan_level = src->rtsd_fan_level;
	dest->rtsd_step_count = src->rtsd_step_count;
	return 0;
}
/**
 * 返回采样缓冲区是否为空
 * @return 0   非空
 *         其他  空
 */
extern s8 sampling_data_is_empty(void) {
	// 如果缓冲区不可用 直接返回为空
	if (!sampling_data_buffer) {
		return 1;
	}
	return (sampling_data_length() == 0);
}
/**
 * 返回采样缓冲区是否已满
 * @return 0   未满
 *         其他  已满
 */
extern s8 sampling_data_is_full(void) {
	// 如果缓冲区不可用 直接返回已满
	if (!sampling_data_buffer) {
		return 1;
	}
	return (sampling_data_length() >= SAMPLING_DATA_LENGTH_LIMIT);
}
/**
 * 初始化。包括初始化一个大一些的缓冲。
 * 创建环形缓冲列表。
 */
extern s8 sampling_init(void) {
	if (!sampling_data_buffer) {
		return sampling_init_0();
	}
	return 0;
}

}
}
