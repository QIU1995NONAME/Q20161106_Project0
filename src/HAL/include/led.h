#ifndef __LED_H__
#define __LED_H__

#include "stm32f10x.h"

namespace QIU{
namespace PJ0{
/**
 * LED直接显示某一个数据
 */
extern void led_display(u8 num);
/**
 * LED初始化(全灭)
 */
extern void led_init(void);

}
}

#endif // __LED_H__
