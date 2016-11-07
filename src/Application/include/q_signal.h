#ifndef __Q_SIGNAL_H__
#define __Q_SIGNAL_H__

#include "stm32f10x.h"

namespace QIU {
namespace PJ0 {
/**
 * 一个很有可能没啥用的信号系统
 * 没用的原因是信号反应比较慢
 */
// 系统信号源
const s16 SIGNAL_SYS = 0x00;

/**
 * 创建并获取一个信号源
 */
extern s8 signal_create_source(void);
/**
 * 注册一个信号 1为注册成功 0为注册失败
 * 信号ID的取值范围 0~15
 */
extern s8 signal_register(s16 source_id, u16 signal_id);
/**
 * 以什么样的身份监听某一个信号
 * 信号ID的取值范围 0~15
 * 如果信号源是系统本身，而信号获取者不是系统，则信号不销毁
 * 否则一旦被监听到，就销毁这个信号
 */
extern s8 signal_listen(s16 listener_id, s16 source_id, u16 signal_id);
/**
 * 触发一个信号
 * 信号ID的取值范围 0~15
 * @return 1 表示触发成功
 *         0 表示未触发
 */
extern s8 signal_trigger(s16 source_id, u16 signal_id);
/**
 * 取消一个信号的触发状态
 * 信号ID的取值范围 0~15
 * @return 1 表示取消成功
 *         0 表示未取消
 */
extern s8 signal_cancel(s16 source_id, u16 signal_id);
/**
 * 信号系统初始化 并返回是否正常初始化
 * @return 初始化是否有问题
 *         0 初始化成功
 *         1 初始化失败
 * @warning 如果初始化失败的话后面用到信号系统的地方都会崩溃
 *          所以建议如果初始化失败则直接进入死循环
 */
extern s8 signal_init(void);

}
}

#endif // __Q_SIGNAL_H__
