#include "timer.h"

namespace QIU {
namespace PJ0 {
// 用到的初始化变量
TIM_TimeBaseInitTypeDef timer_init;
TIM_OCInitTypeDef timer_ocinit;
// 高级定时器 TIM1
inline void timer_config_1(void) {

}
//
inline void timer_config_8(void) {

}
//
inline void timer_config_2(void) {
	// TIM2 初始化 用于中断 1ms
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	// 时钟频率 = 72MHz / ( 预分频值 + 1 )
	timer_init.TIM_Prescaler = 3600 - 1; // 预分频值,得到频率20KHz
	// 向上向下计数模式:  定时时间 = ( 自动重装载值 + 1 ) / 时钟频率
	// 中央对齐计数模式:  定时时间 = ( 自动重装载值 + 0 ) / 时钟频率
	timer_init.TIM_CounterMode = TIM_CounterMode_Up; // 向上计数模式
	timer_init.TIM_Period = 20 - 1; // 自动重装载值
	timer_init.TIM_ClockDivision = 0; // 时钟分割
	TIM_TimeBaseInit(TIM2, &timer_init);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE); // 定时采样中断暂时关闭，在应用层启动定时中断
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // 清除中断标记
	TIM_Cmd(TIM2, ENABLE); // 使能TIM2
}
//
inline void timer_config_3(void) {
	// TIM3 初始化 用于PWM
	timer_init.TIM_Prescaler = 60000; // 预分频值  时钟频率 = 72MHz / ( 预分频值 + 1 )
	timer_init.TIM_CounterMode = TIM_CounterMode_Up; // 向上计数
	timer_init.TIM_Period = 40 - 1; // 自动重装载值
	timer_init.TIM_ClockDivision = 0; // 时钟分割
	TIM_TimeBaseInit(TIM3, &timer_init);
	TIM_ARRPreloadConfig(TIM3, ENABLE);
	// TIM3的GPIO 部分复用功能启动
	// 根据重映射表 TIM3 CH1 PB4
	// 根据重映射表 TIM3 CH2 PB5
	// 根据重映射表 TIM3 CH3 PB0
	// 根据重映射表 TIM3 CH4 PB1
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);
	timer_ocinit.TIM_OCMode = TIM_OCMode_PWM1;
	timer_ocinit.TIM_OutputState = TIM_OutputState_Enable;
	timer_ocinit.TIM_OCPolarity = TIM_OCPolarity_High;
//	TIM_OC1Init(TIM3, &timer_ocinit);	// PB4
	TIM_OC2Init(TIM3, &timer_ocinit);	// PB5
//	TIM_OC3Init(TIM3, &timer_ocinit);	// PB0
//	TIM_OC4Init(TIM3, &timer_ocinit);	// PB1
			//启动TIM3的CCR1寄存器
//	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
			//启动TIM3的CCR2寄存器
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
	//启动TIM3的CCR3寄存器
//	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	//启动TIM3的CCR4寄存器
//	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
	//使能TIM3
	TIM_Cmd(TIM3, ENABLE);
}
//
inline void timer_config_4(void) {
	// TIM3 初始化 用于PWM
	timer_init.TIM_Prescaler = 0; // 预分频值  时钟频率 = 72MHz / ( 预分频值 + 1 )
	timer_init.TIM_CounterMode = TIM_CounterMode_Up; // 向上计数
	timer_init.TIM_Period = 1800 - 1; // 自动重装载值
	timer_init.TIM_ClockDivision = 0; // 时钟分割
	TIM_TimeBaseInit(TIM4, &timer_init);
	TIM_ARRPreloadConfig(TIM4, ENABLE);
	// TIM4的GPIO 复用功能启动 重映射功能禁用
	// 根据映射表 TIM4 CH1 PB6
	// 根据映射表 TIM4 CH2 PB7
	// 根据映射表 TIM4 CH3 PB8
	// 根据映射表 TIM4 CH4 PB9
	timer_ocinit.TIM_OCMode = TIM_OCMode_PWM1;
	timer_ocinit.TIM_OutputState = TIM_OutputState_Enable;
	timer_ocinit.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC3Init(TIM4, &timer_ocinit);	// PB8
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);
	TIM_Cmd(TIM4, ENABLE);
}
//
inline void timer_config_5(void) {

}
//
inline void timer_config_6(void) {
	TIM_ClearITPendingBit(TIM6, TIM_IT_Update);
	timer_init.TIM_Prescaler = 36000 - 1;
	timer_init.TIM_CounterMode = TIM_CounterMode_Up;
	timer_init.TIM_Period = 2 - 1;
	timer_init.TIM_ClockDivision = 0;
	TIM_TimeBaseInit(TIM6, &timer_init);
	TIM_Cmd(TIM6, ENABLE);
	TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);
}
//
inline void timer_config_7(void) {

}
//
extern void timer_config(void) {
	// 定时器时钟使能
	// 高级定时器
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, DISABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, DISABLE);
	// 通用定时器
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, DISABLE);
	// 基本定时器
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, DISABLE);

	// 各个定时器初始化
	timer_config_1();
	timer_config_8();
	timer_config_2();
	timer_config_3();
	timer_config_4();
	timer_config_5();
	timer_config_6();
	timer_config_7();
}

}
}
