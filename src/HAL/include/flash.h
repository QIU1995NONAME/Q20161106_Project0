#ifndef __FLASH_H__
#define __FLASH_H__

#include "stm32f10x.h"

namespace QIU {
namespace PJ0 {

#define FLASH_TYPE_EN25Q80 ((uint16_t)(0x1C13))
#define FLASH_TYPE_EN25Q16 ((uint16_t)(0x1C14))
#define FLASH_TYPE_EN25Q32 ((uint16_t)(0x1C15))
// #define FLASH_TYPE_EN25Q64 ((uint16_t)(0x1C16))
#define FLASH_TYPE_EN25Q64 ((uint16_t)(0xC816))

/**
 * 擦除整个Flash
 * @return 0 成功
 */
extern s8 flash_erase_chip(void);
/**
 * 擦除一个扇区
 * @return 0 成功
 */
extern s8 flash_erase_sector(u32 sector);
/**
 * 读取数据
 * @return 0 成功
 */
extern s8 flash_read(u32 offset, u32 length, u8* buf);
/**
 * 写入数据
 * @return 0 成功
 */
extern s8 flash_write(u32 offset, u32 len, const u8* buf);
/**
 * 启动时需要读取一次ID
 * @return ID
 */
extern u16 flash_init(void);

}
}

#endif // __FLASH_H__
