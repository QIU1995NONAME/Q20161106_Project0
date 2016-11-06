#ifndef __GUI_H__
#define __GUI_H__

#include "stm32f10x.h"
#include "tft.h"
#include "q_misc.h"

namespace QIU {
namespace PJ0 {
/**
 * 系列颜色代码
 */
// 无色系列
#define GUI_COLOR_000 ((u16) (0x0000))
#define GUI_COLOR_444 ((u16) (0x4208))
#define GUI_COLOR_888 ((u16) (0x8410))
#define GUI_COLOR_CCC ((u16) (0xC618))
#define GUI_COLOR_FFF ((u16) (0xFFFF))
// 蓝色系列（暗纯亮）
#define GUI_COLOR_008 ((u16) (0x0010))
#define GUI_COLOR_00F ((u16) (0x001F))
#define GUI_COLOR_88F ((u16) (0x841F))
// 绿色系列（暗纯亮）
#define GUI_COLOR_080 ((u16) (0x0400))
#define GUI_COLOR_0F0 ((u16) (0x07E0))
#define GUI_COLOR_8F8 ((u16) (0x87F0))
// 红色系列（暗纯亮）
#define GUI_COLOR_800 ((u16) (0x8000))
#define GUI_COLOR_F00 ((u16) (0xF800))
#define GUI_COLOR_F88 ((u16) (0xFC10))
// 青色系列（暗纯亮）
#define GUI_COLOR_088 ((u16) (0x0410))
#define GUI_COLOR_0FF ((u16) (0x07FF))
#define GUI_COLOR_8FF ((u16) (0x87FF))
// 黄色系列（暗纯亮）
#define GUI_COLOR_880 ((u16) (0x8400))
#define GUI_COLOR_FF0 ((u16) (0xFFE0))
#define GUI_COLOR_FF8 ((u16) (0xFFF0))
// 品红系列（暗纯亮）
#define GUI_COLOR_808 ((u16) (0x8010))
#define GUI_COLOR_F0F ((u16) (0xF81F))
#define GUI_COLOR_F8F ((u16) (0xFC1F))

/**
 * 判断一个点是否合法
 */
extern u8 gui_check_point(u16 x, u16 y);

/**
 * 在X,Y位置上画一个点
 */
extern void gui_dot(u16 x, u16 y, u16 color);

/**
 * 从(x1, y1)到(x2, y2)画一条线
 */
extern void gui_line(u16 x1, u16 y1, u16 x2, u16 y2, u16 color);

/**
 * 画一个矩形。(x1, y1)和(x2, y2)是一组对角坐标
 */
extern void gui_area(u16 x1, u16 y1, u16 x2, u16 y2, u16 color);

/**
 * 画一个十字标记
 */
extern void gui_sign(u16 x, u16 y, u16 color);

/**
 * 以任意位置为左上角通过内部的字库显示一段信息
 */
extern void gui_inner_char(u16 x, u16 y, s8* str, u16 color, u16 bcolor);

/**
 * 在GUI内部规定的位置通过内部的字库显示一段信息
 */
extern void gui_print_inner_char(s8* str, u16 color, u16 bcolor);

/**
 * 打印换行
 */
extern void gui_print_next_line(void);

/**
 * 清空当前行，并把光标放到开头
 */
extern void gui_clear_line(u16 color);

/**
 * 清屏，并把下一个要打印的字符放到左上角
 */
extern void gui_clear_screen(void);

/**
 * 屏幕初始化
 */
extern void gui_init(void);

}
}

#endif // __GUI_H__
