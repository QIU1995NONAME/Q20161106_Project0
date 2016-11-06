#ifndef __SD_H__
#define __SD_H__

#include "stm32f10x.h"

namespace QIU {
namespace PJ0 {
// SD卡相关操作绝对不要出现在中断中或者被中断调用！

#define SD_TYPE_NONE ((u8)0x00)
#define SD_TYPE_MMC  ((u8)0x01)
#define SD_TYPE_V1   ((u8)0x02)
#define SD_TYPE_V2   ((u8)0x04)
#define SD_TYPE_V2HC ((u8)0x06)

// 获取当前SD卡是否可用 0为不可用，1为可用
extern s8 sd_is_available(void);
// 初始化SD
extern void sd_init(void);
// 获取SD卡大小 如果返回值为负，则说明获取失败
extern s32 sd_get_capacity(void);
// SD卡读取扇区 返回值 0为成功 否则为失败
extern s8 sd_read_sector(u8* buf, u32 sector, u32 num);
// SD卡写入扇区 返回值 0为成功 否则为失败
extern s8 sd_write_sector(const u8* buf, u32 sector, u32 num);

}
}

#endif // __SD_H__
