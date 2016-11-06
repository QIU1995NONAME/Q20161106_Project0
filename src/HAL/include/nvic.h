#ifndef __NVIC_H__
#define __NVIC_H__

#include "stm32f10x.h"

namespace QIU{
namespace PJ0{
/**
 * 中断优先级配置
 */
extern void nvic_config(void);

}
}

#endif // __NVIC_H__
