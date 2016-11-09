#include "cmd_private.h"
#include "memory.h"
namespace QIU {
namespace PJ0 {
// 用来存放接收到的数据
// 同时这个变量也是缓冲区是否可用的标志
s8 * cmd_buffer_1k = 0;
// 指向下一个存放数据的指针
u16 cmd_buffer_pointer_next_write = 0;
// 指向下一个读取数据的指针
u16 cmd_buffer_pointer_next_read = 0;
/**
 * 刷新，查看缓冲区里面是否有可用的命令
 * 可以用于主循环中的串口数据检测
 * @return 如果缓冲区里面有可用的命令则返回1
 *         否则返回0
 */
extern s8 cmd_buffer_has_command(void) {
	do {
		// 把结束的这个玩意缓存，预防由于中断引起的数据异常问题
		u16 tmp_next_write = cmd_buffer_pointer_next_write;
		// 逐个检测，如果开头不是数据起始标记，直接删掉
		while (!cmd_buffer_is_empty()) {
			if (cmd_buffer_get_first() != CMD_STTC) {
				cmd_buffer_remove_first();
				continue;
			} else {
				break;
			}
		}
		// 如果缓冲区是空的，直接跳出
		if (cmd_buffer_is_empty()) {
			break;
		}
		// 查找结束标记
		// FIXME 考虑到每一次主循环都完全扫描一次缓冲区有可能影响到运行速度
		//       所以在此只验证最后的一个或者两个字节是否是有效的结束码
		// 如果倒数第二个字节是转义字符，则这个消息一定不完整
		if (CMD_ESCC
				== (tmp_next_write < 2 ?
						*(cmd_buffer_1k + CMD_BUFFER_LENGTH
								+ tmp_next_write - 2) :
						*(cmd_buffer_1k + tmp_next_write - 2))) {
			break;
		}
		// 如果倒数第二个字符不是是转义字符，而且最后一个字符是结束码，则缓冲区中有有效的数据
		if (CMD_ENDC
				== (tmp_next_write < 1 ?
						*(cmd_buffer_1k + CMD_BUFFER_LENGTH
								+ tmp_next_write - 1) :
						*(cmd_buffer_1k + tmp_next_write - 1))) {
			return 1;
		}
		// 如果缓冲区中没有有效的数据（运行到这里已经说明这个问题了）
		// 同时数据量超过了阈值，则直接清空缓冲区
		if(cmd_buffer_length() > CMD_BUFFER_LIMIT){
			cmd_buffer_clear();
		}
	} while (0);
	return 0;
}
/**
 * 获取缓冲区第一个字节数据，同时移除它
 * 注意，如果获取的字节数据是负数，会被直接转化成正数
 * 例：-1会变换成255 -2会变成254.。。。
 *
 * @return -1 表示缓冲区已经空
 *            否则低8位表示缓冲区内的数据
 */
extern s16 cmd_buffer_remove_first(void) {
	if (cmd_buffer_is_empty()) {
		return -1;
	}
	s16 res = (u8) (cmd_buffer_get_first());
	cmd_buffer_pointer_next_read++;
	if (cmd_buffer_pointer_next_read > CMD_BUFFER_LENGTH - 1) {
		cmd_buffer_pointer_next_read -= CMD_BUFFER_LENGTH;
	}

	return res;
}
/**
 * 将数据放置在缓冲区中
 * 这个函数会被中断调用，绝对不要出现循环和延时！
 * @return 0 表示存入成功
 *         其他 表示存入失败
 */
extern s8 cmd_buffer_add_last(s8 dat) {
// 如果不可用
	if (!cmd_buffer_1k) {
		return -1;
	}
// 如果已满
	if (cmd_buffer_is_full()) {
		return 1;
	}
// 写入一个数据
	*(cmd_buffer_1k + cmd_buffer_pointer_next_write++) = dat;
// 调整指针
	if (cmd_buffer_pointer_next_write > CMD_BUFFER_LENGTH - 1) {
		cmd_buffer_pointer_next_write -= CMD_BUFFER_LENGTH;
	}
	return 0;
}
/**
 * 内部强制初始化
 */
extern s8 cmd_init_0(void) {
// 如果缓冲区可用
	if (cmd_buffer_1k) {
		memory_free(cmd_buffer_1k);
	}
	cmd_buffer_1k = (s8*) memory_alloc0_1k();
	cmd_buffer_pointer_next_write = 0;
	cmd_buffer_pointer_next_read = 0;
// 如果缓冲区不可用
	if (!cmd_buffer_1k) {
		return -1;
	}
// 正常退出
	return 0;
}

}
}
