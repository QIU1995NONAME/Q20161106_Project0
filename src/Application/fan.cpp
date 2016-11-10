#include "fan.h"

namespace QIU {
namespace PJ0 {

#define FAN_MAX_LEVEL (1800 - 1)

extern void fan_set_level(u16 level) {
	// TIM4 Channel3 PB8
	level = level > FAN_MAX_LEVEL ? FAN_MAX_LEVEL : level;
	TIM_SetCompare3(TIM4, level);
}
extern void fan_init(void) {
	fan_set_level(0);
}

}
}
