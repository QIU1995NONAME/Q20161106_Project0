#include "flash.h"
#include "spi.h"
#include "memory.h"

namespace QIU {
namespace PJ0 {

#define FLASH_CMD_EN25X_WriteStatusReg ((uint8_t)(0x01)) // 写状态寄存器
#define FLASH_CMD_EN25X_PageProgram    ((uint8_t)(0x02)) // 页编辑
#define FLASH_CMD_EN25X_ReadData       ((uint8_t)(0x03)) // 读数据
#define FLASH_CMD_EN25X_WriteDisable   ((uint8_t)(0x04)) // 写失能
#define FLASH_CMD_EN25X_ReadStatusReg  ((uint8_t)(0x05)) // 读取状态寄存器
#define FLASH_CMD_EN25X_WriteEnable    ((uint8_t)(0x06)) // 写使能
#define FLASH_CMD_EN25X_SectorErase    ((uint8_t)(0x20)) // 擦除块
#define FLASH_CMD_EN25X_ChipErase      ((uint8_t)(0xC7)) // 擦除片

// 检查Flash是否忙碌 0为空闲 1为忙碌
inline s8 flash_is_busy() {
	// 查看busy位是否清空
	for (s32 i = 0; i < 0x40000000; i++) {
		spi_2_cs_flash();
		spi_2_transfer(FLASH_CMD_EN25X_ReadStatusReg);
		if ((spi_2_transfer(0xFF) & 0x01) != 0x01) {
			spi_2_cs_none();
			spi_2_transfer(0xFF);
			return 0;
		}
		spi_2_cs_none();
		spi_2_transfer(0xFF);
	}
	return 1;
}
// Flash 使能写入功能
inline void flash_enable_write(void) {
	spi_2_cs_flash();
	spi_2_transfer(FLASH_CMD_EN25X_WriteEnable);
	spi_2_cs_none();
	spi_2_transfer(0xFF);
}
// Flash 失能写入功能
inline void flash_disable_write(void) {
	spi_2_cs_flash();
	spi_2_transfer(FLASH_CMD_EN25X_WriteDisable);
	spi_2_cs_none();
	spi_2_transfer(0xFF);
}
// 获取Flash ID
inline u16 flash_get_id(void) {
	u16 result = 0;
	spi_2_cs_flash();
	spi_2_transfer(0x90); // 读取ID的命令
	spi_2_transfer(0x00);
	spi_2_transfer(0x00);
	spi_2_transfer(0x00);
	result |= spi_2_transfer(0xFF) << 8;
	result |= spi_2_transfer(0xFF);
	spi_2_cs_none();
	spi_2_transfer(0xFF);
	return result;

}
// 擦除整个Flash 0为成功
extern s8 flash_erase_chip(void) {
	if (flash_is_busy()) {
		return -1;
	}
	flash_enable_write();
	spi_2_cs_flash();
	spi_2_transfer(FLASH_CMD_EN25X_ChipErase);
	spi_2_cs_none();
	spi_2_transfer(0xFF);
	flash_disable_write();
	return 0;
}
// 擦除一个扇区
extern s8 flash_erase_sector(u32 sector) {
	if (flash_is_busy()) {
		return -1;
	}
	flash_enable_write();
	spi_2_cs_flash();
	spi_2_transfer(FLASH_CMD_EN25X_SectorErase);
	spi_2_transfer(0xFF & (sector >> 16));
	spi_2_transfer(0xFF & (sector >> 8));
	spi_2_transfer(0xFF & sector);
	spi_2_cs_none();
	spi_2_transfer(0xFF);
	flash_disable_write();
	return 0;
}
// 读取数据 0为成功 否则为失败
extern s8 flash_read(u32 offset, u32 length, u8* buf) {
	if (flash_is_busy()) {
		return -1;
	}
	flash_enable_write();
	spi_2_cs_flash();
	//
	spi_2_transfer(FLASH_CMD_EN25X_ReadData);
	spi_2_transfer(0xFF & (offset >> 16));
	spi_2_transfer(0xFF & (offset >> 8));
	spi_2_transfer(0xFF & offset);
	while (length--) {
		*buf++ = spi_2_transfer(0xFF);
	}
	//
	spi_2_cs_none();
	spi_2_transfer(0xFF);
	flash_disable_write();
	return 0;
}
// 向空的 Flash 扇区中写入数据
// 0 为成功 否则为失败
inline s8 flash_write_sector(u32 offset, u16 len, const u8* buf) {
	// 写入Flash是以页(Page 256B)为单位的
	// 本次要写入的字节数
	// 如果地址不是对齐256字节的 则先要把开头的，不对齐的部分先写入
	u16 num_to_write = offset % 256;
	num_to_write = 256 - num_to_write;
	// 如果即将写入的数据不足以填满本页，则一次性写入
	num_to_write = num_to_write > len ? len : num_to_write;
	// 写入程序开始
	while (1) {
		if (flash_is_busy()) {
			return 1;
		}
		flash_enable_write();
		spi_2_cs_flash();
		//
		spi_2_transfer(FLASH_CMD_EN25X_PageProgram);
		spi_2_transfer(offset >> 16);
		spi_2_transfer(offset >> 8);
		spi_2_transfer(offset);
		for (u16 i = 0; i < num_to_write; i++) {
			spi_2_transfer(*buf++);
		}
		//
		spi_2_cs_none();
		spi_2_transfer(0xFF);
		flash_disable_write();
		// 判断是否写完
		if (num_to_write == len) {
			break;	//写入成功
		}
		// 如果还没有写完
		// 接下来要写的数据位置
		offset += num_to_write;
		// 还没有写入的数据长度
		len -= num_to_write;
		// 如果剩余部分比一页(256B)多，则先写一页，否则全写完
		num_to_write = len >= 256 ? 256 : len;
		// 进入下一轮写入操作
	}		// END WHILE(1)
	return 0;
}
// 写入数据 0为成功 1为失败
// FIXME 没有进行写入失败等处理
extern s8 flash_write(u32 offset, u32 len, const u8* buf) {
	// 由于Flash 一次擦除的单位是4KB 所以创建一个4K缓冲
	u8 * buffer_4k = (u8 *) memory_alloc_4k();
	// 扇区地址
	u16 sector = offset >> 12;
	// 扇区内的字节地址
	u16 byte_addr = offset & 4095;
	// 本扇区还可以写入的字节数
	u16 num_to_write = 4096 - byte_addr;
	// 如果真正要写入的字节数比本扇区内的数量少，则直接全写完
	num_to_write = num_to_write > len ? len : num_to_write;
	// 循环变量
	u16 i = 0;
	while (1) {
		// 先读取一个扇区
		flash_read(sector << 12, 4096, buffer_4k);
		// 检测这个扇区中是否有数据
		for (i = 0; i < num_to_write; i++) {
			if (*(buffer_4k + byte_addr + i) != 0xFF) {
				// 要写入的部分已经有数据了
				break;
			}
		}
		// 如果这两个值不相同说明上面的循环走到了break
		// 即 已经有数据了
		if (i < num_to_write) {
			// 擦除扇区
			flash_erase_sector(sector << 12);
			// 复制数据到4K缓冲
			for (i = 0; i < num_to_write; i++) {
				*(buffer_4k + byte_addr + i) = *(buf + i);
			}
			// 将4K数据直接写入
			flash_write_sector(sector << 12, 4096, buffer_4k);
		} else {
			flash_write_sector(offset, num_to_write, buf);
		}
		// 这两个值相同，说明写入完成
		if (num_to_write == len) {
			break;
		}
		// 进行到这里，说明写入并没有完成
		buf += num_to_write; // 需要写入的数据又写完了一些
		offset += num_to_write; // 写入的地址需要相应向后移动
		len -= num_to_write; // 需要写入数据的长度相应缩短
		sector++; // 向前移动一个扇区
		byte_addr = 0; // 不论刚刚发生了什么，接下来写入数据一定是扇区对齐的
		// 如果剩余的数量超过4K,则下一循环先写入4K
		num_to_write = len > 4096 ? 4096 : len;
	}
	// 这句话无论如何都要执行到
	memory_free(buffer_4k);
	return 0;
}
// 启动时需要读取一次ID
extern u16 flash_init(void) {
	return flash_get_id();
}

}
}


