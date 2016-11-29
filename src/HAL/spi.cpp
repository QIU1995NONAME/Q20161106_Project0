#include "spi.h"
#include "systick.h"
namespace QIU {
namespace PJ0 {
//
SPI_InitTypeDef spi_init;
//
inline void spi_config_1(void) {
	// 全双工SPI
	spi_init.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	// 单片机是主机
	spi_init.SPI_Mode = SPI_Mode_Master;
	// 8位数据
	spi_init.SPI_DataSize = SPI_DataSize_8b;
	// 时钟悬空高电平
	spi_init.SPI_CPOL = SPI_CPOL_High;
	// 在第二个时钟采集数据
	spi_init.SPI_CPHA = SPI_CPHA_2Edge;
	// NSS 使用软件控制
	spi_init.SPI_NSS = SPI_NSS_Soft;
	// 16时钟分频
	spi_init.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
	// 从最高位开始传输
	spi_init.SPI_FirstBit = SPI_FirstBit_MSB;
	// ?
	spi_init.SPI_CRCPolynomial = 7;
	// 使能SPI1
	SPI_Cmd(SPI1, ENABLE);
	// 初始化
	SPI_Init(SPI1, &spi_init);

}
//
inline void spi_config_2(void) {
	// 全双工SPI
	spi_init.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	// 单片机是主机
	spi_init.SPI_Mode = SPI_Mode_Master;
	// 8位数据
	spi_init.SPI_DataSize = SPI_DataSize_8b;
	// 时钟悬空高电平
	spi_init.SPI_CPOL = SPI_CPOL_Low;
	// 在第二个时钟采集数据
	spi_init.SPI_CPHA = SPI_CPHA_1Edge;
	// NSS 使用软件控制
	spi_init.SPI_NSS = SPI_NSS_Soft;
	// 256时钟分频
	spi_init.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;
	// 从最高位开始传输
	spi_init.SPI_FirstBit = SPI_FirstBit_MSB;
	// ?
	spi_init.SPI_CRCPolynomial = 7;
	// 使能SPI1
	SPI_Cmd(SPI2, ENABLE);
	// 初始化
	SPI_Init(SPI2, &spi_init);

}
//
inline void spi_config_3(void) {
	//unused
}
// 初始化
extern void spi_config(void) {
	// 启动时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI3, DISABLE);
	// 逐个初始化
	spi_config_1();
	spi_config_2();
	spi_config_3();
}
// 数据转移
extern s16 spi_1_transfer(u8 dat) {
	// 等待时间
	s16 retry = 1000;
	// 等待发送缓冲器清空
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET) {
		delay_us(10);
		retry--;
		if (retry < 0) {
			return 0xF0FF; // FIXME 暂定：发送错误
		}
	}
	// 发送数据
	SPI_I2S_SendData(SPI1, dat);
	retry = 1000;
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET) {
		delay_us(10);
		retry--;
		if (retry < 0) {
			return 0xFFFF; // FIXME 暂定，接收错误
		}
	}
	return SPI_I2S_ReceiveData(SPI1);
}
// 数据转移
extern s16 spi_2_transfer(u8 dat) {
	// 等待时间
	s16 retry = 1000;
	// 等待发送缓冲器清空
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET) {
		delay_us(10);
		retry--;
		if (retry < 0) {
			return 0xF0FF; // FIXME 暂定：发送错误
		}
	}
	// 发送数据
	SPI_I2S_SendData(SPI2, dat);
	retry = 1000;
	while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET) {
		delay_us(10);
		retry--;
		if (retry < 0) {
			return 0xFFFF; // FIXME 暂定，接收错误
		}
	}
	return SPI_I2S_ReceiveData(SPI2);
}

}
}

