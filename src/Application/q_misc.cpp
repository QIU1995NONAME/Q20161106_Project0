#include "q_misc.h"

#define __USE_MEMORY_BUFFER__

#ifdef __USE_MEMORY_BUFFER__
#include "memory.h"
#endif //__USE_MEMORY_BUFFER__

namespace QIU {
namespace PJ0 {

const u8 CRCHTable[256] = { 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
		0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
		0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
		0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
		0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
		0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
		0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
		0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
		0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
		0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
		0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
		0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
		0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
		0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
		0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
		0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
		0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
		0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
		0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
		0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
		0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
		0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40 };
const u8 CRCLTable[256] = { 0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2,
		0xC6, 0x06, 0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD,
		0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09, 0x08, 0xC8,
		0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A, 0x1E, 0xDE, 0xDF, 0x1F,
		0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4, 0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6,
		0xD2, 0x12, 0x13, 0xD3, 0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1,
		0x33, 0xF3, 0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4,
		0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A, 0x3B, 0xFB,
		0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29, 0xEB, 0x2B, 0x2A, 0xEA,
		0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED, 0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5,
		0x27, 0xE7, 0xE6, 0x26, 0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0,
		0xA0, 0x60, 0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67,
		0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F, 0x6E, 0xAE,
		0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68, 0x78, 0xB8, 0xB9, 0x79,
		0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E, 0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C,
		0xB4, 0x74, 0x75, 0xB5, 0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73,
		0xB1, 0x71, 0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92,
		0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C, 0x5D, 0x9D,
		0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B, 0x99, 0x59, 0x58, 0x98,
		0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B, 0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F,
		0x8D, 0x4D, 0x4C, 0x8C, 0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86,
		0x82, 0x42, 0x43, 0x83, 0x41, 0x81, 0x80, 0x40 };

const s32 NUM_TABLE[10] = { 1000000000, 100000000, 10000000, 1000000, 100000,
		10000, 1000, 100, 10, 1 };
extern u16 misc_calculate_crc(const u8* ptr, u16 len) {
	u8 crch = 0x00;
	u8 crcl = 0x00;
	u16 index = 0x0000;
	while (len--) {
		index = crcl ^ *ptr++;
		crcl = crch ^ *(CRCHTable + index);
		crch = *(CRCLTable + index);
	}
	return ((crch << 8) | crcl);
}
extern u16 misc_pack_message(u8* const result, u8 len, const u8* const msg) {
	// 缓冲区
#ifdef __USE_MEMORY_BUFFER__
	u8 * tmp = (u8*) memory_alloc_1k();
	if (tmp == 0) {
		return 0;
	}
#else //__USE_MEMORY_BUFFER__
	u8 tmp[512];
#endif //__USE_MEMORY_BUFFER__
	// 变量初始化
	u16 tmp_len = len + 4;
	u32 res_len = 0;
	u16 check = 0;
	// 第一个字节 代表消息长度
	*(tmp) = tmp_len;
	// 第二个字节 chksum 预留出来
	*(tmp + 1) = 0;
	// 复制消息 将msg的消息复制到tmp
	for (u8 i = 0; i < len; i++) {
		*(tmp + 2 + i) = *(msg + i);
	}
	// 最后两个字节 是CRC校验用的 预留
	*(tmp + tmp_len - 2) = 0x00;
	*(tmp + tmp_len - 1) = 0x00;
	// 进行CRC的计算
	check = misc_calculate_crc(tmp, tmp_len);
	// 将CRC填入消息 先填高8位，再填低8位
	*(tmp + tmp_len - 2) = (check >> 8) & 0xFF;
	*(tmp + tmp_len - 1) = check & 0xFF;
	// 清空check 准备进行校验和的计算
	check = 0;
	// 开始计算SUM
	for (u8 i = 0; i < tmp_len; i++) {
		check += *(tmp + i);
	}
	// SUM填入消息
	*(tmp + 1) = 0xFF - (check & 0xFF) + 1;
	// 接下来是另一组协议 需要将其中特殊意义的编码进行转码
	// 并开始写返回值 首先是消息起始码
	*(result + res_len++) = MSG_BYTE_STTC;
	// 逐字节检测消息
	for (u8 i = 0; i < tmp_len; i++) {
		switch (*(tmp + i)) {
		case MSG_BYTE_ENDC:
		case MSG_BYTE_ESCC:
		case MSG_BYTE_STTC:
			*(result + res_len++) = MSG_BYTE_ESCC;
			/* no break */
		default:
			*(result + res_len++) = *(tmp + i);
		}
	}
	// 最后加上消息结束码
	*(result + res_len++) = MSG_BYTE_ENDC;
	// 返回长度
#ifdef __USE_MEMORY_BUFFER__
	memory_free(tmp);
#endif // __USE_MEMORY_BUFFER__
	return res_len;
}

extern u16 misc_unpack_message(u8* const result, u8 len, const u8* const pack) {
	// 值得注意的是 此处的消息是经过串口接收的
	// 不再存在起始码结束码转义码这些东西（第0层协议）
	// 直接解封第1层协议即可
#ifdef __USE_MEMORY_BUFFER__
	u8 * tmp = (u8*) memory_alloc_1k();
	if (tmp == 0) {
		return 0;
	}
#else //__USE_MEMORY_BUFFER__
	u8 tmp[512];
#endif //__USE_MEMORY_BUFFER__
	u32 res_len = 0;
	u16 check = 0;
	do {
		// 验证长度
		if (*pack != len) {
			res_len = 0;
			break;
		}
		// 第一次复制
		for (u8 i = 0; i < len; i++) {
			*(tmp + i) = *(pack + i);
		}
		// 后计算的先验证 验证SUM
		for (u8 i = 0; i < len; i++) {
			check += *(tmp + i);
		}
		if ((check & 0xFF) != 0) {
			res_len = 0;
			break;
		}
		// 清空SUM校验码
		*(tmp + 1) = 0;
		// 验证CRC
		check = (*(tmp + len - 2) << 8) + *(tmp + len - 1);
		*(tmp + len - 2) = 0;
		*(tmp + len - 1) = 0;
		if (check != misc_calculate_crc(tmp, len)) {
			res_len = 0;
			break;
		}
		// 验证通过 写结果
		for (u8 i = 0; i < len - 4; i++) {
			*(result + res_len++) = *(tmp + i + 2);
		}
		// OK
	} while (0);
#ifdef __USE_MEMORY_BUFFER__
	memory_free(tmp);
#endif // __USE_MEMORY_BUFFER__
	return res_len;
}
extern u8 misc_int2string(s8* buf, s32 num) {
	u8 first_num_flag = 0;	//第一个非0数字还没有出现
	u8 length = 0;
	u8 tmp = 0;
	if (num == 0) {
		*(buf + length++) = '0';
		*(buf + length++) = 0;
		return length;
	}
	if (num < 0) {
		*(buf + length++) = '-';
		num = -num;
	}
	if (num >= NUM_TABLE[0]) {
		*(buf + length++) = 'I';
		*(buf + length++) = 'n';
		*(buf + length++) = 'f';
		*(buf + length++) = 0;
		return length;
	}
	for (u8 i = 1; i < 10; i++) {
		tmp = num / NUM_TABLE[i];
		num %= NUM_TABLE[i];
		if (!first_num_flag) {
			if (!tmp) {
				continue;
			} else {
				first_num_flag = 1;
			}
		}
		*(buf + length++) = 0x30 + tmp;
	}
	*(buf + length++) = 0;
	return length;
}
extern u8 misc_int2string_a(s8* buf, s32 num) {
	u8 length = 0;
	u8 tmp = 0;
	if (num == 0) {
		*(buf + length++) = '0';
		*(buf + length++) = '0';
		*(buf + length++) = '0';
		*(buf + length++) = '0';
		*(buf + length++) = '0';
		*(buf + length++) = '0';
		*(buf + length++) = '0';
		*(buf + length++) = '0';
		*(buf + length++) = '0';
		*(buf + length++) = 0;
		return length;
	}
	if (num < 0) {
		*(buf + length++) = '-';
		num = -num;
	}
	if (num >= NUM_TABLE[0]) {
		*(buf + length++) = 'I';
		*(buf + length++) = 'n';
		*(buf + length++) = 'f';
		*(buf + length++) = 0;
		return length;
	}
	for (u8 i = 1; i < 10; i++) {
		tmp = num / NUM_TABLE[i];
		num %= NUM_TABLE[i];
		*(buf + length++) = 0x30 + tmp;
	}
	*(buf + length++) = 0;
	return length;
}
extern u8 misc_num2string(s8* buf, double num) {
	u8 length = 0;
	if (num < 0) {
		*(buf + length++) = '-';
		num = -num;
	}
	if (num >= NUM_TABLE[0]) {
		*(buf + length++) = 'I';
		*(buf + length++) = 'n';
		*(buf + length++) = 'f';
		*(buf + length++) = 0;
		return length;
	}
	u32 tmp = num;
	double num_f = num - tmp;
	length += misc_int2string(buf + length, tmp);

	*(buf + length - 1) = '.';	//结尾的\0改为小数点
	for (u8 i = 0; (i < 12 - length) && i < 4; i++) {
		num_f *= 10;
		tmp = num_f;
		num_f -= tmp;
		*(buf + length++) = 0x30 + tmp;
	}
	*(buf + length++) = 0;
	return length;
}
const u8 MONTH_DATE[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/**
 * 时间戳转换成时间结构
 */
extern s8 misc_uint2timetype(TimeType* tt, u32 timestamp) {
	if (tt == 0) {
		return -1;
	}
	// 是否为闰年
	u8 is_leap = 0;
	// 现在的时间戳精确到秒
	u8 second = timestamp % 60;
	// 现在的时间戳精确到分
	timestamp /= 60;
	u8 minute = timestamp % 60;
	// 现在的时间戳精确到时
	timestamp /= 60;
	u8 hour = timestamp % 24;
	// 现在的时间戳精确到日
	timestamp /= 24;
	// 目前这个变量里面存放着次时间戳处于某一个四年的第几天
	u16 date = timestamp % 1461;	//连续4年总天数
	u16 year = timestamp / 1461;	//过去了多少个4年
	// 时间戳从1970年开始，连续4年每年的天数是365,365,366,365
	year *= 4;	//已经过去了多少年
	year += 1970;	//转换到真正的年份
	do {
		if (date < 365) {
			break;
		}
		date -= 365;
		year++;
		if (date < 365) {
			break;
		}
		date -= 365;
		year++;
		if (date < 366) {
			// 只有到达这个分支才会是闰年
			is_leap = 1;
			break;
		}
		date -= 366;
		year++;
	} while (0);
	// 目前的情况是  年份已经找准，一年中的某一天已经找准，下面进行月份判断
	u8 month = 1;	//月份的基数是1
	for (u8 i = 0; i < 12; i++) {
		// 正在校验的月份的天数
		u8 current_month_date = *(MONTH_DATE + i);
		// 如果是闰年 而且是在2月
		if (is_leap != 0 && i == 1) {
			//把2月29日添加进去
			current_month_date++;
		}
		// 如果日期不足一个月
		if (date < current_month_date) {
			break;
		}
		// 否则推进一个月
		date -= current_month_date;
		month++;
	}
	// 由于之前的所有运算，日期都是从0开始记的，
	// 所以需要把日期向前推进1
	date++;
	tt->time_second = second;
	tt->time_minute = minute;
	tt->time_hour = hour;
	tt->time_date = (u8) date;
	tt->time_month = month;
	tt->time_year = year;
	return 0;
}
/**
 * 时间戳转换成可读的时间字符串
 * 缓冲区至少20字节！
 */
extern s8 misc_uint2timestring(s8* buf, u32 timestamp) {
	if (buf == 0) {
		return -1;
	}
	TimeType tt;
	misc_uint2timetype(&tt, timestamp);
	// FIXME 下面这段程序写的实在是有点傻，但是目前不想想太多
	// year 4 month 2 date 2 hour 2 minute 2 second 2
	u16 pointer = 0;
	u16 tmp;
	// 年份转换
	tmp = tt.time_year;
	*(buf + pointer++) = '0' + tmp / 1000;
	tmp %= 1000;
	*(buf + pointer++) = '0' + tmp / 100;
	tmp %= 100;
	*(buf + pointer++) = '0' + tmp / 10;
	tmp %= 10;
	*(buf + pointer++) = '0' + tmp;
	*(buf + pointer++) = '/';
	// 月份转换
	tmp = tt.time_month;
	*(buf + pointer++) = '0' + tmp / 10;
	tmp %= 10;
	*(buf + pointer++) = '0' + tmp;
	*(buf + pointer++) = '/';
	// 日期转换
	tmp = tt.time_date;
	*(buf + pointer++) = '0' + tmp / 10;
	tmp %= 10;
	*(buf + pointer++) = '0' + tmp;
	*(buf + pointer++) = ' ';
	// 小时转换
	tmp = tt.time_hour;
	*(buf + pointer++) = '0' + tmp / 10;
	tmp %= 10;
	*(buf + pointer++) = '0' + tmp;
	*(buf + pointer++) = ':';
	// 分钟转换
	tmp = tt.time_minute;
	*(buf + pointer++) = '0' + tmp / 10;
	tmp %= 10;
	*(buf + pointer++) = '0' + tmp;
	*(buf + pointer++) = ':';
	// 秒钟转换
	tmp = tt.time_second;
	*(buf + pointer++) = '0' + tmp / 10;
	tmp %= 10;
	*(buf + pointer++) = '0' + tmp;
	*(buf + pointer++) = 0;
	return pointer;
}
// [31:25]
#define MISC_FATTIME_MASK_YEAR      ((uint32_t) (0xFE000000))
// [24:21]
#define MISC_FATTIME_MASK_MONTH     ((uint32_t) (0x01E00000))
// [20:16]
#define MISC_FATTIME_MASK_DATE      ((uint32_t) (0x001F0000))
// [15:11]
#define MISC_FATTIME_MASK_HOUR      ((uint32_t) (0x0000F800))
// [10: 5]
#define MISC_FATTIME_MASK_MINUTE    ((uint32_t) (0x000007E0))
// [ 4: 0]
#define MISC_FATTIME_MASK_SECOND_2  ((uint32_t) (0x0000001F))
/**
 * 将时间戳转换成FAT适配的32位时间标记
 */
extern s8 misc_uint2fattime(u32* result, u32 timestamp) {
	if (result == 0) {
		return -1;
	}
	TimeType tt;
	misc_uint2timetype(&tt, timestamp);
	*result = 0;
	// [31:25]: YEAR origin from the 1980 (0..127)
	if (tt.time_year < 1980) {
		*result = 0;
		return 2;
	}
	tt.time_year -= 1980;
	*result |= MISC_FATTIME_MASK_YEAR & (tt.time_year << 25);
	*result |= MISC_FATTIME_MASK_MONTH & (tt.time_month << 21);
	*result |= MISC_FATTIME_MASK_DATE & (tt.time_date << 16);
	*result |= MISC_FATTIME_MASK_HOUR & (tt.time_hour << 11);
	*result |= MISC_FATTIME_MASK_MINUTE & (tt.time_minute << 5);
	*result |= MISC_FATTIME_MASK_SECOND_2 & (tt.time_second >> 1);
	return 0;
}

}
}

