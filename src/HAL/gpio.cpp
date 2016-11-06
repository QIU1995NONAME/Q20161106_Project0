#include "gpio.h"

namespace QIU {
namespace PJ0 {
// 目前已经被初始化的GPIO口
//          12    8    4    0
// GPIO_A 0000-0110 1110-0001
// GPIO_B 1111-0001 1110-0000
// GPIO_C 0000-0000 1111-1111
// GPIO_D 1111-1111 1111-0011
// GPIO_E 1111-1111 1001-1111
// GPIO_F 1111-0000 0011-1111
// GPIO_G 0111-0100 0011-1111
//
GPIO_InitTypeDef gpio_init;
// 按键
inline void gpio_config_key(void) {
	// PA0
	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
	gpio_init.GPIO_Mode = GPIO_Mode_IPD;
	gpio_init.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOA, &gpio_init);
	// PE2 PE3 PE4
	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
	gpio_init.GPIO_Mode = GPIO_Mode_IPU;
	gpio_init.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_Init(GPIOA, &gpio_init);
}
// LED 数码管
inline void gpio_config_led(void) {
	// PC7 ~ PC0
	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
	gpio_init.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_init.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3
			| GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_Init(GPIOC, &gpio_init);
}
// 蜂鸣器PWM输出
inline void gpio_config_beep_pwm(void) {
	// PB5 使用PWM驱动
	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
	gpio_init.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio_init.GPIO_Pin = GPIO_Pin_5;
	GPIO_Init(GPIOB, &gpio_init);
}
// 风扇PWM输出
inline void gpio_config_fan_pwm(void) {
	// PB8 使用PWM驱动
	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
	gpio_init.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio_init.GPIO_Pin = GPIO_Pin_8;
	GPIO_Init(GPIOB, &gpio_init);
}
// E6A2 光电编码器
inline void gpio_config_e6a2(void) {
	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
	gpio_init.GPIO_Mode = GPIO_Mode_IPU;
	gpio_init.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_Init(GPIOB, &gpio_init);
}
// 串口1
inline void gpio_config_usart1(void) {
	// 初始化 USART1使用的GPIO PA9输出(TX) PA10 输入(RX)
	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
	gpio_init.GPIO_Mode = GPIO_Mode_AF_PP; // 复用推挽输出
	gpio_init.GPIO_Pin = GPIO_Pin_9; // TX
	GPIO_Init(GPIOA, &gpio_init);
	gpio_init.GPIO_Mode = GPIO_Mode_IN_FLOATING; // 浮空输入
	gpio_init.GPIO_Pin = GPIO_Pin_10; // RX
	GPIO_Init(GPIOA, &gpio_init);
}
// 触摸屏 用来检测是否触摸的信号线
inline void gpio_config_touch_pen(void) {
	// TOUCH_PEN PD7
	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
	gpio_init.GPIO_Mode = GPIO_Mode_IPU; // 上拉输入
	gpio_init.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOD, &gpio_init);
}
// SPI 1 2 总线初始化
inline void gpio_config_spi(void) {
	// SPI1 PA5 PA6 PA7
	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
	gpio_init.GPIO_Mode = GPIO_Mode_AF_PP; // 复用推挽输出
	gpio_init.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_Init(GPIOA, &gpio_init);
	GPIO_SetBits(GPIOA, GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7);
	// SPI2 PB13 PB14 PB15
	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
	gpio_init.GPIO_Mode = GPIO_Mode_AF_PP; // 复用推挽输出
	gpio_init.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_Init(GPIOB, &gpio_init);
	// 使用SPI1的模块信号线
	// TOUCH_CS    PD6
	gpio_init.GPIO_Mode = GPIO_Mode_Out_PP; // 推挽输出
	gpio_init.GPIO_Pin = GPIO_Pin_6;
	GPIO_Init(GPIOD, &gpio_init);
	GPIO_SetBits(GPIOD, GPIO_Pin_6);
	// 使用SPI2的模块信号线
	// SD_CS       PG14
	// FLASH_CS    PG13
	gpio_init.GPIO_Mode = GPIO_Mode_Out_PP; // 推挽输出
	gpio_init.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_13;
	GPIO_Init(GPIOG, &gpio_init);
	GPIO_SetBits(GPIOG, GPIO_Pin_13);
	GPIO_SetBits(GPIOG, GPIO_Pin_14);
	// ENC28J60_CS PB12
	gpio_init.GPIO_Pin = GPIO_Pin_12;
	GPIO_Init(GPIOB, &gpio_init);
	GPIO_SetBits(GPIOB, GPIO_Pin_12);

}
// FSMC模块
inline void gpio_config_fsmc(void) {
	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
	gpio_init.GPIO_Mode = GPIO_Mode_AF_PP;
	// PD0   FSMC_D2
	// PD1   FSMC_D3
	// PD4   FSMC_NOE
	// PD5   FSMC_NWE
	// PD8   FSMC_D13
	// PD9   FSMC_D14
	// PD10  FSMC_D15
	// PD11  FSMC_A16
	// PD12  FSMC_A17
	// PD13  FSMC_A18
	// PD14  FSMC_D0
	// PD15  FSMC_D1
	gpio_init.GPIO_Pin = GPIO_Pin_All
			& ~(GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_6 | GPIO_Pin_7);
	GPIO_Init(GPIOD, &gpio_init);
	// PE0   FSMC_NBL0
	// PE1   FSMC_NBL1
	// PE7   FSMC_D4
	// PE8   FSMC_D5
	// PE9   FSMC_D6
	// PE10  FSMC_D7
	// PE11  FSMC_D8
	// PE12  FSMC_D9
	// PE13  FSMC_D10
	// PE14  FSMC_D11
	// PE15  FSMC_D12
	gpio_init.GPIO_Pin = GPIO_Pin_All & ~( GPIO_Pin_2 | GPIO_Pin_3)
			& ~(GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6);
	GPIO_Init(GPIOE, &gpio_init);
	// PF0   FSMC_A0
	// PF1   FSMC_A1
	// PF2   FSMC_A2
	// PF3   FSMC_A3
	// PF4   FSMC_A4
	// PF5   FSMC_A5
	// PF12  FSMC_A6
	// PF13  FSMC_A7
	// PF14  FSMC_A8
	// PF15  FSMC_A9
	gpio_init.GPIO_Pin = GPIO_Pin_All & ~( GPIO_Pin_6 | GPIO_Pin_7)
			& ~(GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11);

	GPIO_Init(GPIOF, &gpio_init);
	// PG0   FSMC_A10
	// PG1   FSMC_A11
	// PG2   FSMC_A12
	// PG3   FSMC_A13
	// PG4   FSMC_A14
	// PG5   FSMC_A15
	// PG10  FSMC_NE3
	// PG12  FSMC_NE4
	gpio_init.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3
			| GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_10 | GPIO_Pin_12;
	GPIO_Init(GPIOG, &gpio_init);
}
// 初始化
extern void gpio_config(void) {
	// GPIO 时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);

	//各项外设GPIO初始化
	gpio_config_key();
	gpio_config_led();
	gpio_config_beep_pwm();
	gpio_config_fan_pwm();
	gpio_config_usart1();
	gpio_config_touch_pen();
	gpio_config_spi();
	gpio_config_fsmc();
	gpio_config_e6a2();
}

}
}
