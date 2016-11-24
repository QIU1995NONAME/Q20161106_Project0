#include "nvic.h"

namespace QIU {
namespace PJ0 {
//
NVIC_InitTypeDef nvic_init;
// 按键中断 FIXME 已经被关闭
inline void nvic_config_exti_key(void) {
	nvic_init.NVIC_IRQChannel = EXTI0_IRQn;
	nvic_init.NVIC_IRQChannelPreemptionPriority = 7;
	nvic_init.NVIC_IRQChannelSubPriority = 0;
	nvic_init.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic_init);

	nvic_init.NVIC_IRQChannel = EXTI2_IRQn;
	nvic_init.NVIC_IRQChannelPreemptionPriority = 7;
	nvic_init.NVIC_IRQChannelSubPriority = 0;
	nvic_init.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic_init);

	nvic_init.NVIC_IRQChannel = EXTI3_IRQn;
	nvic_init.NVIC_IRQChannelPreemptionPriority = 7;
	nvic_init.NVIC_IRQChannelSubPriority = 0;
	nvic_init.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic_init);

	nvic_init.NVIC_IRQChannel = EXTI4_IRQn;
	nvic_init.NVIC_IRQChannelPreemptionPriority = 7;
	nvic_init.NVIC_IRQChannelSubPriority = 0;
	nvic_init.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic_init);
}
// 光电编码器E6A2中断
inline void nvic_config_exti_e6a2(void) {
	// 光电编码器计数
	nvic_init.NVIC_IRQChannel = EXTI9_5_IRQn;
	nvic_init.NVIC_IRQChannelPreemptionPriority = 0;
	nvic_init.NVIC_IRQChannelSubPriority = 0;
	nvic_init.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic_init);
}
// 定时器中断
inline void nvic_config_timer(void) {
	// 定时采样
	nvic_init.NVIC_IRQChannel = TIM2_IRQn;
	nvic_init.NVIC_IRQChannelPreemptionPriority = 1;
	nvic_init.NVIC_IRQChannelSubPriority = 0;
	nvic_init.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic_init);
	//　定时任务系统
	nvic_init.NVIC_IRQChannel = TIM6_IRQn;
	nvic_init.NVIC_IRQChannelPreemptionPriority = 2;
	nvic_init.NVIC_IRQChannelSubPriority = 0;
	nvic_init.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvic_init);
}
// 串口中断
inline void nvic_config_usart(void) {
	// USART1中断
	nvic_init.NVIC_IRQChannel = USART1_IRQn;
	nvic_init.NVIC_IRQChannelCmd = ENABLE;
	nvic_init.NVIC_IRQChannelPreemptionPriority = 3;
	nvic_init.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&nvic_init);
}
/**
 * 嵌套向量中断控制器 中断优先级配置
 */
extern void nvic_config(void) {
	// 中断分级 3位抢占 1位响应
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);
	// 各项中断配置
	// FIXME 按键中断被关闭
//	nvic_config_exti_key();
	nvic_config_timer();
	nvic_config_usart();
	nvic_config_exti_e6a2();
}

}
}
