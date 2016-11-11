#ifndef __RTC_H__
#define __RTC_H__

#include <stm32f10x.h>

namespace QIU{
namespace PJ0{
/**
 * 向RTC的计数器写入数值
 */
extern void rtc_set_counter(u32 num);
/**
 * RTC 配置
 */
extern void rtc_config(void);
/**
 * RTC 初始化
 */
extern void rtc_init(void);
/**
 * 获取RTC计数器的数值
 */
inline u32 rtc_get_counter(void){
	return RTC_GetCounter();
}

}
}

#endif // __RTC_H__
