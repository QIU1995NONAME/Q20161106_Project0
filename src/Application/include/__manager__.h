#ifndef __MANAGER___H__
#define __MANAGER___H__

#include "__includes__.h"

namespace QIU {
namespace PJ0 {
/**
 * 这个文件主要掌管着上位机与此单片机的交互功能
 * 同时兼有通过数据与命令的交互调动各个单片机功能的任务
 */
/**
 * 管理器主循环
 * 除了主循环以外不得被任何其他方式调用
 */
extern void manager_main_loop_function(void);
/**
 * 管理器初始化
 * 一旦初始化失败应当立刻进入死循环。
 * @return 0 初始化成功
 *         否则初始化失败
 */
extern s8 manager_init(void);

}
}

#endif // __MANAGER___H__
