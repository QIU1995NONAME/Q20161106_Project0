#include "stm32f10x.h"
#define __QIU_PJ0_NEED_FRAME__
#include "__frame__.h"

int main(void) {
	SystemInit();
	QIU::PJ0::__frame_1_hal_config__();
	QIU::PJ0::__frame_2_app_init__();
	while (1) {
		QIU::PJ0::__frame_3_main_loop__();
	}
}
