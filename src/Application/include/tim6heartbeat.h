#ifndef __TIM6_HEARTBEAT_H__
#define __TIM6_HEARTBEAT_H__

#include "stm32f10x.h"

namespace QIU {
namespace PJ0 {
// 时间戳的秒部分 跟随RTC行动
extern u32 t6_timestamp_s;
// 时间戳的毫秒部分
extern u16 t6_timestamp_ms;
// 定时当前时间
extern u32 t6_event_time_count[16];

typedef void (*__heartbeat_event__)(void);

/**
 * 初始化
 */
extern void tim6_heartbeat_init(void);
/**
 * 放置主循环中用来监控各个时钟的状态
 */
extern void tim6_heartbeat_main_loop_function(void);
/**
 * 添加定时任务
 * @param num 定时任务号 0~15 只看低4位
 * @param f   定时任务的任务指针
 * @param ms  多少毫秒执行一次定时任务
 */
extern void tim6_heartbeat_add_event(u8 num, __heartbeat_event__ f, u16 ms);
/**
 * 移除定时任务
 */
extern void tim6_heartbeat_del_event(u8 num);
/**
 * 查询是否存在定时任务
 * @param num 任务号
 * @return 1 存在 0 不存在
 */
extern s8 tim6_heartbeat_has_event(u8 num);
}
}

#endif /* __TIM6_HEARTBEAT_H__ */
