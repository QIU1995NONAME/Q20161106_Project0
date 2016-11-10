#include "rtc.h"

namespace QIU {
namespace PJ0 {
#define CODE_RTC_INITED  ((uint16_t) (0x55AA))
/**
 * 向RTC的计数器写入数值
 */
extern void rtc_set_counter(u32 num) {
	RTC_SetCounter(num);
	// 等待最后一次对RTC操作的完成
	RTC_WaitForLastTask();
}
/**
 * RTC 配置
 */
extern void rtc_config(void) {
	// 启动电源时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
	// 启动备用寄存器时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP, ENABLE);
	// 启动RTC与后备寄存器的访问
	PWR_BackupAccessCmd(ENABLE);
	// 通过验证寄存器中的值判断是否经过了初始化配置
	if (BKP_ReadBackupRegister(BKP_DR3) != CODE_RTC_INITED) {
		// 强制初始化
		rtc_init();
		// 等待最后一次对RTC操作的完成
		RTC_WaitForLastTask();
		// 写入成功初始化的数值
		BKP_WriteBackupRegister(BKP_DR3, CODE_RTC_INITED);
	} else {
		// 等待RTC寄存器同步
		RTC_WaitForSynchro();
		// 等待最后一次对RTC操作的完成
		RTC_WaitForLastTask();
	}
}
/**
 * RTC 强制初始化
 * 如果此部分已经被初始化，则正常的配置程序会跳过此函数
 * 如果未被初始化，则正常的配置程序会自动执行此函数
 */
extern void rtc_init(void) {
	// 启动电源时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
	// 启动备用寄存器时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP, ENABLE);
	// 启动RTC与后备寄存器的访问
	PWR_BackupAccessCmd(ENABLE);
	// 将BKP全部寄存器全都设为默认
	BKP_DeInit();
	// 启动外设低速晶振
	RCC_LSEConfig(RCC_LSE_ON);
	// 等待外部低速晶振起振
	while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET) {
		// DO NOTHING
	}
	// 设置RTC的时钟源为LSE
	RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
	// 启动RTC时钟
	RCC_RTCCLKCmd(ENABLE);
	// 等待同步
	RTC_WaitForSynchro();
	// 等待最后一次对RTC操作的完成
	RTC_WaitForLastTask();
	// 设置预分频
	RTC_SetPrescaler(32767);
	// 等待最后一次对RTC操作的完成
	RTC_WaitForLastTask();
}

}
}


