#ifndef __Q_MISC_H__
#define __Q_MISC_H__

#include "stm32f10x.h"

namespace QIU {
namespace PJ0 {
/**
 * 这个文件里面是一些杂项
 * 一些不知道放在哪里的功能就放在这里了
 */
typedef struct MISC_TIME_STRUCT {
	u8 time_second;
	u8 time_minute;
	u8 time_hour;
	u8 time_date;
	u8 time_month;
	u16 time_year;
} TimeType;
/**
 * 计算某段消息的CRC码
 * @param ptr 消息开始指针
 * @param len 消息长度
 * @return 消息的crc码
 */
extern u16 misc_calculate_crc(const u8* ptr, u16 len);
/**
 * 把24位的颜色码转换成16位
 * R8 G8 B8 -> R5 G6 B5
 */
inline u16 misc_color24to16(u8 red, u8 green, u8 blue) {
	return ((((((u32) red >> 3) << 8) | (u32) green) >> 2) << 8 | (u32) blue)
			>> 3;
}
/**
 * 整数转字符串
 * @return 输出的字符串长度（包括最后的\0）
 */
extern u8 misc_int2string(s8* buf, s32 num);

/**
 * 整数转字符串
 * @return 输出的字符串长度（包括最后的\0）不省略开头的0
 */
extern u8 misc_int2string_a(s8* buf, s32 num);
/**
 * 小数转字符串
 * @return 输出的字符串长度（包括最后的\0）
 */
extern u8 misc_num2string(s8* buf, double num);
/**
 * 时间戳转换成时间结构
 */
extern s8 misc_uint2timetype(TimeType* result, u32 timestamp);
/**
 * 时间戳转换成可读的时间字符串
 * 缓冲区至少20字节！
 * @return 大于0 表示成功 真正占用的缓冲区数量
 */
extern s8 misc_uint2timestring(s8* buf, u32 timestamp);
/**
 * 将时间戳转换成FAT适配的32位时间标记
 */
extern s8 misc_uint2fattime(u32* result, u32 timestamp);
}
}

#endif // __Q_MISC_H__
