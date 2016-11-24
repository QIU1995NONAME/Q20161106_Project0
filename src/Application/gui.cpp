#include "gui.h"

#define __NEED_ASCII__
#include "ascii_code.h"

namespace QIU {
namespace PJ0 {
#define GUI_MAX_LINE  ((u16) (((TFT_MAX_ROW + 1) >> 4) - 1))
#define GUI_MAX_CHAR  ((u16) (((TFT_MAX_COL + 1) >> 3) - 1))
// 用于屏幕显示字符的小玩意
u16 gui_current_line = 0;
u16 gui_current_char = 0;
extern u8 gui_check_point(u16 x, u16 y) {
	return (x <= TFT_MAX_COL && y <= TFT_MAX_ROW) ? 1 : 0;
}
extern void gui_dot(u16 x, u16 y, u16 color) {
	if (!gui_check_point(x, y)) {
		return;
	}
	TFT_SetArea(x, x, y, y);
	TFT_WriteDat(color);
	TFT_Cmd_00_NOP();
}
extern void gui_line(u16 x1, u16 y1, u16 x2, u16 y2, u16 color) {
	if (!gui_check_point(x1, y1)) {
		return;
	}
	if (!gui_check_point(x2, y2)) {
		return;
	}
	// x y 增量方向
	s8 dx = 0;
	s8 dy = 0;
	// x y 增量
	s32 delta_x = x2 - x1;
	s32 delta_y = y2 - y1;
	// 矫正方向
	if (delta_x < 0) {
		dx = -1;
		delta_x = -delta_x;
	} else if (delta_x > 0) {
		dx = 1;
	} else {
		dx = 0;
	}
	if (delta_y < 0) {
		dy = -1;
		delta_y = -delta_y;
	} else if (delta_y > 0) {
		dy = 1;
	} else {
		dy = 0;
	}
	// 确定方向
	s32 distance = (delta_x > delta_y) ? delta_x : delta_y;
	// X,Y需要按照比例增加，定义增量系数
	s32 x_error = 0;
	s32 y_error = 0;
	for (s32 i = 0; i < distance + 2; i++) {
		gui_dot(x1, y1, color);
		x_error += delta_x;
		y_error += delta_y;
		if (x_error > distance) {
			x_error -= distance;
			x1 += dx;
		}
		if (y_error > distance) {
			y_error -= distance;
			y1 += dy;
		}
	}
}

extern void gui_area(u16 x1, u16 y1, u16 x2, u16 y2, u16 color) {
	if (!gui_check_point(x1, y1)) {
		return;
	}
	if (!gui_check_point(x2, y2)) {
		return;
	}
	u16 tmp;
	if (x1 > x2) {
		tmp = x2;
		x2 = x1;
		x1 = tmp;
	}
	if (y1 > y2) {
		tmp = y2;
		y2 = y1;
		y1 = tmp;
	}
	TFT_SetArea(x1, x2, y1, y2);
	// 这么写更省存储空间 虽然看上去真的很不适应
	x1 = x2 - x1 + 1;
	y1 = y2 - y1 + 1;
	while (x1--) {
		tmp = y1;
		while (tmp--) {
			TFT_WriteDat(color);
		}
	}
	TFT_Cmd_00_NOP();
}

// 画一个十字标记
extern void gui_sign(u16 x, u16 y, u16 color) {
	if (!gui_check_point(x, y)) {
		return;
	}
	//标记的中心区域
	TFT_SetArea(x - 1, x + 1, y - 1, y + 1);
	for (u8 i = 0; i < 9; i++) {
		TFT_WriteDat(color);
	}
	TFT_SetArea(x - 4, x + 4, y, y);

	for (u8 i = 0; i < 9; i++) {
		TFT_WriteDat(color);
	}
	TFT_SetArea(x, x, y - 4, y + 4);

	for (u8 i = 0; i < 9; i++) {
		TFT_WriteDat(color);
	}
}
// 通过内部的字库(头文件)显示字符 任意位置
extern void gui_inner_char(u16 x, u16 y, s8* str, u16 color, u16 bcolor) {
	while (*str != 0) {
		// 字的序号
		s32 ch = *str - 32;
		// 判断是否存在
		ch = ch >= 00 ? ch : 0;
		ch = ch <= 96 ? ch : 0;
		// 字的位置
		TFT_SetArea(x, x + 7, y, y + 15);
		// 每个字符16字节
		for (u8 i = 0; i < 16; i++) {
			u8 ch_code = ASCII8x16[ch][i];
			for (u8 j = 0; j < 8; j++) {
				if (ch_code & 0x80) {
					TFT_WriteDat(color);
				} else {
					TFT_WriteDat(bcolor);
				}
				ch_code <<= 1;
			}
		}
		TFT_Cmd_00_NOP();
		// 抬走！下一个！
		str++;
		// 切换坐标
		x += 8;
		if (x > TFT_MAX_COL - 7) {
			x = 0;
			y += 16;
		}
	}
}
// 通过内部的字库(头文件)显示字符 内部自动计算位置
extern void gui_print_inner_char(s8* str, u16 color, u16 bcolor) {
	u16 x, y;
	while (*str != 0) {
		y = gui_current_line << 4;
		x = gui_current_char << 3;
		// 字的序号
		s32 ch = *str - 32;
		// 判断是否存在
		ch = ch >= 00 ? ch : 0;
		ch = ch <= 96 ? ch : 0;
		// 字的位置
		TFT_SetArea(x, x + 7, y, y + 15);
		// 每个字符16字节
		for (u8 i = 0; i < 16; i++) {
			u8 ch_code = ASCII8x16[ch][i];
			for (u8 j = 0; j < 8; j++) {
				if (ch_code & 0x80) {
					TFT_WriteDat(color);
				} else {
					TFT_WriteDat(bcolor);
				}
				ch_code <<= 1;
			}
		}
		TFT_Cmd_00_NOP();
		// 抬走！下一个！
		str++;
		// 切换坐标
		gui_current_char++;
		if (gui_current_char > GUI_MAX_CHAR) {
			gui_current_char = 0;
			gui_current_line++;
		}
	}
}
extern void gui_print_next_line(void) {
	gui_current_line++;
	gui_current_char = 0;
}
extern void gui_clear_line(u16 color) {
	gui_area(0, (gui_current_line << 4), TFT_MAX_COL,
			(gui_current_line << 4) + 15, color);
	gui_current_char = 0;
}
extern void gui_clear_screen(void) {
	TFT_ClearScreen(GUI_COLOR_000);
	gui_current_line = 0;
	gui_current_char = 0;
}
extern void gui_init(void) {
	gui_clear_screen();
}

}
}

