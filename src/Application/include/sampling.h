#ifndef __SAMPLING_H__
#define __SAMPLING_H__

#include "stm32f10x.h"

namespace QIU {
namespace PJ0 {
/**
 * 实时采样功能
 * 核心功能：利用中断讲需要采集的数据放入缓冲区
 *         可以直接提取刚刚采集到的数据
 * 扩展功能：利用SD卡将数据永久性的存放在外部。可以用来查阅历史记录
 *         如果没有SD卡，则历史数据只保留很少一部分（可配置）
 */

/**
 * 采样数据结构
 * 除了时间戳以外还需要什么样的数据
 * （每一个采样都会附带一个时间戳）
 */
typedef struct REAL_TIME_SAMPLING_DATA {
	u32 rtsd_timestamp_s; // 时间戳_秒
	u16 rtsd_timestamp_ms; // 时间戳_毫秒
	s32 rtsd_angle; // 光电编码器数值(也就是角度) 单位 千分之一圈
	u16 rtsd_fan_level; // 风扇转速等级
	s32 rtsd_step_count; // 步进电机当前的步数
} SamplingData;
/**
 * 复制一个采样数据
 * @param dest 数据复制的目标
 * @param src  数据复制的源
 * @return 0    复制成功
 *         否则：复制失败
 */
extern s8 sampling_data_clone(SamplingData * dest, SamplingData * src);
/**
 * 返回采样缓冲区是否为空
 */
extern s8 sampling_data_is_empty(void);
/**
 * 返回采样缓冲区是否已满
 */
extern s8 sampling_data_is_full(void);
/**
 * 初始化。
 * 包括初始化一个大一些的缓冲，
 * 创建环形缓冲列表等。
 * @return 0 为初始化成功
 *         否则为初始化失败
 */
extern s8 sampling_init(void);
}
}

#endif // __SAMPLING_H__
