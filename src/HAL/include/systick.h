#ifndef __SYSTICK_H__
#define __SYSTICK_H__

#include "stm32f10x.h"

namespace QIU{
namespace PJ0{
/**
 * 精确延时：微秒延时
 */
extern void delay_us(u32 us);
/**
 * 精确延时：微秒级别的毫秒延时
 */
extern void delay_ms(u32 ms);

}
}



#endif // __SYSTICK_H__
