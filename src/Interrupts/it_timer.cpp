#include "stm32f10x.h"
#include "stm32f10x_it.h"
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

}
void TIM3_IRQHandler(void) {
	// UNUSED
}
void TIM4_IRQHandler(void) {
}
void TIM5_IRQHandler(void) {
}
void TIM6_IRQHandler(void) {
	t6_timestamp_l32++;
	if (t6_timestamp_l32 == 0) {
		t6_timestamp_h32++;
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
