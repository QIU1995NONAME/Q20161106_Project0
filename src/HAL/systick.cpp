#include "systick.h"

namespace QIU {
namespace PJ0 {

extern void delay_us(u32 us) {
	u32 tmp;
	SysTick->LOAD = 9 * us; // 设置重装数值
	SysTick->CTRL = 0x01;  // 使能，不启动中断，时钟源HCLK/8
	SysTick->VAL  = 0;     // 清零计数数值
	do {
		tmp = SysTick->CTRL; // 获取
	} while ((tmp & 0x00000001) && (!(tmp & 0x00010000))); // 直到时间到达
	SysTick->CTRL = 0;  //关闭
	SysTick->VAL  = 0;  //清除
}
extern void delay_ms(u32 ms) {
	u32 tmp;
	SysTick->LOAD = 9000 * ms; // 设置重装数值
	SysTick->CTRL = 0x01;  // 使能，不启动中断，时钟源HCLK/8
	SysTick->VAL  = 0;     // 清零计数数值
	do {
		tmp = SysTick->CTRL; // 获取
	} while ((tmp & 0x00000001) && (!(tmp & 0x00010000))); // 直到时间到达
	SysTick->CTRL = 0;  //关闭
	SysTick->VAL  = 0;  //清除
}

}
}

