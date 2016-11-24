#include "tb6560.h"
#include "systick.h"

namespace QIU {
namespace PJ0 {
// 当前步进电机的步数
s32 tb6560_stepcount = 0;
/**
 * 获取当前步进电机的步数
 * @return 当前的步数
 */
extern s32 tb6560_get_stepcount(void) {
	return tb6560_stepcount;
}
/**
 * 设置步进电机的步数
 * @param stepcount_set 设置的步数
 */
extern void tb6560_set_stepcount(s32 stepcount_set) {
	s32 changes = stepcount_set - tb6560_stepcount;
	changes < 0 ? tb6560_step(1, -changes) : tb6560_step(0, changes);
}
/**
 * 使电机转动
 * @param backward 如果为0正转 如果为1反转
 * @param stepcount 步数
 */
extern void tb6560_step(u8 backward, u32 stepcount) {
	backward ?
			GPIO_SetBits(GPIOA, GPIO_Pin_11) :
			GPIO_ResetBits(GPIOA, GPIO_Pin_11);
	GPIO_ResetBits(GPIOA, GPIO_Pin_12);
	while (stepcount--) {
		delay_ms(1);
		GPIO_SetBits(GPIOA, GPIO_Pin_12);
		delay_ms(1);
		GPIO_ResetBits(GPIOA, GPIO_Pin_12);
		backward ? tb6560_stepcount-- : tb6560_stepcount++;
	}
}
/**
 * 初始化
 */
extern void tb6560_init(void) {
	tb6560_enable();
	tb6560_stepcount = 0;
	tb6560_step(0, 0);
}

}
}

