#ifndef __FRAME_TASK_H__
#define __FRAME_TASK_H__

#include "stm32f10x.h"
#include "tim6heartbeat.h"

namespace QIU {
namespace PJ0 {

/**
 * 计划任务初始化
 */
extern void __task_init__(void);

}
}

#endif // __FRAME_TASK_H__
