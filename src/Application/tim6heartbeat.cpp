#include "tim6heartbeat.h"

// 最快也只能是10ms
#define MIN_TIME (10)

namespace QIU {
namespace PJ0 {
// private
u16 t6_event_enable;  //事件是否有效
u16 t6_event_time[16]; //事件定时事件
void (*t6_events[16])(void);
// __heartbeat_event__ t6_events[16];
void tim6_event_do_nothing(void) {
	//DO NOTHING
}
// public
u32 t6_event_time_count[16]; //定时当前时间
u32 t6_timestamp_h32;
u32 t6_timestamp_l32;

// 初始化
extern void tim6_heartbeat_init() {
	t6_timestamp_h32 = 0;
	t6_timestamp_l32 = 0;
	t6_event_enable = 0;
	for (u8 i = 0; i < 16; i++) {
		*(t6_event_time + i) = MIN_TIME;
		*(t6_event_time_count + i) = 0;
		*(t6_events + i) = tim6_event_do_nothing;
	}
}
// 用于主循环中
extern void tim6_heartbeat_main_loop_function() {
	for (u8 i = 0; i < 16; i++) {
		if ((t6_event_enable & (1 << i)) != 0) {
			if (*(t6_event_time_count + i) >= *(t6_event_time + i)) {
				*(t6_event_time_count + i) = 0;
				if (*(t6_events + i) != 0) {
					(*(t6_events[i]))();
				}
			}
		}
	}
}
// 添加定时任务
extern void tim6_heartbeat_add_event(u8 num, __heartbeat_event__ f, u16 ms) {
	num &= 0x0F; //只保留低4位
	ms = ms < MIN_TIME ? MIN_TIME : ms;
	t6_event_enable &= ~(1 << num);
	*(t6_events + num) = f; // 注册事件
	*(t6_event_time + num) = ms;
	*(t6_event_time_count + num) = 0;
	t6_event_enable |= (1 << num);
}
// 添加定时任务
extern void tim6_heartbeat_del_event(u8 num) {
	num &= 0x0F; //只保留低4位
	t6_event_enable &= ~(1 << num);
	*(t6_events + num) = tim6_event_do_nothing;
	*(t6_event_time + num) = MIN_TIME;
}

}
}
