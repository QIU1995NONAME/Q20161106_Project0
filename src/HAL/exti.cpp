#include "exti.h"
namespace QIU {
namespace PJ0 {
//
EXTI_InitTypeDef exti_init;
// 按键中断
inline void exti_config_key(void) {
	// 将4个按键(PA0 PE2 PE3 PE4)设置为4个外部中断线路
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource2);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4);

	// 配置外部中断 PA0 上升沿触发
	exti_init.EXTI_LineCmd = ENABLE;
	exti_init.EXTI_Trigger = EXTI_Trigger_Rising;
	exti_init.EXTI_Mode = EXTI_Mode_Interrupt;
	exti_init.EXTI_Line = EXTI_Line0;
	EXTI_Init(&exti_init);

	// 配置外部中断 PE2 PE3 PE4下降沿触发
	exti_init.EXTI_Trigger = EXTI_Trigger_Falling;
	exti_init.EXTI_Line = EXTI_Line2;
	EXTI_Init(&exti_init);
	exti_init.EXTI_Line = EXTI_Line3;
	EXTI_Init(&exti_init);
	exti_init.EXTI_Line = EXTI_Line4;
	EXTI_Init(&exti_init);
}
//编码器中断
inline void exti_config_e6a2(void) {
	// 将编码器的A相(PB6)设置为外部中断线路
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource6);

	// 配置外部中断 PB6 上升沿触发
	exti_init.EXTI_LineCmd = ENABLE;
	exti_init.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	exti_init.EXTI_Mode = EXTI_Mode_Interrupt;
	exti_init.EXTI_Line = EXTI_Line6;
	EXTI_Init(&exti_init);
}
//外部中断配置
extern void exti_config(void) {
	// 各项外部中断配置
	// FIXME 按键中断被关闭
//	exti_config_key();
	exti_config_e6a2();
}

}
}
