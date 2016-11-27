#include "controller_private.h"
#include "memory.h"
#include "tim6heartbeat.h"

namespace QIU {
namespace PJ0 {

void * controller_buffer_1k = 0;
s16 controller_project = 0;
s16 controller_mode = 0;

/**
 * 定时20ms执行的函数，用来进行控制
 * 挂在定时系统上面的，不可以直接调用
 */
extern void controller_task_20ms(void) {
	//上一个循环的工程号
	static s16 last_project = 0;
	//上一个循环的模式
	static s16 last_mode = 0;
	// 如果工程变动
	if (last_project != controller_project) {
		// 需要进行工程初始化，然后退出
		/*
		 * TODO 进行工程初始化
		 */
		// 记录变动
		last_project = controller_project;
		// 工程模式置0
		controller_mode = 0;
		return;
	}
	// 如果工程没有变动，而模式发生改变
	if (last_mode != controller_mode) {
		// 进行模式调节
		/*
		 * TODO 进行模式调节
		 */
		// 记录变动
		last_mode != controller_mode;
		return;
	}
	// 都没有变化，继续进行当前项目的当前模式
	switch (last_project) {
	case 0x01:
		break;
	case 0x02:
		break;
	default:
		break;
	}
}

/**
 * 强制初始化
 * @return 0 代表成功
 */
extern s8 controller_init_0(void) {
	if (controller_buffer_1k) {
		memory_free(controller_buffer_1k);
		controller_buffer_1k = 0;
	}
	void * p = memory_alloc0_1k();
	if (p == 0) {
		return 0xFF; // 内存不足
	}
	controller_buffer_1k = p;
	tim6_heartbeat_del_event(0x04);
	tim6_heartbeat_add_event(0x04, controller_task_20ms, 20);
	return 0;
}

}
}
