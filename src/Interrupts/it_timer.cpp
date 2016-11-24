#include "stm32f10x.h"
#include "stm32f10x_it.h"

#include "e6a2.h"
#include "fan.h"
#include "rtc.h"
#include "sampling_private.h"
#include "tb6560.h"
#include "tim6heartbeat.h"

using namespace QIU::PJ0;

void TIM1_BRK_IRQHandler(void) {
}
void TIM1_UP_IRQHandler(void) {
}
void TIM1_TRG_COM_IRQHandler(void) {
}
void TIM1_CC_IRQHandler(void) {
}
void TIM8_BRK_IRQHandler(void) {
}
void TIM8_UP_IRQHandler(void) {
}
void TIM8_TRG_COM_IRQHandler(void) {
}
void TIM8_CC_IRQHandler(void) {
}
void TIM2_IRQHandler(void) {
	static u16 counter = 0;
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	if (!sampling_is_running) {
		counter = 0;
		return;
	}
	// 目前这个中断是1ms一次
	// 可以根据需要选择多长时间进行一次底层采样
	if (counter < sampling_data_interval) {
		counter++;
	} else {
		counter = 0;
		SamplingData * psdata = sampling_write_next();
		// 缓冲区可用，准备赋值
		if (psdata != 0) {
			psdata->rtsd_timestamp_s = t6_timestamp_s;
			psdata->rtsd_timestamp_ms = t6_timestamp_ms;
			psdata->rtsd_angle = e6a2_read();
			psdata->rtsd_fan_level = fan_get_level();
			psdata->rtsd_step_count = tb6560_get_stepcount();
		}
	}
}
void TIM3_IRQHandler(void) {
	// UNUSED
}
void TIM4_IRQHandler(void) {
}
void TIM5_IRQHandler(void) {
}
void TIM6_IRQHandler(void) {
	t6_timestamp_ms++;
	// 时间戳秒更新不可以完全跟随RTC，应该在毫秒归零的时候跟随RTC。
	// 因为由于初始化等原因，RTC的秒中断和此时间戳的毫秒归零并不在同一时刻。
	// 如果一味地跟随RTC而不考虑自己的毫秒计数的话，很有可能导致时间戳不是单增的。
	// 有可能出现 6.7 7.8 7.9 7.0 7.1 ... 7.6 7.7 8.8 8.9 8.0 这样的序列。
	// 我们容许单片机的时间戳与上位机的时间戳相差5秒以内。
	// 因为此实验中单片机的时间戳仅用来标记数据的时间坐标，需要精确的时间间隔而不是时间点。
	if (t6_timestamp_ms >= 1000) {
		t6_timestamp_ms = 0;
		t6_timestamp_s = rtc_get_counter();
	}
	*(t6_event_time_count + 0x00) += 1;
	*(t6_event_time_count + 0x01) += 1;
	*(t6_event_time_count + 0x02) += 1;
	*(t6_event_time_count + 0x03) += 1;
	*(t6_event_time_count + 0x04) += 1;
	*(t6_event_time_count + 0x05) += 1;
	*(t6_event_time_count + 0x06) += 1;
	*(t6_event_time_count + 0x07) += 1;
	*(t6_event_time_count + 0x08) += 1;
	*(t6_event_time_count + 0x09) += 1;
	*(t6_event_time_count + 0x0A) += 1;
	*(t6_event_time_count + 0x0B) += 1;
	*(t6_event_time_count + 0x0C) += 1;
	*(t6_event_time_count + 0x0D) += 1;
	*(t6_event_time_count + 0x0E) += 1;
	*(t6_event_time_count + 0x0F) += 1;

	TIM_ClearITPendingBit(TIM6, TIM_IT_Update);
}
void TIM7_IRQHandler(void) {
}
