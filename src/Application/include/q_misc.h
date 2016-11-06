#ifndef __Q_MISC_H__
#define __Q_MISC_H__

#include "stm32f10x.h"

namespace QIU {
namespace PJ0 {
/**
 * 这个文件里面是一些杂项
 * 一些不知道放在哪里的功能就放在这里了
 */
const u8 MSG_BYTE_ENDC = 0x25; // 消息结束
const u8 MSG_BYTE_ESCC = 0x99; // 消息转义码
const u8 MSG_BYTE_STTC = 0x92; // 消息开始
/**
 * 计算某段消息的CRC码
 * @param ptr 消息开始指针
 * @param len 消息长度
 * @return 消息的crc码
 */
extern u16 misc_calculate_crc(const u8* ptr, u16 len);
/**
 * 将某一段消息封包
 * 由于传入参数的类型 长度不可以超过255 如果以后这段程序升级，需要考虑判断消息的长度上限
 * @param result 结果指针
 * @param len 准备封包的消息长度
 * @param msg 消息指针
 * @return 封包之后的消息长度
 *         如果返回值为0 说明封包失败
 */
extern u16 misc_pack_message(u8* const result, u8 len, const u8* const msg);
/**
 * 将某一段消息解包
 * 由于传入参数的类型 长度不可以超过255 如果以后这段程序升级，需要考虑判断消息的长度上限
 * @param result 结果指针
 * @param len 准备解包的消息长度
 * @param msg 指向待解包的消息指针
 * @return 解包之后的消息长度
 *         如果返回0 说明解包失败
 *
 */
extern u16 misc_unpack_message(u8* const result, u8 len, const u8* const pack);

// 一个小工具 把24位的颜色码转换成16位
// R8 G8 B8 -> R5 G6 B5
inline u16 misc_color24to16(u8 red, u8 green, u8 blue) {
	return ((((((u32) red >> 3) << 8) | (u32) green) >> 2) << 8 | (u32) blue)
			>> 3;
}
// 整数转字符串 返回输出的字符串长度（包括最后的\0）
extern u8 misc_int2string(s8* buf, s32 num);

// 整数转字符串 返回输出的字符串长度（包括最后的\0）不省略开头的0
extern u8 misc_int2string_a(s8* buf, s32 num);
// 小数转字符串
extern u8 misc_num2string(s8* buf, double num);

}
}

#endif // __Q_MISC_H__
