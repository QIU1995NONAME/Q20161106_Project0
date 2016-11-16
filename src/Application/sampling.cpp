#include "sampling_private.h"
#include "memory.h"

namespace QIU {
namespace PJ0 {
/**
 * 返回采样缓冲区是否为空
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
 */
extern s8 sampling_data_is_full(void) {
	// 如果缓冲区不可用 直接返回已满
	if (!sampling_data_buffer) {
		return 1;
	}
	return (sampling_data_length() >= SAMPLING_DATA_LENGTH_LIMIT);
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
