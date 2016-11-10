#ifndef __CMD_H__
#define __CMD_H__

#include "stm32f10x.h"

namespace QIU {
namespace PJ0 {
/**
 * 从串口缓冲中尝试获取数据。并将分析之后的数据放置在上层应用的缓冲区中
 * @param buf 传入的缓冲区。可以使用的长度必须至少64字节
 * @return 获取到的数据长度
 *         如果返回值是0，说明没有获取到数据
 *         如果返回值小于0 说明获取到的数据有问题
 */
extern s16 cmd_buffer_analyze_data(s8* buf);
/**
 * 缓冲区是否为空
 * 只有在处理数据的时候关心是否空
 * @return 如果本缓冲区不可用，或本来就是空的则返回1
 *         如果本缓冲区有数据，返0
 */
extern s8 cmd_buffer_is_empty(void);

/**
 * 缓冲区是否已满
 * 只有在接收数据的时候才会关心是否满
 * @return 如果缓冲区不可用，或本来已满，则返回1
 *         如果缓冲区未满，则返回0
 */
extern s8 cmd_buffer_is_full(void);

/**
 * 清空缓冲区
 * 实质上就是把两个指针置零
 * 几乎不用！
 */
extern s8 cmd_buffer_clear(void);
/**
 * 获取现在缓冲区中有多少数据
 * @return 缓冲区中有多少数据
 */
extern u16 cmd_buffer_length(void);
/**
 * 串口命令功能初始化
 */
extern s8 cmd_init(void);

}
}

#endif // __CMD_H__
