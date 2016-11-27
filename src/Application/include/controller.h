#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "stm32f10x.h"

namespace QIU {
namespace PJ0 {
/**
 * 这个文件中主要提供了对两个项目所需要数据以及控制模块的控制
 * 项目包括帆版风扇(1)和步进电机(2)，由“当前项目”标识。
 * 两个项目都有的功能：角度传感器置0。这个功能只有在下面两种控制模式0中有效。
 * 帆版风扇项目的控制模式包括:
 *  0. 手动控制（提供风扇转速(int))(默认)
 *  1. 自动控制（提供PID参数(double)及角度脉冲(int).
 * 步进电机项目的控制模式包括:
 *  0. 回归静止 (提供所在的步子(int))(默认)
 *  1. 平面水平摆动(无参数 实时调平)
 *  2. 正转(定时正转)(给出每50ms转动的步子(uint))
 *  3. 反转(定时反转)(给出每50ms转动的步子(uint))
 *  4. 来回摆（最好能控制摆幅）。
 *
 */

/**
 * 设置当前的工程代号
 * @param project 工程代号
 */
extern void controller_set_project(s8 project);

/**
 * 获取当前工程代号
 * @return 工程代号
 */
extern s8 controller_get_project(void);

/**
 * 控制器初始化
 * @return 状态值 0为成功
 */
extern s8 controller_init(void);

}
}

#endif // __CONTROLLER_H__
