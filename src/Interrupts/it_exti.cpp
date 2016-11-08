#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "systick.h"
#include "e6a2.h"
using namespace QIU::PJ0;

void EXTI0_IRQHandler(void) {
	if (EXTI_GetITStatus(EXTI_Line0) == SET) {
		delay_ms(10); // 消除抖动
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == Bit_SET) {
			// ****************************
			// ****************************
		}
		EXTI_ClearITPendingBit(EXTI_Line0);
	}
}

void EXTI1_IRQHandler(void) {

}

void EXTI2_IRQHandler(void) {
	if (EXTI_GetITStatus(EXTI_Line2) == SET) {
		delay_ms(10); // 消除抖动
		if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2) == Bit_RESET) {
			// ****************************
			// ****************************
		}
		EXTI_ClearITPendingBit(EXTI_Line2);
	}
}

void EXTI3_IRQHandler(void) {
	if (EXTI_GetITStatus(EXTI_Line3) == SET) {
		delay_ms(10); // 消除抖动
		if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3) == Bit_RESET) {
			// ****************************
			// ****************************
		}
		EXTI_ClearITPendingBit(EXTI_Line3);
	}
}

void EXTI4_IRQHandler(void) {
	if (EXTI_GetITStatus(EXTI_Line4) == SET) {
		delay_ms(10); // 消除抖动
		if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) == Bit_RESET) {
			// ****************************
			// ****************************
		}
		EXTI_ClearITPendingBit(EXTI_Line4);
	}
}
void EXTI9_5_IRQHandler(void) {
	// 目前只考虑光电编码器
	if (EXTI_GetITStatus(EXTI_Line6) == SET) {
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)) {
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7)) {
				e6a2_var++;
			} else {
				e6a2_var--;
			}
		} else {
			if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7)) {
				e6a2_var--;
			} else {
				e6a2_var++;
			}

		}
		EXTI_ClearITPendingBit(EXTI_Line6);
	}
}

void EXTI15_10_IRQHandler(void) {

}
