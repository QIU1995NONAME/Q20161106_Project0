#define __QIU_PJ0_NEED_FRAME__
#include "__frame__.h"
#include "__frame_task__.h"
#include "__includes__.h"
#include "__manager__.h"
// 如果需要添加新模块的头文件
// 直接添加到__includes__.h

#define __FRAME_INIT_DEBUG_INFO__

namespace QIU {
namespace PJ0 {

#ifdef __FRAME_INIT_DEBUG_INFO__
s8 frame_debuf_buffer[32];
#endif // __FRAME_INIT_DEBUG_INFO__
/**
 * 这个函数主要用于当初始化完成之后，
 * 屏幕上面的信息。
 * 按照网格来算，屏幕一共是30行(480/16)(0~29)40列(320/8)(0~39)
 */
inline void __print_basic__(void) {
	u16 bcolor = GUI_COLOR_000;
	u16 fcolor = GUI_COLOR_CCC;
	char * initinfo [30];
	s8 p = 0;
	// 0
	*(initinfo + p++) = "*======================================*\0";
	*(initinfo + p++) = "* Project Name: Q20161106_Project0     *\0";
	*(initinfo + p++) = "* Author:                              *\0";
	*(initinfo + p++) = "*    QIU1995NONAME <qmh1995@163.com>   *\0";
	*(initinfo + p++) = "*    FengQi SUN    <578478754@qq.com>  *\0";
	// 5
	*(initinfo + p++) = "* URL:                                 *\0";
	*(initinfo + p++) = "*   https://github.com/QIU1995NONAME   *\0";
	*(initinfo + p++) = "*     /Q20161106_Project0              *\0";
	*(initinfo + p++) = "* LICENSE: The MIT License.            *\0";
	*(initinfo + p++) = "*======================================*\0";
	// 10
	*(initinfo + p++) = "Current Time : ????????????????         \0"; // 10,15  实时时钟
	*(initinfo + p++) = "Current System Status :                 \0";
	*(initinfo + p++) = " SD Card   Enabled     :    [ ??? ]     \0"; // 12,30 SD卡是否可用
	*(initinfo + p++) = " Sampling  Enabled     :    [ ??? ]     \0"; // 13,30 底层采样是否启动
	*(initinfo + p++) = " HeartBeat Enabled     :    [ ??? ]     \0"; // 14,30 心跳是否在维持
	// 15
	*(initinfo + p++) = " Sampling Buffer Max   :    [ 512 ]     \0";
	*(initinfo + p++) = " Sampling Buffer Limit :    [ 500 ]     \0";
	*(initinfo + p++) = " Sampling Buffer Used  :    [ ??? ]     \0";// 17,30 采样缓冲区使用了多少
	*(initinfo + p++) = "                                        \0";
	*(initinfo + p++) = "Current Value:                          \0";
	// 20
	*(initinfo + p++) = " OE Encoder Pulse : ?                   \0";// 20,20 当前光电编码器的脉冲数
	*(initinfo + p++) = " OE Encoder Angle : ?                   \0";// 21,20 当前光电编码器的角度
	*(initinfo + p++) = " Fan Level        : ?                   \0";// 22,20 风扇转速值
	*(initinfo + p++) = " Fan Level %      : ?                   \0";// 23,20 风扇转速百分比
	*(initinfo + p++) = " StepMotor Step   : ?                   \0";// 24,20 步进电机当前步数
	// 25
	*(initinfo + p++) = " StepMotor Angle  : ?                   \0";// 25,20 步进电机当前角度
	*(initinfo + p++) = "                                        \0";
	*(initinfo + p++) = "                                        \0";
	*(initinfo + p++) = "                                        \0";
	*(initinfo + p++) = "                                        \0";
	for (p = 0; p < 30; p++) {
		gui_inner_char_align(p, 0, (s8*)(*(initinfo + p)), fcolor, bcolor);
	}
	//

}
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
	if (sampling_init()) {
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
	if(controller_init()){
#ifdef __FRAME_INIT_DEBUG_INFO__
		gui_print_inner_char((s8*) "Controller ERROR!", GUI_COLOR_F00,
		GUI_COLOR_444);
		gui_print_next_line();
#endif // __FRAME_INIT_DEBUG_INFO__
		while (1) {
		}
	}
	// ==============================================================================
	led_init();
	key_init();
	e6a2_reset();
	fan_init();
	tb6560_init();
	// 把调试信息清空
	gui_clear_screen();
	__print_basic__();
	// ==============================================================================
	// 一定是最后初始化计划任务！
	__task_init__(); //last
}
// 毕竟主循环,里面的函数没有绝对的先后顺序关系。
// 或许以后可以在这里面设置优先级的关系
extern void __frame_3_main_loop__(void) {
	manager_main_loop_function();
	sampling_main_loop_function();
	tim6_heartbeat_main_loop_function();
}

}
}
