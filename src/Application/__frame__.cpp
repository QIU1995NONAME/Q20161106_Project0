#define __QIU_PJ0_NEED_FRAME__
#include "__frame__.h"
#include "stm32f10x.h"
#include "__frame_task__.h"
#include "__manager__.h"
#include "__includes__.h"
// 如果需要添加新模块的头文件
// 直接添加到__includes__.h

#define __FRAME_INIT_DEBUG_INFO__

namespace QIU {
namespace PJ0 {

#ifdef __FRAME_INIT_DEBUG_INFO__
s8 frame_debuf_buffer[32];
#endif // __FRAME_INIT_DEBUG_INFO__
//
extern void __frame_1_hal_config__(void) {
	rtc_config();  //0
	gpio_config(); //1
	exti_config();
	timer_config();
	usart_config();
	fsmc_config();
	spi_config();
	nvic_config(); //last
}
//
extern void __frame_2_app_init__(void) {
	TFT_Init(); //0
	gui_init();
	// ==============================================================================
	// 接下来的初始化程序可以打印出调试信息
	if (memory_init()) { //0
#ifdef __FRAME_INIT_DEBUG_INFO__
		gui_print_inner_char((s8*) "Memory ERROR!", GUI_COLOR_F00,
		GUI_COLOR_444);
		gui_print_next_line();
#endif // __FRAME_INIT_DEBUG_INFO__
		while (1) {
			; //内存初始化失败 程序会被停在这里
		}
	}
	fatfs_init(); //2
	if (signal_init()) {
#ifdef __FRAME_INIT_DEBUG_INFO__
		gui_print_inner_char((s8*) "Q Signal ERROR!", GUI_COLOR_F00,
		GUI_COLOR_444);
		gui_print_next_line();
#endif // __FRAME_INIT_DEBUG_INFO__
		while (1)
			; //信号系统失败系统卡死
	}
	cmd_init();
	// 必须在T6初始化之前
	if(sampling_init()){
#ifdef __FRAME_INIT_DEBUG_INFO__
		gui_print_inner_char((s8*) "RTSampling ERROR!", GUI_COLOR_F00,
		GUI_COLOR_444);
		gui_print_next_line();
#endif // __FRAME_INIT_DEBUG_INFO__
	}
	tim6_heartbeat_init(); //4
	// 必须在T6初始化之后
	if (manager_init()) {
#ifdef __FRAME_INIT_DEBUG_INFO__
		gui_print_inner_char((s8*) "Manager ERROR!", GUI_COLOR_F00,
		GUI_COLOR_444);
		gui_print_next_line();
#endif // __FRAME_INIT_DEBUG_INFO__
		while (1) {
		}
	}
	// 把调试信息清空 准备开始应用层初始化
	gui_clear_screen();
	// ==============================================================================
	led_init();
	key_init();
	e6a2_reset();
	fan_init();
	tb6560_init();
	// 一定是最后初始化计划任务！
	__task_init__(); //last
}
//
extern void __frame_3_main_loop__(void) {
	manager_main_loop_function();
	tim6_heartbeat_main_loop_function();
}

}
}
