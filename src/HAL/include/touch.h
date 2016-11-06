#ifndef __TOUCH_H__
#define __TOUCH_H__

#include "stm32f10x.h"

namespace QIU {
namespace PJ0 {

// 读取现在的物理坐标
extern void touch_read_point(u16* x, u16* y);
// 初始化函数
extern void touch_init(void);

// 通过验证(PD7)TOUCH_PEN判断是否触摸
// TOUCH_PEN 低为触摸 高为未触摸
inline s8 touch_is_touched(void){
	if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_7)){
		return 0;
	}else{
		return 1;
	}
}

}
}

#endif // __TOUCH_H__
