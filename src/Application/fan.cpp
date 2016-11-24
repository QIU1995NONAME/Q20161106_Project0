#include "fan.h"

namespace QIU {
namespace PJ0 {

u16 fan_level = 0;
extern u16 fan_get_level(void){
	return fan_level;
}
extern void fan_set_level(u16 level) {
	// TIM4 Channel3 PB8
	level = level > FAN_MAX_LEVEL ? FAN_MAX_LEVEL : level;
	fan_level = level;
	TIM_SetCompare3(TIM4, level);
}
extern void fan_init(void) {
	fan_set_level(0);
}

}
}
