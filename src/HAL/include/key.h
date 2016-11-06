#ifndef __KEY_H__
#define __KEY_H__

#include "stm32f10x.h"

namespace QIU {
namespace PJ0 {

// 初始化按键信号 0为成功 1为失败
extern s8 key_init(void);
//这个系列是经过消抖处理的读取按键值 但是每一个函数都会延时10ms
extern s8 key_delay_up(void);
//这个系列是经过消抖处理的读取按键值 但是每一个函数都会延时10ms
extern s8 key_delay_left(void);
//这个系列是经过消抖处理的读取按键值 但是每一个函数都会延时10ms
extern s8 key_delay_down(void);
//这个系列是经过消抖处理的读取按键值 但是每一个函数都会延时10ms
extern s8 key_delay_right(void);
//这个系列是不经过消抖的读取按键值 需要在上层程序中消除抖动
//PA0 K_UP 0 未按下 1 按下
inline s8 key_raw_up(void) {
	return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) ? 1 : 0;
}
//这个系列是不经过消抖的读取按键值 需要在上层程序中消除抖动
//PE2 K_LEFT 1 未按下 0 按下
inline s8 key_raw_left(void) {
	return GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2) ? 0 : 1;
}
//这个系列是不经过消抖的读取按键值 需要在上层程序中消除抖动
//PE3 K_DOWN 1 未按下 0 按下
inline s8 key_raw_down(void) {
	return GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3) ? 0 : 1;
}
//这个系列是不经过消抖的读取按键值 需要在上层程序中消除抖动
//PE4 K_RIGHT 1 未按下 0 按下
inline s8 key_raw_right(void) {
	return GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) ? 0 : 1;
}

}
}

#endif // __BEEP_H__
