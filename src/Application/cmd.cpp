#include "cmd_private.h"
#include "memory.h"
#include "systick.h"
#include "usart.h"
#include "q_signal.h"
#include "q_misc.h"
namespace QIU {
namespace PJ0 {
/**
 * 向上位机发送数据
 * @param msg 要发送的数据缓冲区
 * @param len 数据长度
 */
extern s8 cmd_buffer_send_data(const u8* const msg, u8 len) {
	// 创建一个信息处理和发送缓冲区
	u8 * tmpbuf = (u8*) memory_alloc_1k();
	if (tmpbuf == 0) {
		return -1;
	}
	u16 tmp_len = (u16) len + 4;
	// 第0个字节 消息长度
	*(tmpbuf) = tmp_len;
	// 第1个字节 校验和
	*(tmpbuf + 1) = 0;
	// 复制数据
	for (u16 i = 0; i < len; i++) {
		*(tmpbuf + 2 + i) = *(msg + i);
	}
	// 预留CRC
	*(tmpbuf + tmp_len - 2) = 0x00;
	*(tmpbuf + tmp_len - 1) = 0x00;
	// 计算CRC
	u16 check = misc_calculate_crc(tmpbuf, tmp_len);
	// 填入消息
	*(tmpbuf + tmp_len - 2) = 0xFF & (check >> 8);
	*(tmpbuf + tmp_len - 1) = 0xFF & check;
	// 计算SUM
	check = 0;
	for (u16 i = 0; i < tmp_len; i++) {
		check += *(tmpbuf + i);
	}
	// 只留低8位
	check &= 0xFF;
	check = 0x100 - check;
	*(tmpbuf + 1) = 0xFF & check;
	// 准备发送
//	// FIXME 总有数据发不出去！
//	usart_1_ready_to_send();
	// 起始码
	usart_1_send(CMD_STTC);
	for (u16 i = 0; i < tmp_len; i++) {
		switch (*(tmpbuf + i)) {
		case CMD_ENDC:
		case CMD_ESCC:
		case CMD_STTC:
			usart_1_send(CMD_ESCC);
			/* no break */
		default:
			usart_1_send(*(tmpbuf + i));
		}
	}
	// 结束码
	usart_1_send(CMD_ENDC);
	memory_free(tmpbuf);
	return 0;
}

/**
 * 从串口缓冲中尝试获取数据。并将分析之后的数据放置在上层应用的缓冲区中
 * @param buf 传入的缓冲区
 * 可以使用的长度必须至少64字节
 * 保险起见至少准备1KB
 * @return 获取到的数据长度
 *         如果返回值是0，说明没有获取到数据
 *         如果返回值小于0 说明获取到的数据有问题
 */
extern s16 cmd_buffer_analyze_data(u8* buf) {
	// 如果缓冲区中没有可用的命令
	if (!cmd_buffer_has_command()) {
		return 0;
	}
	// 如果第一个字节不是起始字节，直接退出
	if (cmd_buffer_remove_first() != CMD_STTC) {
		return 0;
	}
	// 开始正式收拾数据
	u16 count = CMD_BUFFER_LENGTH;
	// 是否处于转义模式
	s8 status_escape = 0;
	// 获得的数据长度
	s16 length = 0;
	// 临时存放数据
	s8 tmp;
	// 防止死循环
	while (count--) {
		if (status_escape) {
			// 关闭转义模式
			status_escape = 0;
			// 直接把下一个字节放入缓冲区
			*(buf + length++) = cmd_buffer_remove_first();
			continue;
		}
		// 如果不在转义模式，先判断关键字
		tmp = cmd_buffer_remove_first();
		// 如果是转义字符
		if (tmp == CMD_ESCC) {
			status_escape = 1;
			continue;
		}
		// 如果是结束符
		if (tmp == CMD_ENDC) {
			// 正确的退出方式应该是这里！
			break;
		}
		// 否则
		*(buf + length++) = tmp;
	}
	// 如果上面的退出循环是因为防止死循环退出来的
	// 立即退出，返回错误码
	if (count == 0) {
		return 0xFF00;
	}
	// 开始验证 第一层数据解析已经通过
	// 长度验证
	tmp = *buf;
	if (tmp != length) {
		return 0xF100;	// 长度验证失败
	}
	// 求和验证
	tmp = 0;
	for (u8 i = 0; i < length; i++) {
		tmp += *(buf + i);
	}
	if (tmp != 0) {
		return 0xF200;	// CHECKSUM失败
	}
	// 校验和通过 删除校验和数据
	*(buf + 1) = 0;
	// 准备进行CRC校验
	u16 r_crc = 0;	// 数据中的CRC16
	u16 c_crc = 0;	// 计算出的CRC16
	// 先提取出数据中的CRC
	r_crc = (u8) *(buf + length - 2);
	r_crc <<= 8;
	r_crc |= (u8) *(buf + length - 1);
	// 然后删去CRC数据
	*(buf + length - 2) = 0;
	*(buf + length - 1) = 0;
	c_crc = misc_calculate_crc((u8*) buf, length);
	// 校验
	if (c_crc != r_crc) {
		return 0xF300;	//CRC16校验失败
	}
	// 所有的验证通过，去掉校验数据占用的字节，只保留命令字节和参数字节
	// 需要去掉开头的长度和校验和，结尾的两个CRC
	length -= 4;
	for (u8 i = 0; i < length; i++) {
		*(buf + i) = *(buf + i + 2);
	}
	return length;
}

/**
 * 缓冲区是否为空
 * 只有在处理数据的时候关心是否空
 * @return 如果本缓冲区不可用，或本来就是空的则返回1
 *         如果本缓冲区有数据，返0
 */
extern s8 cmd_buffer_is_empty(void) {
	if (!cmd_buffer_1k) {
		return 1;
	}
	return cmd_buffer_pointer_next_write == cmd_buffer_pointer_next_read;
}
/**
 * 缓冲区是否已满
 * 只有在接收数据的时候才会关心是否满
 * 这个函数会被中断调用，绝对不要写循环或者延时！
 * @return 如果缓冲区不可用，或本来已满，则返回1
 *         如果缓冲区未满，则返回0
 */
extern s8 cmd_buffer_is_full(void) {
	if (!cmd_buffer_1k) {
		return 1;
	}
	u16 tmp;
	tmp = cmd_buffer_pointer_next_write + 1;
	if (tmp > CMD_BUFFER_LENGTH - 1) {
		tmp -= CMD_BUFFER_LENGTH;
	}
	return tmp == cmd_buffer_pointer_next_read;
}
/**
 * 清空缓冲区
 * 实质上就是把两个指针置零
 * 几乎不用！
 */
extern s8 cmd_buffer_clear(void) {
	cmd_buffer_pointer_next_read = 0;
	cmd_buffer_pointer_next_write = 0;
	return 0;
}
/**
 * 获取现在缓冲区中有多少数据
 * @return 缓冲区中有多少数据
 */
extern u16 cmd_buffer_length(void) {
	u16 res = cmd_buffer_pointer_next_write;
	if (res < cmd_buffer_pointer_next_read) {
		res += CMD_BUFFER_LENGTH;
	}
	res -= cmd_buffer_pointer_next_read;
	return res;
}
/**
 * 串口命令初始化
 * @return 0表示初始化成功
 *         其他表示初始化失败
 */
extern s8 cmd_init(void) {
	if (!cmd_buffer_1k) {
		return cmd_init_0();
	}
	return 0;
}

}
}
