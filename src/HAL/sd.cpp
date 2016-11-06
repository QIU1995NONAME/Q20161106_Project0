#include "sd.h"
#include "spi.h"
#include "systick.h"

#define SD_CMD_00 (0x00)      //命令00  卡复位
#define SD_CMD_01 (0x01)      //TODO 未知
#define SD_CMD_08 (0x08)      //命令08，SEND_IF_COND
#define SD_CMD_09 (0x09)      //命令09，读CSD数据
#define SD_CMD_10 (0x0A)      //命令10，读CID数据
#define SD_CMD_12 (0x0C)      //命令12，停止数据传输
#define SD_CMD_16 (0x10)      //命令16，设置SectorSize 应返回0x00
#define SD_CMD_17 (0x11)      //命令17，读sector
#define SD_CMD_18 (0x12)      //命令18，读Multi sector
#define SD_CMD_23 (0x17)      //命令23，设置多sector写入前预先擦除N个block
#define SD_CMD_24 (0x18)      //命令24，写sector
#define SD_CMD_25 (0x19)      //命令25，写Multi sector
#define SD_CMD_41 (0x29)      //命令41，应返回0x00
#define SD_CMD_55 (0x37)      //命令55，应返回0x01
#define SD_CMD_58 (0x3A)      //命令58，读OCR信息
#define SD_CMD_59 (0x3B)      //命令59，使能/禁止CRC，应返回0x00

namespace QIU {
namespace PJ0 {

// 存放 CSD 寄存器数据的缓冲区
u8 SD_CSD[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// SD卡是否可用
s8 sd_available = 0;

// 用来保存SD卡的型号信息
u8 sd_type = SD_TYPE_NONE;

// 向SD写命令
s8 sd_write_command(u8 cmd, u32 arg, u8 crc) {
	s8 result = -1;
	u8 r_cmd = cmd;
	s8 retry = 100;
	// FIXME 暂定的数据预处理方法
	r_cmd &= 0x7F; // cmd 最高位 置0
	r_cmd |= 0x40; // cmd 次高位 置1
	crc |= 0x01; // crc 最低位 置1
	spi_2_cs_none(); // 取消SPI2片选
	spi_2_transfer(0xFF); // 等待8个时钟
	spi_2_cs_sd(); // 选中SD
	while (spi_2_transfer(0xFF) != 0xFF) { // FIXME 这里有可能出现问题
		if (retry < 0) {
			spi_2_cs_none();
			return -1; //失败
		}
		retry--;
	}
	// 开始发送
	spi_2_transfer(r_cmd);
	spi_2_transfer(0x00FF & (arg >> 24));
	spi_2_transfer(0x00FF & (arg >> 16));
	spi_2_transfer(0x00FF & (arg >> 8));
	spi_2_transfer(0x00FF & arg);
	spi_2_transfer(crc);
	// 如果是停止数据命令 则多发送一个时钟
	if (cmd == SD_CMD_12) {
		spi_2_transfer(0xFF);
	}
	retry = 100;
	while ((result = spi_2_transfer(0xFF)) < 0) {
		if (retry < 0) {
			spi_2_cs_none();
			return -1; //失败
		}
		retry--;
	}
	// 不取消片选
	return result; // 成功
}
// 刷新SD卡CSD信息 0表示成功 否则为失败
s8 sd_refresh_csd(void) {
	s8 retry = 100;
	// 如果SD卡不可用，直接放弃操作
	if (!sd_available) {
		return -1;
	}
	while (sd_write_command(SD_CMD_09, 0x00, 0x01) != 0x00) {
		retry--;
		if (retry < 0) {
			return -1;
		}
	}
	retry = 100;
	// 等待起始应答 0xFE
	while (spi_2_transfer(0xFF) != 0xFE) {
		retry--;
		if (retry < 0) {
			return -1;
		}
	}
	for (u8 i = 0; i < 16; i++) {
		*(SD_CSD + i) = spi_2_transfer(0xFF);
	}
	// FIXME 数据的CRC校验 暂不考虑
	spi_2_transfer(0xFF);
	spi_2_transfer(0xFF);

	// 取消SD卡片选
	spi_2_cs_none();
	spi_2_transfer(0xFF);

	return 0;
}
// 初始化SD
void sd_init_0(void) {
	u8 buf[4];
	s8 retry = 100;
	// 先取消片选
	spi_2_cs_none();
	// 初始化，先发送至少74个时钟
	for (u8 i = 0; i < 16; i++) {
		spi_2_transfer(0xFF);
	}
	// 发送SD RESET 当读取到0x01的时候说明初始化成功
	while (sd_write_command(SD_CMD_00, 0x00, 0x95) != 0x01) {
		retry--;
		if (retry < 0) {
			sd_available = 0;
			return;
		}
	}
	// 检测是否为SD V2.0
	retry = 100;
	while (sd_write_command(SD_CMD_08, 0x01AA, 0x87) != 0x01) {
		retry--;
		if (retry < 0) {
			break;
		}
	}
	if (retry != 0) { // SD V2.0
		for (u8 i = 0; i < 4; i++) {
			*(buf + i) = spi_2_transfer(0xFF);
		}
		// 判断电压是否支持
		if (*(buf + 2) != 0x01 || *(buf + 3) != 0xAA) {
			sd_available = 0;
			return;
		}
		//初始化SD
		retry = 100;
		while ((sd_write_command(SD_CMD_55, 0x00, 0x01), sd_write_command(
		SD_CMD_41, 0x40000000, 0x01)) != 0x00) {
			retry--;
			if (retry < 0) {
				sd_available = 0;
				return;
			}
		}
		// 检测SDHC卡还是SD卡
		retry = 100;
		while (sd_write_command(SD_CMD_58, 0x00, 0x01) != 0x00) {
			retry--;
			if (retry < 0) {
				sd_type = SD_TYPE_NONE;
				break;
			}
		}
		// 读取OCR
		for (u8 i = 0; i < 4; i++) {
			*(buf + i) = spi_2_transfer(0xFF);
		}
		if (*buf & 0x40) {
			sd_type = SD_TYPE_V2HC;
		} else {
			sd_type = SD_TYPE_V2;
		}
	} else { // SD V1.0 或者 MMC
		retry = 100;
		sd_write_command(SD_CMD_55, 0x00, 0x01);
		*buf = sd_write_command(SD_CMD_41, 0x00, 0x01);
		if (*buf <= 0x01) { // SD V1.0
			sd_type = SD_TYPE_V1;
			while ((sd_write_command(SD_CMD_55, 0x00, 0x01), sd_write_command(
			SD_CMD_41, 0x00, 0x01)) != 0x00) {
				retry--;
				if (retry < 0) {
					sd_available = 0;
					return;
				}
			}
		} else { //MMC V3
			sd_type = SD_TYPE_MMC;
			while (sd_write_command(SD_CMD_01, 0x00, 0x01) != 0x00) {
				retry--;
				if (retry < 0) {
					sd_available = 0;
					return;
				}
			}
		}
	}
	// 取消片选
	spi_2_cs_none();
	sd_available = 1;
	if (sd_refresh_csd() != 0) {
		sd_available = 0;
	}
	return;
}
// ========================================
//
// EXTERN FUNCTIONS
//
// ========================================

// 获取当前SD卡是否可用 0为不可用，1为可用
extern s8 sd_is_available(void) {
	return sd_available;
}
// 初始化SD
extern void sd_init(void) {
	sd_init_0();
}
// 获取SD卡大小 如果返回值为负，则说明获取失败
extern s32 sd_get_capacity(void) {
	s32 result = 0;
	// 不可用
	if (!sd_available) {
		return -1;
	}
	if ((*SD_CSD & 0xC0) == 0x40) { // SD V2.0
		result = *(SD_CSD + 9) + ((u16) (*(SD_CSD + 8)) << 8) + 1; // 计算C_SIZE 在CSD[69:48]
		result <<= 10; // 再乘以1024(左移10位)即可获得扇区数。
	} else { // SD V1.0
		// 结果应该为 BLOCKNR * BLOCK_LEN
		// BLOCKNR = (C_SIZE + 1) * MULT
		// BLOCK_LEN = (1 << READ_BL_LEN)

		// BLOCK_LEN,C_SIZE_MULT在CSD[49:47] READ_BL_LEN在CSD[83:80]
		s32 n = (SD_CSD[5] & 0x0A) + ((SD_CSD[10] & 0x80) >> 7)
				+ ((SD_CSD[9] & 0x03) << 1) + 2;
		// C_SIZE在CSD[73:62]
		result = (SD_CSD[8] >> 6) + ((uint16_t) SD_CSD[7] << 2)
				+ ((uint16_t) (SD_CSD[6] & 3) << 10) + 1;
		result <<= (n - 9);	//得到扇区数
	}
	return result;
}
// 读取扇区数据的核心部分程序
s8 sd_read_sector_data(u8* buf) {
	s16 retry = 10000;
	while (spi_2_transfer(0xFF) != 0xFE) {
		retry--;
		if (retry < 0) {
			return -1;
		}
	}
	for (u16 i = 0; i < 512; i++) {
		*buf++ = spi_2_transfer(0xFF);
	}
	// 忽略CRC 但是时序还是要走的
	spi_2_transfer(0xFF);
	spi_2_transfer(0xFF);
	return 0;
}
// 写入扇区数据的核心部分程序
s8 sd_write_sector_data(const u8* buf, u8 cmd) {
	s16 retry = 10000;
	// 等待SD卡准备好
	while (spi_2_transfer(0xFF) != 0xFF) {
		retry--;
		if (retry < 0) {
			return -1;
		}
	}
	// 发送命令
	spi_2_transfer(cmd);
	// 发送数据
	for (u16 i = 0; i < 512; i++) {
		spi_2_transfer(*buf++);
	}
	// 忽略CRC 但是时序还是要走的
	spi_2_transfer(0xFF);
	spi_2_transfer(0xFF);
	// 读取返回值
	retry = spi_2_transfer(0xFF);
	// 如果写入失败
	if ((retry & 0x1F) != 0x05) {
		spi_2_cs_none();
		spi_2_transfer(0xFF);
		return -1;
	}
	return 0;
}
// SD卡读取扇区 返回值 0为成功 否则为失败
extern s8 sd_read_sector(u8* buf, u32 sector, u32 num) {
	if (!sd_available) {
		return -1;
	}
	if (sd_type != SD_TYPE_V2HC) {
		sector <<= 9;	//转换为字节地址
	}
	s16 retry = 10000;
	if (num == 1) {	// 仅操作一个扇区
		while (sd_write_command(SD_CMD_17, sector, 0x01) != 0x00) {
			retry--;
			if (retry < 0) {
				return -1;
			}
		}
		// 开始接收
		if (sd_read_sector_data(buf) != 0) {
			return -1;
		}
	} else {	// 操作多个扇区
		while (sd_write_command(SD_CMD_18, sector, 0x01) != 0x00) {
			retry--;
			if (retry < 0) {
				return -1;
			}
		}
		// 开始接收
		while (num--) {
			if (sd_read_sector_data(buf) != 0) {
				return -1;
			}
			buf += 512;
		}
		sd_write_command(SD_CMD_12, 0, 0x01); //发送停止信号
	}
	// 取消片选
	spi_2_cs_none();
	spi_2_transfer(0xFF);
	return 0;
}
// SD卡写入扇区 返回值 0为成功 否则为失败
extern s8 sd_write_sector(const u8* buf, u32 sector, u32 num) {
	if (!sd_available) {
		return -1;
	}
	if (sd_type != SD_TYPE_V2HC) {
		sector <<= 9;	//转换为字节地址
	}
	s16 retry = 10000;
	if (num == 1) {	// 仅操作一个扇区
		while (sd_write_command(SD_CMD_24, sector, 0x01) != 0x00) {
			retry--;
			if (retry < 0) {
				return -1;
			}
		}
		if (sd_write_sector_data(buf, 0xFE) != 0) {
			return -1;
		}
	} else {	// 操作多个扇区
		if (sd_type == SD_TYPE_MMC) {	//如果是MMC卡，需要先擦除num个扇区中的数据
			sd_write_command(SD_CMD_55, 0x00, 0x01);
			sd_write_command(SD_CMD_23, num, 0x01);
		}

		while (sd_write_command(SD_CMD_25, sector, 0x01) != 0x00) {
			retry--;
			if (retry < 0) {
				return -1;
			}
		}
		// 开始接收
		while (num--) {
			if (sd_write_sector_data(buf, 0xFC) != 0x00) {
				return -1;
			}
			buf += 512;
		}
		retry = 10000;
		// 等待SD卡准备好
		while (spi_2_transfer(0xFF) != 0xFF) {
			retry--;
			if (retry < 0) {
				return -1;
			}
		}
		spi_2_transfer(0xFD);
	}
	// 取消片选
	spi_2_cs_none();
	spi_2_transfer(0xFF);
	return 0;
}
}
}
