#ifndef __CONTROLLER_PRIVATE_H__
#define __CONTROLLER_PRIVATE_H__

#include "stm32f10x.h"
#include "controller.h"

namespace QIU {
namespace PJ0 {

extern void * controller_buffer_1k;
extern s16 controller_project;
extern s16 controller_mode;

/**
 * 定时20ms执行的函数，用来进行控制
 * 挂在定时系统上面的，不可以直接调用
 */
extern void controller_task_20ms(void);

/**
 * 强制初始化
 * @return 0 代表成功
 */
extern s8 controller_init_0(void);

}
}

#endif // __CONTROLLER_PRIVATE_H__
