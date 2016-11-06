#ifndef __TIM6_HEARTBEAT_H__
#define __TIM6_HEARTBEAT_H__

#include "stm32f10x.h"

namespace QIU{
namespace PJ0{

extern u32 t6_timestamp_h32;
extern u32 t6_timestamp_l32;
extern u32 t6_event_time_count[16]; //定时当前时间

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
extern void tim6_heartbeat_add_event(u8 num,__heartbeat_event__ f,u16 ms);
/**
 * 移除定时任务
 */
extern void tim6_heartbeat_del_event(u8 num);

}
}

#endif /* __TIM6_HEARTBEAT_H__ */
