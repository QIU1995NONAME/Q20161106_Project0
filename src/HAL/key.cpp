#include "key.h"
#include "systick.h"

namespace QIU {
namespace PJ0 {

extern s8 key_init(void) {
	return 0;
}
//这个系列是经过消抖处理的读取按键值 但是每一个函数都会延时10ms
extern s8 key_delay_up(void) {
	if (key_raw_up()) {
		delay_ms(10);
		if (key_raw_up()) {
			return 1;
		}
	}
	return 0;
}
//这个系列是经过消抖处理的读取按键值 但是每一个函数都会延时10ms
extern s8 key_delay_left(void) {
	if (key_raw_left()) {
		delay_ms(10);
		if (key_raw_left()) {
			return 1;
		}
	}
	return 0;
}
//这个系列是经过消抖处理的读取按键值 但是每一个函数都会延时10ms
extern s8 key_delay_down(void) {
	if (key_raw_down()) {
		delay_ms(10);
		if (key_raw_down()) {
			return 1;
		}
	}
	return 0;
}
//这个系列是经过消抖处理的读取按键值 但是每一个函数都会延时10ms
extern s8 key_delay_right(void) {
	if (key_raw_right()) {
		delay_ms(10);
		if (key_raw_right()) {
			return 1;
		}
	}
	return 0;
}

}
}
