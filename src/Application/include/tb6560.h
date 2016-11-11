#ifndef __TB6560_H__
#define __TB6560_H__

#include "stm32f10x.h"
#include "systick.h"

namespace QIU {
namespace PJ0 {
// 这个模块主要用于步进电机驱动板TB6560的控制
// 控制线一共3根
// PB10    EN+   0为工作状态    1为脱机状态
// PA11    CW+   0为正转标记   1为反转标记
// PA12    CLK+  一个脉冲步进电机走一步
/**
 * 使驱动板进入工作模式
 */
inline void tb6560_enable(void) {
	GPIO_ResetBits(GPIOB, GPIO_Pin_10);
}
/**
 * 使驱动板进入脱机模式
 */
inline void tb6560_disable(void) {
	GPIO_SetBits(GPIOB, GPIO_Pin_10);
}
/**
 * 获取当前步进电机的步数
 * @return 当前的步数
 */
extern s32 tb6560_get_stepcount(void);
/**
 * 设置步进电机的步数
 * @param stepcount_set 设置的步数
 */
extern void tb6560_set_stepcount(s32 stepcount_set);
/**
 * 使电机走一步
 * @param backward 如果为0正转一步 如果为1反转一步
 * @param stepcount 步数
 */
extern void tb6560_step(u8 backward, u32 stepcount);
/**
 * 初始化
 */
extern void tb6560_init(void);
}
}

#endif // __TB6560_H__
