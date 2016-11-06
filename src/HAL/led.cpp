#include "led.h"

namespace QIU{
namespace PJ0{

extern void led_display(u8 num){
	GPIO_Write(GPIOC,0xFF & ~(num));
}
extern void led_init(void){
	led_display(0x00);
}

}
}

