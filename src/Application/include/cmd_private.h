#ifndef __CMD_PRIVATE_H__
#define __CMD_PRIVATE_H__

#include "stm32f10x.h"
#include "cmd.h"
// 这个头文件是个内部头文件，不需要开放的
// 专供中断使用的头文件
namespace QIU {
namespace PJ0 {
// 缓冲区长度
#define CMD_BUFFER_LENGTH ((uint16_t) (1024))
// 缓冲区阈值(不宜过小)
// 如果缓冲区第一个有效的字节是开始码，
// 同时缓冲区里面有效数据的长度达到了此阈值
// 此时多半是发生了数据错误，一旦这种情况出现则直接清空缓冲
#define CMD_BUFFER_LIMIT  ((uint16_t) (896))
// 信息结束码
const s8 CMD_ENDC = 0x25;
// 关键字转义码
const s8 CMD_ESCC = 0x75;
// 数据起始码
const s8 CMD_STTC = 0x5D;
// 用来存放接收到的数据
// 同时这个变量也是缓冲区是否可用的标志
extern s8 * cmd_buffer_1k;
// 指向下一个存放数据的指针
extern u16 cmd_buffer_pointer_next_write;
// 指向下一个读取数据的指针
extern u16 cmd_buffer_pointer_next_read;
/**
 * 刷新，查看缓冲区里面是否有可用的命令
 * @return 如果缓冲区里面有可用的命令则返回1
 *         否则返回0
 */
extern s8 cmd_buffer_has_command(void);
/**
 * 获取缓冲区第一个字节数据，同时移除它
 * 注意，如果获取的字节数据是负数，会被直接转化成正数
 * 例：-1会变换成255 -2会变成254.。。。
 *
 * @return -1 表示缓冲区已经空
 *            否则低8位表示缓冲区内的数据
 */
extern s16 cmd_buffer_remove_first(void);
/**
 * 将数据放置在缓冲区中
 * 这个函数会被中断调用，绝对不要出现循环和延时！
 * @return 0 表示存入成功
 *         其他 表示存入失败
 */
extern s8 cmd_buffer_add_last(s8 dat);
/**
 * 内部强制初始化
 */
extern s8 cmd_init_0(void);
/**
 * 获取缓冲区第一个字节的数据
 */
inline s8 cmd_buffer_get_first(void) {
	return *(cmd_buffer_1k + cmd_buffer_pointer_next_read);
}

}
}

#endif // __CMD_PRIVATE_H__
