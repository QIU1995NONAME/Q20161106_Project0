#ifndef __E6A2_H__
#define __E6A2_H__

#include "stm32f10x.h"

namespace QIU {
namespace PJ0 {
/**
 * 只有中断可以赋予这个变量0以外的值
 */
extern s32 e6a2_var;
/**
 * 编码器E6A2计数清零
 */
extern void e6a2_reset(void);
/**
 * 读取编码器E6A2当前的计数值
 */
extern s32 e6a2_read(void);

}
}

#endif // __E6A2_H__
