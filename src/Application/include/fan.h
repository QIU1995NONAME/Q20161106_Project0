#ifndef __FAN_H__
#define __FAN_H__

#include "stm32f10x.h"

namespace QIU {
namespace PJ0 {
/**
 * 获取风扇的转速
 * @return 当前设定的风扇转速
 */
extern u16 fan_get_level(void);
/**
 * 设置风扇的转速
 * 参数范围 0 ~ 1799
 */
extern void fan_set_level(u16 level);
/**
 * 风扇初始化
 * 实际上就是将转速设置为0
 */
extern void fan_init(void);

}
}

#endif // __FAN_H__
