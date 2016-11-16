#include "sampling_private.h"
#include "memory.h"

namespace QIU {
namespace PJ0 {
/**
 * 初始化。包括初始化一个大一些的缓冲。
 * 创建环形缓冲列表。
 */
extern s8 sampling_init(void) {
	if (!sampling_data_buffer) {
		return sampling_init_0();
	}
	return 0;
}
}
}
