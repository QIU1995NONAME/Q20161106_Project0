#ifndef __SAMPLING_PRIVATE_H__
#define __SAMPLING_PRIVATE_H__

#include "stm32f10x.h"
#include "sampling.h"

namespace QIU {
namespace PJ0 {
#define SAMPLING_DATA_MAX_LENGTH ((u16) (400))
// 缓冲区第一个数据
extern u16 sampling_data_first;
// 缓冲区最后一个数据
extern u16 sampling_data_last;
// 缓冲区接下来可以用的数据区
extern u16 sampling_data_next_write;
// 主缓冲区
extern SamplingData * sampling_data_buffer;
/**
 * 强制初始化。
 * 包括初始化一个大一些的缓冲，
 * 创建环形缓冲列表等。
 * @return 0 为初始化成功
 *         否则为初始化失败
 */
extern s8 sampling_init_0(void);

}
}

#endif // __SAMPLING_PRIVATE_H__
