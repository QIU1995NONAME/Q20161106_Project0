#include "usart.h"

namespace QIU {
namespace PJ0 {
//
USART_InitTypeDef usart_init;
//
inline void usart_config_1(void) {
	usart_init.USART_BaudRate = 57600; // 波特率57600
	usart_init.USART_WordLength = USART_WordLength_8b; // 字长8bit
	usart_init.USART_StopBits = USART_StopBits_1; // 停止位1bit
	usart_init.USART_Parity = USART_Parity_No; // 无校验
	usart_init.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; // 开启发送接收
	usart_init.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // 失能硬件流
	USART_Init(USART1, &usart_init); // 初始化
	USART_Cmd(USART1, ENABLE); // 使能USART1
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); // 启动接收中断
	USART_ClearFlag(USART1, USART_FLAG_TC); // 清除标志位
}
//
inline void usart_config_2(void) {

}
//
inline void usart_config_3(void) {

}
//
inline void uart_config_4(void) {

}
//
inline void uart_config_5(void) {

}
//串口初始化设置
extern void usart_config(void) {
	// 串口时钟初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, DISABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, DISABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, DISABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, DISABLE);
	// 各个串口初始化
	usart_config_1();
	usart_config_2();
	usart_config_3();
	uart_config_4();
	uart_config_5();

}

}
}
