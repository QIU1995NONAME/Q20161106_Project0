#ifndef __USART_H__
#define __USART_H__

#include "stm32f10x.h"
#include "systick.h"

namespace QIU {
namespace PJ0 {
/**
 * 串口配置
 */
extern void usart_config(void);

inline void usart_1_send(u8 dat) {
	USART_SendData(USART1, dat);
	delay_us(500);
//	s32 retry = 0x10000000;
//	while (retry && USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET){
//		retry --;
//		// DO NOTHING 等待发送完成
//	}
}
//inline void usart_1_ready_to_send(void){
//	s32 retry = 0x10000000;
//	while(retry && USART_GetFlagStatus(USART1, USART_FLAG_TXE)){
//		retry --;
//	}
//}
}
}

#endif // __USART_H__
