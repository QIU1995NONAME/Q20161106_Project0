#include "controller_private.h"
#include "memory.h"

namespace QIU {
namespace PJ0 {

extern s8 controller_get_int(u8 index, int * value) {
	if (!controller_parambuf_2k) {
		return 0xFF; // 缓冲不可用
	}
	if (!value) {
		return 0xFE; // NULL指针
	}
	if (index >= CTRL_PARAMBUF_INT_LENGTH) {
		return 0x7F; // 下标超限
	}
	*value = *(CTRL_BUF_INT + index);
	return 0;
}
extern s8 controller_get_double(u8 index, double * value) {
	if (!controller_parambuf_2k) {
		return 0xFF; // 缓冲不可用
	}
	if (!value) {
		return 0xFE; // NULL指针
	}
	if (index >= CTRL_PARAMBUF_DBL_LENGTH) {
		return 0x7F; // 下标超限
	}
	*value = *(CTRL_BUF_DBL + index);
	return 0;
}
extern s8 controller_set_int(u8 index, int value) {
	if (!controller_get_rw_int(index)) {
		return 0x10; // 权限不足
	}
	return controller_set_0_int(index, value);
}
extern s8 controller_set_double(u8 index, double value) {
	if (!controller_get_rw_double(index)) {
		return 0x10; // 权限不足
	}
	return controller_set_0_double(index, value);
}
/**
 * 设置当前的工程代号
 * @param project 工程代号
 */
extern void controller_set_project(s8 project) {
	// TODO 暂时不写更多的优化
	controller_project = project;
}
/**
 * 设置当前的模式
 * @param mode 模式
 */
extern void controller_set_mode(s8 mode) {
	// TODO 暂时不写更多的优化
	controller_mode = mode;
}
/**
 * 获取当前工程代号
 * @return 工程代号
 */
extern s8 controller_get_project(void) {
	return controller_project;
}
/**
 * 获取当前模式号
 * @return 模式号
 */
extern s8 controller_get_mode(void) {
	return controller_mode;
}
/**
 * 控制器初始化
 * @return 状态值 0为成功
 */
extern s8 controller_init(void) {
	if (!controller_parambuf_2k) {
		return controller_init_0();
	}
	return 0;
}

}
}
