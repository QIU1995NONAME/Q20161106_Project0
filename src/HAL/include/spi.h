#ifndef __SPI_H__
#define __SPI_H__

#include "stm32f10x.h"

namespace QIU {
namespace PJ0 {

// 初始化
extern void spi_config(void);

// 数据转移 从SPI收到的数据是8位，如果返回的数据超过8位
// 说明有错误产生
extern s16 spi_1_transfer(u8 dat);

// 数据转移 从SPI收到的数据是8位，如果返回的数据超过8位
// 说明有错误产生
extern s16 spi_2_transfer(u8 dat);
////////////////////////////////////////////////////
// SPI1片选信号 不选中
inline void spi_1_cs_none() {
	GPIO_SetBits(GPIOD, GPIO_Pin_6); //触摸屏
}
// SPI1 片选信号 触摸屏
inline void spi_1_cs_touch() {
	spi_1_cs_none();
	GPIO_ResetBits(GPIOD, GPIO_Pin_6); //触摸屏
}
//
////////////////////////////////////////////////////
// SPI2片选信号 不选中
inline void spi_2_cs_none(void) {
	GPIO_SetBits(GPIOB, GPIO_Pin_12); // ENC28J60
	GPIO_SetBits(GPIOG, GPIO_Pin_13); // FLASH
	GPIO_SetBits(GPIOG, GPIO_Pin_14); // SD
}
// SPI2片选信号 选中网络模块
inline void spi_2_cs_enc28j60(void) {
	spi_2_cs_none();
	GPIO_ResetBits(GPIOB, GPIO_Pin_12); // ENC28J60
}
// SPI2片选信号 选中FLASH模块
inline void spi_2_cs_flash(void) {
	spi_2_cs_none();
	GPIO_ResetBits(GPIOG, GPIO_Pin_13); // FLASH
}
// SPI2片选信号 选中SD卡
inline void spi_2_cs_sd(void) {
	spi_2_cs_none();
	GPIO_ResetBits(GPIOG, GPIO_Pin_14); // SD
}

}
}

#endif // __SPI_H__
