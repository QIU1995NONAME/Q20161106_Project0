#ifndef __CONTROLLER_PRIVATE_H__
#define __CONTROLLER_PRIVATE_H__

#include "stm32f10x.h"
#include "controller.h"

namespace QIU {
namespace PJ0 {

extern void * controller_parambuf_2k;
extern s8 controller_project;
extern s8 controller_mode;

#define CTRL_PARAMBUF_INT_LENGTH     ((u8) (240))
#define CTRL_PARAMBUF_DBL_LENGTH     ((u8) (128))
// XXX 缓冲区预留8字节
// INT变量是否可写 240个 30字节
#define CTRL_BUF_INT_RW    ((unsigned char *) ((char *)controller_parambuf_2k + 8))
// DBL变量是否可写 128个 16字节
#define CTRL_BUF_DBL_RW    ((unsigned char *) ((char *)controller_parambuf_2k + 38))
// XXX 缓冲区预留10字节
// 240个int
#define CTRL_BUF_INT       ((int *) ((char *)controller_parambuf_2k + 64))
// 128个double
#define CTRL_BUF_DBL       ((double *) ((char *)controller_parambuf_2k + 1024))
/// 变量权限初始化
extern s8 controller_rw_reset(void);
/// 获取变量是否可写
extern s8 controller_get_rw_int(u8 index);
/// 设置变量是否可写
extern s8 controller_set_rw_int(u8 index , s8 rw);
/// 获取变量是否可写
extern s8 controller_get_rw_double(u8 index);
/// 设置变量是否可写
extern s8 controller_set_rw_double(u8 index , s8 rw);

/// 强制变量设定
extern s8 controller_set_0_int(u8 index, int value);
/// 强制变量设定
extern s8 controller_set_0_double(u8 index, double value);

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

// 其它各个工程的初始化以及执行算法
// 分布在各个文件中

extern s8 controller_0_init(void);
extern s8 controller_1_init(void);
extern s8 controller_2_init(void);

extern void controller_0_task(s8 mode);
extern void controller_1_task(s8 mode);
extern void controller_2_task(s8 mode);

}
}

#endif // __CONTROLLER_PRIVATE_H__
