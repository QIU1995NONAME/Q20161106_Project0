#ifndef __INCLUDES_H__
#define __INCLUDES_H__

#include "stm32f10x.h"

#include "beep.h"
#include "e6a2.h"
#include "exti.h"
#include "gpio.h"
#include "gui.h"
#include "fan.h"
#include "fatfs.h"
#include "ff.h"
#include "flash.h"
#include "fsmc.h"
#include "key.h"
#include "led.h"
#include "memory.h"
#include "nvic.h"
#include "q_signal.h"
#include "q_misc.h"
#include "rtc.h"
#include "spi.h"
#include "systick.h"
#include "touch.h"
#include "tft.h"
#include "tim6heartbeat.h"
#include "timer.h"
#include "usart.h"
/*
 * 这个文件仅仅用来方便防止大量的include
 * 只有中断所在的文件以及以双下划线开头的文件可以使用此文件
 * 此文件不可以include以双下划线开头的头文件
 */

#endif // __INCLUDES_H__
