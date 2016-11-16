#include "sampling_private.h"
#include "memory.h"

namespace QIU {
namespace PJ0 {
// 缓冲区第一个数据
u16 sampling_data_first = 0;
// 缓冲区最后一个数据
u16 sampling_data_last = 0;
// 缓冲区接下来可以用的数据区
u16 sampling_data_next_write = 0;
// 主缓冲区
SamplingData * sampling_data_buffer = 0;
/**
 * 强制初始化。
 * 包括初始化一个大一些的缓冲，
 * 创建环形缓冲列表等。
 * @return 0 为初始化成功
 *         否则为初始化失败
 */
extern s8 sampling_init_0(void) {
	if (sampling_data_buffer) {
		memory_free(sampling_data_buffer);
		sampling_data_buffer = 0;
	}
	void * p = memory_alloc0_8k();
	if (!p) {
		// 内存不足
		return -1;
	}
	sampling_data_buffer = (SamplingData *) (p);
	sampling_data_first = 0;
	sampling_data_last = 0;
	sampling_data_next_write = 0;
	return 0;
}

}
}
