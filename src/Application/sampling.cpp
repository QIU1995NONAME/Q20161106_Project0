#include "sampling_private.h"
#include "memory.h"

namespace QIU {
namespace PJ0 {
/// 采样功能是否正在运行
s8 sampling_is_running = 0;
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
extern s8 sampling_data_clone(SamplingData * dest, const SamplingData * src) {
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
/**
 * 用在主循环中的函数
 * 主要用于将缓存的数据存入SD
 */
extern void sampling_main_loop_function(void) {
	static s8 need_save;
	// 实时采样功能是否初始化
	// 未初始化则直接跳过
	if(!sampling_data_buffer){
		return;
	}
	// 实时采样功能是否正在运行
	if(sampling_is_running){
		// 这个模式下要保留最近的5条数据
		if(sampling_data_length()>5){
			need_save = 1;
		}else{
			need_save = 0;
		}
	}else{
		if(sampling_data_length()>0){
			need_save = 1;
		}else{
			need_save = 0;
		}
	}
	if(need_save){
		const SamplingData * data = sampling_data_get_first();
		if(data == 0){
			return;
		}
		sampling_file_append(data);
		sampling_data_remove_first();
	}
}

}
}
