#ifndef __SAMPLING_PRIVATE_H__
#define __SAMPLING_PRIVATE_H__

#include "stm32f10x.h"
#include "sampling.h"

namespace QIU {
namespace PJ0 {
#define SAMPLING_DATA_LENGTH_MAX   ((u16) (512))
#define SAMPLING_DATA_LENGTH_LIMIT ((u16) (500))
#define SAMPLING_DATA_INTERVAL_MAX ((u16) (1000))
#define SAMPLING_DATA_INTERVAL_MIN ((u16) (2))

// 采样间隔 - 1(毫秒)
extern u16 sampling_data_interval;
// 缓冲区第一个数据
extern u16 sampling_data_first;
// 缓冲区接下来可以用的数据区
extern u16 sampling_data_next_write;
// 主缓冲区
extern SamplingData * sampling_data_buffer;
/**
 * 获取下一个缓存写入指针
 * 仅用于中断！要保证中断在调用了这个函数之后，必须立即把对应的数据进行赋值，否则会出现无法预知的错误。
 * @return 0 获取失败
 */
extern SamplingData * sampling_write_next(void);
/**
 * 采样缓冲拥有多少条数据
 * @return 缓冲区中已有的数据条数
 *         如果返回负值，说明缓冲区不可用。
 */
extern s16 sampling_data_length(void);
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
