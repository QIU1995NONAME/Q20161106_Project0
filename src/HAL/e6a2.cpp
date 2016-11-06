#include "e6a2.h"

namespace QIU {
namespace PJ0 {
/**
 * 只有中断可以赋予这个变量0以外的值
 */
s32 e6a2_var = 0;
/**
 * 编码器E6A2计数清零
 */
extern void e6a2_reset(void) {
	e6a2_var = 0;
}
/**
 * 读取编码器E6A2当前的计数值
 */
extern s32 e6a2_read(void) {
	return e6a2_var;
}

}
}
