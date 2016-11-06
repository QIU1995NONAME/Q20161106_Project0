#include "stm32f10x.h"
#include "stm32f10x_it.h"

#include "q_misc.h"
using namespace QIU::PJ0;

void USART1_IRQHandler(void) {
	// FIXME 这个中断函数只是实验用
	static u8 k;
	USART_ClearFlag(USART1, USART_FLAG_TC);
	if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
		k = USART_ReceiveData(USART1);
		USART_SendData(USART1,k);
		while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);//等待发送完毕
	}
}

void USART2_IRQHandler(void) {

}

void USART3_IRQHandler(void) {

}

void UART4_IRQHandler(void) {

}

void UART5_IRQHandler(void) {

}
