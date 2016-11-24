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
/// 采样功能是否正在运行
extern s8 sampling_is_running;
/**
 * 采样数据结构
 * 除了时间戳以外还需要什么样的数据
 * （每一个采样都会附带一个时间戳）
 */
typedef struct REAL_TIME_SAMPLING_DATA {
	u32 rtsd_timestamp_s; // 时间戳_秒
	u16 rtsd_timestamp_ms; // 时间戳_毫秒
	u16 rtsd_fan_level; // 风扇转速等级
	s32 rtsd_angle; // 光电编码器数值(也就是角度) 单位 千分之一圈
	s32 rtsd_step_count; // 步进电机当前的步数
} SamplingData;
/**
 * 采样缓冲拥有多少条数据
 * @return 缓冲区中已有的数据条数
 *         如果返回负值，说明缓冲区不可用。
 */
extern s16 sampling_data_length(void);
/**
 * 移除第一条记录
 */
extern void sampling_data_remove_first(void);
/**
 * 获取缓冲区第一条记录的指针
 * @return 第一条记录的指针
 */
extern const SamplingData * sampling_data_get_first(void);
/**
 * 获取缓冲区最后一条记录的指针。
 * 这个函数主要用于向串口发送数据用。
 * @return 最后一条记录的指针
 */
extern const SamplingData * sampling_data_get_last(void);
/**
 * 复制一个采样数据
 * @param dest 数据复制的目标
 * @param src  数据复制的源
 * @return 0    复制成功
 *         否则：复制失败
 */
extern s8 sampling_data_clone(SamplingData * dest, const SamplingData * src);
/**
 * 返回采样缓冲区是否为空
 * @return 0   非空
 *         其他  空
 */
extern s8 sampling_data_is_empty(void);
/**
 * 返回采样缓冲区是否已满
 * @return 0   未满
 *         其他  已满
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
/**
 * 用在主循环中的函数
 */
extern void sampling_main_loop_function(void);
/**
 * 启动定时采样
 */
inline void sampling_start(void) {
	sampling_is_running = 1;
}
/**
 * 关闭定时采样
 */
inline void sampling_stop(void) {
	sampling_is_running = 0;
}

}
}

#endif // __SAMPLING_H__
