#ifndef __FRAME_H__
#define __FRAME_H__

#include "stm32f10x.h"

// 此文件只能被需要框架的地方引用
#ifndef __QIU_PJ0_NEED_FRAME__
#error "此文件只能被需要框架的地方引用!"
#endif

namespace QIU {
namespace PJ0 {

/**
 * 硬件配置函数
 */
extern void __frame_1_hal_config__(void);
/**
 * 纯软件部分初始化函数
 */
extern void __frame_2_app_init__(void);
/**
 * 框架主循环
 */
extern void __frame_3_main_loop__(void);

}
}

#endif // __FRAME_H__
