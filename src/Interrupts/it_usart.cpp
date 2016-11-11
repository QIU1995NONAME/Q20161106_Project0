#include "stm32f10x.h"
#include "stm32f10x_it.h"

#include "q_misc.h"
#include "cmd_private.h"

using namespace QIU::PJ0;

void USART1_IRQHandler(void) {
	static s8 data;
	USART_ClearFlag(USART1, USART_FLAG_TC);
	if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
		// ****************************
		data = USART_ReceiveData(USART1);
		// 缓冲区是否已满
		if(cmd_buffer_is_full()){
			// 放弃数据
			// DO NOTHING
		}else{
			// 如果缓冲区还有地方，就把数据写进去
			cmd_buffer_add_last(data);
		}
		// ****************************
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
