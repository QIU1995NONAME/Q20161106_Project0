#include "controller_private.h"
#include "e6a2.h"
#include "fan.h"

#define CONTROLLER_PROJECT_1

namespace QIU {
namespace PJ0 {

// 风扇帆板
// INT  0 风扇转速等级设定值
// INT  1 帆板角度步数设定值
// DBL  0 P
// DBL  1 I
// DBL  2 D
// DBL 64 累计积分值
// DBL 65 上一次的偏差
extern void controller_1_task(s8 mode) {
	static s8 last_mode = -1;
	switch (mode) {
	case 0x01:
		if (last_mode != mode) {
			last_mode = mode;
			// 切换到自动
			controller_set_rw_int(0, 0);
			controller_set_rw_int(1, 1);
			controller_set_0_double(64, 0);
			controller_set_0_double(65, 0);
		}
		// 自动控制
		int ctrl_target_angle_pulse;
		controller_get_int(1, &ctrl_target_angle_pulse);
		int ctrl_current_angle_pulse = e6a2_read();
		// 偏差为 当前值 - 设定值
		double ctrl_error = ctrl_current_angle_pulse - ctrl_target_angle_pulse;
		// 获取PID
		int ctrl_target_fan_level = 0;
		double ctrl_KP, ctrl_KI, ctrl_KD;
		double ctrl_current_I, ctrl_last_error;
		controller_get_double(0, &ctrl_KP);
		controller_get_double(1, &ctrl_KI);
		controller_get_double(2, &ctrl_KD);
		controller_get_double(64, &ctrl_current_I);
		controller_get_double(65, &ctrl_last_error);
		// 偏差计入积分
		ctrl_current_I += ctrl_error;
		// 控制
		ctrl_target_fan_level = ctrl_KP
				* (ctrl_error + ctrl_KI * ctrl_current_I * 0.02
						+ ctrl_KD * (ctrl_error - ctrl_last_error) / 0.02);
		// 保存当前偏差为下一次的上次偏差
		ctrl_last_error = ctrl_error;
		// 保存
		controller_set_0_double(64,ctrl_current_I);
		controller_set_0_double(65,ctrl_last_error);
		// 写入控制参数
		controller_set_0_int(0,ctrl_target_fan_level);
		fan_set_level(ctrl_target_fan_level);
		break;
	case 0x00:
	default:
		if (last_mode != mode) {
			last_mode = mode;
			// 切换到手动
			controller_set_rw_int(0, 1);
			controller_set_rw_int(1, 0);
			controller_set_0_double(64, 0);
			controller_set_0_double(65, 0);
		}
		// 手动控制
		// 直接把风扇的转速置为传入的值
		int level = 0;
		controller_get_int(0, &level);
		fan_set_level(level);
		break;
	}
}

extern s8 controller_1_init(void) {
	controller_set_rw_int(0, 0);
	controller_set_rw_int(1, 0);
	controller_set_rw_double(0, 1);
	controller_set_rw_double(1, 1);
	controller_set_rw_double(2, 1);
	controller_set_rw_double(64, 0);
	controller_set_rw_double(65, 0);
	controller_set_0_double(64, 0);
	controller_set_0_double(65, 0);
	return 0;
}

}
}
