#include "__manager__.h"
#include "__includes__.h"
namespace QIU {
namespace PJ0 {
// 用于处理数据用的缓冲区
u8* manager_cmd_r_buffer_1k = 0;
u8* manager_cmd_s_buffer_1k = 0;
// 心跳计数
s8 manager_heartbeat_count = 0;
// 心跳功能 1S刷新一次
void manager_heartbeat_task_1000ms(void) {
	if (manager_heartbeat_count > 0) {
		manager_heartbeat_count--;
		// 发送心跳回应
		*manager_cmd_s_buffer_1k = 0x77;
		u32 t_s = t6_timestamp_s;
		u16 t_ms = t6_timestamp_ms;
		*(manager_cmd_s_buffer_1k + 1) = 0xFF & (t_s);
		*(manager_cmd_s_buffer_1k + 2) = 0xFF & (t_s >> 8);
		*(manager_cmd_s_buffer_1k + 3) = 0xFF & (t_s >> 16);
		*(manager_cmd_s_buffer_1k + 4) = 0xFF & (t_s >> 24);
		*(manager_cmd_s_buffer_1k + 5) = 0xFF & (t_ms);
		*(manager_cmd_s_buffer_1k + 6) = 0xFF & (t_ms >> 8);
		cmd_buffer_send_data(manager_cmd_s_buffer_1k, 7);
	}
}
/**
 * 管理器主循环
 * 除了主循环以外不得被任何其他方式调用
 */
extern void manager_main_loop_function(void) {
	static s16 st_res;
	//尝试接收命令
	st_res = cmd_buffer_analyze_data(manager_cmd_r_buffer_1k);
	do {
		// 如果没有接收到数据
		if (st_res == 0) {
			break;
		}
		// 如果数据有问题
		if (st_res < 0) {
			// FIXME 没有处理过程
			break;
		}
		// 如果接收到了数据
		switch (*(manager_cmd_r_buffer_1k)) {
		// XXX 0x77
		case 0x77:
			manager_heartbeat_count = 7;
			break;
		default:
			// 未知指令
			;
		}
	} while (0);
}
/**
 * 管理器初始化
 * 一旦初始化失败应当立刻进入死循环。
 * @return 0 初始化成功
 *         否则初始化失败
 */
extern s8 manager_init(void) {
	manager_cmd_r_buffer_1k = (u8*) memory_alloc_1k();
	if (!manager_cmd_r_buffer_1k) {
		return -1;
	}
	manager_cmd_s_buffer_1k = (u8*) memory_alloc_1k();
	if (!manager_cmd_s_buffer_1k) {
		return -1;
	}
	// 初始化心跳
	manager_heartbeat_count = 0;
	tim6_heartbeat_add_event(0x00, manager_heartbeat_task_1000ms, 1000);

	// TODO 其他初始化任务
	return 0;
}
}
}
