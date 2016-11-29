#include "controller_private.h"
#include "memory.h"
#include "tim6heartbeat.h"

namespace QIU {
namespace PJ0 {

void * controller_parambuf_2k = 0;
int * controller_parambuf_int = 0;
double * controller_parambuf_double = 0;
s8 controller_project = 0;
s8 controller_mode = 0;
/// 变量权限初始化
extern s8 controller_rw_reset(void) {
	for (u8 i = 0; i < 30; i++) {
		*(CTRL_BUF_INT_RW + i) = 0;
	}
	for (u8 i = 0; i < 16; i++) {
		*(CTRL_BUF_DBL_RW + i) = 0;
	}
	return 0;
}
/// 获取变量是否可写
extern s8 controller_get_rw_int(u8 index) {
	if (!controller_parambuf_2k) {
		return 0;
	}
	if (index >= CTRL_PARAMBUF_INT_LENGTH) {
		return 0;
	}
	u8 byte0 = index >> 3;
	u8 bit0 = index & 0x07;
	return ((*(CTRL_BUF_INT_RW + byte0)) & (1 << bit0)) ? 1 : 0;
}
/// 设置变量是否可写
extern s8 controller_set_rw_int(u8 index, s8 rw) {
	if (!controller_parambuf_2k) {
		return -1;
	}
	if (index >= CTRL_PARAMBUF_INT_LENGTH) {
		return -1;
	}
	u8 byte0 = index >> 3;
	u8 bit0 = index & 0x07;
	if (rw) {
		*(CTRL_BUF_INT_RW + byte0) |= (1 << bit0);
	} else {
		*(CTRL_BUF_INT_RW + byte0) &= ~(1 << bit0);
	}
	return 0;
}
/// 获取变量是否可写
extern s8 controller_get_rw_double(u8 index) {
	if (!controller_parambuf_2k) {
		return 0;
	}
	if (index >= CTRL_PARAMBUF_DBL_LENGTH) {
		return 0;
	}
	u8 byte0 = index >> 3;
	u8 bit0 = index & 0x07;
	return ((*(CTRL_BUF_DBL_RW + byte0)) & (1 << bit0)) ? 1 : 0;
}
/// 设置变量是否可写
extern s8 controller_set_rw_double(u8 index, s8 rw) {
	if (!controller_parambuf_2k) {
		return -1;
	}
	if (index >= CTRL_PARAMBUF_DBL_LENGTH) {
		return -1;
	}
	u8 byte0 = index >> 3;
	u8 bit0 = index & 0x07;
	if (rw) {
		*(CTRL_BUF_DBL_RW + byte0) |= (1 << bit0);
	} else {
		*(CTRL_BUF_DBL_RW + byte0) &= ~(1 << bit0);
	}
	return 0;
}
/// 强制变量设定
extern s8 controller_set_0_int(u8 index, int value) {
	if (!controller_parambuf_2k) {
		return 0xFF; // 缓冲不可用
	}
	if (index >= CTRL_PARAMBUF_INT_LENGTH) {
		return 0x7F; // 下标超限
	}
	*(CTRL_BUF_INT + index) = value;
	return 0;
}
/// 强制变量设定
extern s8 controller_set_0_double(u8 index, double value) {
	if (!controller_parambuf_2k) {
		return 0xFF; // 缓冲不可用
	}
	if (index >= CTRL_PARAMBUF_DBL_LENGTH) {
		return 0x7F; // 下标超限
	}
	*(CTRL_BUF_DBL + index) = value;
	return 0;
}

/**
 * 定时20ms执行的函数，用来进行控制
 * 挂在定时系统上面的，不可以直接调用
 */
extern void controller_task_20ms(void) {
	//上一个循环的工程号
	static s8 last_project = -1;
	// 如果工程变动
	if (last_project != controller_project) {
		// 需要进行工程初始化，然后退出
		switch (controller_project) {
		case 0x00:
			controller_0_init();
			break;
		case 0x01:
			controller_1_init();
			break;
		case 0x02:
			controller_2_init();
			break;
		default:
			controller_0_init();
			break;
		}
		// 记录变动
		last_project = controller_project;
		// 模式初始化
		controller_mode = 0;
		return;
	}
	// 都没有变化，继续进行当前项目的当前模式
	switch (last_project) {
	case 0x00:
		controller_0_task(controller_mode);
		break;
	case 0x01:
		controller_1_task(controller_mode);
		break;
	case 0x02:
		controller_2_task(controller_mode);
		break;
	default:
		controller_0_task(controller_mode);
		break;
	}
}

/**
 * 强制初始化
 * @return 0 代表成功
 */
extern s8 controller_init_0(void) {
	if (controller_parambuf_2k) {
		memory_free(controller_parambuf_2k);
		controller_parambuf_2k = 0;
	}
	void * p = memory_alloc0_2k();
	if (p == 0) {
		return 0xFF; // 内存不足
	}
	controller_parambuf_2k = p;
	controller_project = 0;
	controller_mode = 0;
	controller_rw_reset();
	tim6_heartbeat_del_event(0x04);
	tim6_heartbeat_add_event(0x04, controller_task_20ms, 20);
	return 0;
}

}
}
