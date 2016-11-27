#include "controller_private.cpp"
#include "memory.h"

namespace QIU {
namespace PJ0 {

/**
 * 设置当前的工程代号
 * @param project 工程代号
 */
extern void controller_set_project(s8 project) {
	// TODO
}

/**
 * 获取当前工程代号
 * @return 工程代号
 */
extern s8 controller_get_project(void) {
	return controller_project;
}

/**
 * 控制器初始化
 * @return 状态值 0为成功
 */
extern s8 controller_init(void) {
	if (!controller_buffer_1k) {
		return controller_init_0();
	}
	return 0;
}

}
}
