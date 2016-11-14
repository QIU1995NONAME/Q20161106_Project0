#include "__frame_task__.h"
#include "__includes__.h"
// FIXME 我感觉这个文件中的代码还会被我重构
// 无法避免 迟早要这么做的
namespace QIU {
namespace PJ0 {

//void __task_0_scan_key__(void) {
//	if (flag_led) {
//		led_display(0x80);
//		flag_led = 0;
//	} else {
//		led_display(0x00);
//		flag_led = 1;
//	}
//	s8 buf[128];
//	misc_int2string(buf, e6a2_read());
//	gui_inner_char(0, 0, buf, misc_color24to16(64, 64, 64),
//			misc_color24to16(255, 255, 128));
//}
// 计划任务2 10ms 刷新屏幕上面的数字
//void __task_2__(void) {
//	static s16 argument = 0;
//	static u8 direction = 1;
//	s8 buf[128];
////	beep_set_pitch(argument);
//	fan_set_level(argument);
//	misc_int2string(buf, argument);
//	gui_print_inner_char(0, 16, buf, misc_color24to16(128, 128, 255),
//			misc_color24to16(64, 96, 64));
//	if (direction == 1) {
//		argument += 3;
//		if (argument >= 1199) {
//			direction = 0;
//		}
//	} else {
//		argument -= 3;
//		if (argument <= 300) {
//			direction = 1;
//		}
//	}
//}
// 计划任务3 10ms 调试 定时器时间轴
//void __task_3__(void) {
//	s8 buf[128];
//	misc_int2string(buf, t6_timestamp_l32);
//	gui_print_inner_char(0, 32, buf, misc_color24to16(64, 64, 64),
//			misc_color24to16(128, 255, 128));
//	for (u8 i = 0; i < 16; i++) {
//		misc_int2string(buf, *(t6_event_time_count + i));
//		gui_print_inner_char(0, (i + 3) * 16, buf, misc_color24to16(128, 255, 128),
//				misc_color24to16(64, 64, 64));
//	}
//}
//void __task_test_touch__(void) {
//	u16 x;
//	u16 y;
//	s8 buf[128];
//	x = touch_is_touched();
//	misc_int2string_a(buf, 1000 + x);
//	gui_print_inner_char(0, 200, buf, misc_color24to16(64, 64, 64),
//			misc_color24to16(128, 255, 128));
//	touch_read_point(&x, &y);
//	misc_int2string_a(buf, x);
//	gui_print_inner_char(0, 216, buf, misc_color24to16(64, 64, 64),
//			misc_color24to16(128, 255, 128));
//	misc_int2string_a(buf, y);
//	gui_print_inner_char(0, 232, buf, misc_color24to16(64, 64, 64),
//			misc_color24to16(128, 255, 128));

//}
//u16 level = 0;
//s8 forward = 0;
//s8 buf[64];
//void __task_2__(void) {
//	misc_int2string_a(buf, e6a2_read());
//	gui_inner_char(0, 0, buf, GUI_COLOR_CCC, GUI_COLOR_000);
//	misc_int2string_a(buf, GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6));
//	gui_inner_char(0, 16, buf, GUI_COLOR_CCC, GUI_COLOR_000);
//}
//void __task_1_test_beep__(void) {
//	if (key_down_listen(SIGNAL_SYS)) {
//		forward = 0;
//	}
//	if (key_left_listen(SIGNAL_SYS)) {
//		forward = 1;
//	}
//	if (key_right_listen(SIGNAL_SYS)) {
//		forward = -1;
//	}
//	if (forward > 0) {
//		level++;
//	} else if (forward < 0) {
//		level--;
//	}
//	beep_set_level(20);
//	beep_set_pitch(level);
//	misc_int2string(buf, level);
//	gui_clear_line(GUI_COLOR_000);
//	gui_print_inner_char(buf, GUI_COLOR_0F0, GUI_COLOR_444);
//	level++;
//}
//BNote * note_array = 0;
//inline void __task_test_beep_init__(void) {
//	note_array = (BNote*) memory_alloc0_4k();
//	s16 pointer = 0;
//	// u8 level1 = 4;
//	u8 level2 = 8;
//	// 开头空余
//	BNote * note = note_array + pointer++;
//	note->note_pitch = 0;
//	note->note_level = 0;
//	note->note_ticks = 8 * 8;
//	note->note_ticks_avail = 0;
//
//	// XXX NOTE  2-6-6-65
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 4 + BEEP_PITCH_D;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_A;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_A;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_A;
//	note->note_level = level2;
//	note->note_ticks = 4; // 0.5
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 4; // 0.5
//	note->note_ticks_avail = 16;
//
//	// XXX NOTE 6---4561
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_A;
//	note->note_level = level2;
//	note->note_ticks = 16; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_F;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_A;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 4 + BEEP_PITCH_C;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//
//	// XXX NOTE  2-6-6-65
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 4 + BEEP_PITCH_D;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_A;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_A;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_A;
//	note->note_level = level2;
//	note->note_ticks = 4; // 0.5
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 4; // 0.5
//	note->note_ticks_avail = 16;
//
//	// XXX NOTE 4---4561
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_F;
//	note->note_level = level2;
//	note->note_ticks = 16; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_F;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_A;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 4 + BEEP_PITCH_C;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//
//	// XXX NOTE  5-5-5-54
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 4; // 0.5
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_F;
//	note->note_level = level2;
//	note->note_ticks = 4; // 0.5
//	note->note_ticks_avail = 16;
//
//	// XXX NOTE 5---3451
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 16; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_E;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_F;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 4 + BEEP_PITCH_C;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//
//	// XXX NOTE 656-4-6-
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_A;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_A;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 4 + BEEP_PITCH_F;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_A;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//
//	// XXX NOTE 545-3-1-
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_F;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 4 + BEEP_PITCH_E;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 4 + BEEP_PITCH_C;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// XXX NOTE  2-6-6-65
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 4 + BEEP_PITCH_D;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_A;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_A;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_A;
//	note->note_level = level2;
//	note->note_ticks = 4; // 0.5
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 4; // 0.5
//	note->note_ticks_avail = 16;
//
//	// XXX NOTE 6---4561
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_A;
//	note->note_level = level2;
//	note->note_ticks = 16; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_F;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_A;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 4 + BEEP_PITCH_C;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//
//	// XXX NOTE  2-5-5-46
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 4 + BEEP_PITCH_D;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 8; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_F;
//	note->note_level = level2;
//	note->note_ticks = 4; // 0.5
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_A;
//	note->note_level = level2;
//	note->note_ticks = 4; // 0.5
//	note->note_ticks_avail = 16;
//
//	// XXX NOTE 5---3456
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 16; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_E;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_F;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_A;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//
//	// XXX NOTE  432---43
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_F;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_E;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_D;
//	note->note_level = level2;
//	note->note_ticks = 16; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_F;
//	note->note_level = level2;
//	note->note_ticks = 4; // 0.5
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_E;
//	note->note_level = level2;
//	note->note_ticks = 4; // 0.5
//	note->note_ticks_avail = 16;
//
//	// XXX NOTE 2---2345
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_D;
//	note->note_level = level2;
//	note->note_ticks = 16; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_D;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_E;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_F;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_G;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// XXX NOTE  321---32
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_E;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_D;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_C;
//	note->note_level = level2;
//	note->note_ticks = 16; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_E;
//	note->note_level = level2;
//	note->note_ticks = 4; // 0.5
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_D;
//	note->note_level = level2;
//	note->note_ticks = 4; // 0.5
//	note->note_ticks_avail = 16;
//
//	// XXX NOTE 1--23431
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_C;
//	note->note_level = level2;
//	note->note_ticks = 12; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_D;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_E;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_F;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_E;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// NOTE
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_C;
//	note->note_level = level2;
//	note->note_ticks = 4; // 1
//	note->note_ticks_avail = 16;
//	// XXX NOTE 2-------
//	note = note_array + pointer++;
//	note->note_pitch = BEEP_PITCH_12 * 3 + BEEP_PITCH_D;
//	note->note_level = level2;
//	note->note_ticks = 32; // 1
//	note->note_ticks_avail = 32;
//
//	// 开始播放
//	beep_play(note_array, pointer, BEEP_PLAY_SPEED_120);
//}
//s8 buffer[32];
//void __task_print_time_100ms__(void) {
//	misc_uint2timestring(buffer, rtc_get_counter());
//	gui_inner_char(0, 0, buffer, GUI_COLOR_CCC, GUI_COLOR_000);
//}
//void __task_test_tb6560__(void) {
//	s32 arg = e6a2_read();
//	arg >>= 2;
//	tb6560_set_stepcount(-arg);
//	misc_int2string(buffer, e6a2_read());
//	gui_inner_char(0, 16, buffer, GUI_COLOR_8F8, GUI_COLOR_444);
//	misc_int2string(buffer, tb6560_get_stepcount());
//	gui_inner_char(0, 32, buffer, GUI_COLOR_FF8, GUI_COLOR_444);
//}
extern void __task_init__(void) {
	u8 taskid = 0;
//	__task_test_beep_init__();
//	tim6_heartbeat_add_event(taskid++, beep_task_10ms, 10);
//	tim6_heartbeat_add_event(taskid++, __task_1_test_beep__, 1000);
//	tim6_heartbeat_add_event(taskid++, __task_print_time_100ms__, 100);
//	tim6_heartbeat_add_event(taskid++, __task_test_tb6560__, 10);
}

}
}

