#ifndef __FATFS_H__
#define __FATFS_H__

#include "stm32f10x.h"

namespace QIU {
namespace PJ0 {
/**
 * 返回SD卡上面的文件系统是否可用
 * @return 0为不可用
 *         1为可用
 */
extern s8 fatfs_0_is_avail(void);
/**
 * 初始化文件系统FATFS
 * 由于目前只有SD卡支持此类操作
 * 所以这个函数的功能就是初始化SD卡并挂载
 */
extern void fatfs_init(void);

}
}

#endif // __FATFS_H__
