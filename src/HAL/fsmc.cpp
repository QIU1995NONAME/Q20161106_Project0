#include "fsmc.h"

namespace QIU {
namespace PJ0 {

// 用于SRAM的FSMC接口初始化
inline void fsmc_config_1_3(void) {
	FSMC_NORSRAMInitTypeDef fsmc_norsram_init;
	FSMC_NORSRAMTimingInitTypeDef fsmc_norsram_timing_init;
	// 第一存储块 第三区
	fsmc_norsram_init.FSMC_Bank = FSMC_Bank1_NORSRAM3;
	// SRAM 模式
	fsmc_norsram_init.FSMC_MemoryType = FSMC_MemoryType_SRAM;
	// 数据宽度16位
	fsmc_norsram_init.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;
	// 写使能
	fsmc_norsram_init.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
	// 拓展模式失能 读写使用同样的时序
	fsmc_norsram_init.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable;
	// 地址和数据线复用 失能
	fsmc_norsram_init.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;

	fsmc_norsram_init.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
	fsmc_norsram_init.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
	fsmc_norsram_init.FSMC_AsynchronousWait = FSMC_AsynchronousWait_Disable;
	fsmc_norsram_init.FSMC_WrapMode = FSMC_WrapMode_Disable;
	fsmc_norsram_init.FSMC_WaitSignalActive =
	FSMC_WaitSignalActive_BeforeWaitState;
	fsmc_norsram_init.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
	fsmc_norsram_init.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
	// 设置读写时序
	fsmc_norsram_init.FSMC_ReadWriteTimingStruct = &fsmc_norsram_timing_init;
	// 设置写时序
	fsmc_norsram_init.FSMC_WriteTimingStruct = &fsmc_norsram_timing_init;
	// 设置读写时序
	// 地址建立时间, 3 个 HCLK 周期
	fsmc_norsram_timing_init.FSMC_AddressSetupTime = 0x02;
	// 地址保持时间, 1 个 HCLK 周期
	fsmc_norsram_timing_init.FSMC_AddressHoldTime = 0x00;
	// 数据建立时间, 4 个 HCLK 周期
	fsmc_norsram_timing_init.FSMC_DataSetupTime = 0x03;
	// 数据保持时间, 1 个 HCLK 周期
	fsmc_norsram_timing_init.FSMC_DataLatency = 0x00;
	// 总线恢复时间设置
	fsmc_norsram_timing_init.FSMC_BusTurnAroundDuration = 0x00;
	// 时钟分频设置
	fsmc_norsram_timing_init.FSMC_CLKDivision = 0x00;
	// 设置模式B (NOR)
	fsmc_norsram_timing_init.FSMC_AccessMode = FSMC_AccessMode_A;
	// 初始化
	FSMC_NORSRAMInit(&fsmc_norsram_init);
}
// 用于TFT显示屏的FSMC接口初始化
inline void fsmc_config_1_4(void) {
	FSMC_NORSRAMInitTypeDef fsmc_norsram_init;
	FSMC_NORSRAMTimingInitTypeDef fsmc_norsram_timing_init;
	// 第一存储块 第四区
	fsmc_norsram_init.FSMC_Bank = FSMC_Bank1_NORSRAM4;
	// SRAM 模式
	fsmc_norsram_init.FSMC_MemoryType = FSMC_MemoryType_SRAM;
	// 数据宽度16位
	fsmc_norsram_init.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;
	// 写使能
	fsmc_norsram_init.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
	// 拓展模式使能 读写使用不同的时序
	fsmc_norsram_init.FSMC_ExtendedMode = FSMC_ExtendedMode_Enable;
	// 地址和数据线复用 失能
	fsmc_norsram_init.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
	// 设置读写时序
	fsmc_norsram_init.FSMC_ReadWriteTimingStruct = &fsmc_norsram_timing_init;
	// 设置写时序
	fsmc_norsram_init.FSMC_WriteTimingStruct = &fsmc_norsram_timing_init;
	// 设置读写时序
	// 地址建立时间, 3 个 HCLK 周期
	fsmc_norsram_timing_init.FSMC_AddressSetupTime = 0x02;
	// 地址保持时间, 1 个 HCLK 周期
	fsmc_norsram_timing_init.FSMC_AddressHoldTime = 0x00;
	// 数据建立时间, 6 个 HCLK 周期
	fsmc_norsram_timing_init.FSMC_DataSetupTime = 0x05;
	// 数据保持时间, 1 个 HCLK 周期
	fsmc_norsram_timing_init.FSMC_DataLatency = 0x00;
	// 总线恢复时间设置
	fsmc_norsram_timing_init.FSMC_BusTurnAroundDuration = 0x00;
	// 时钟分频设置
	fsmc_norsram_timing_init.FSMC_CLKDivision = 0x01;
	// 设置模式B (NOR)
	fsmc_norsram_timing_init.FSMC_AccessMode = FSMC_AccessMode_B;
	// 初始化
	FSMC_NORSRAMInit(&fsmc_norsram_init);
}
/**
 * FSMC功能配置
 */
extern void fsmc_config(void) {
	// 启动时钟
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);
	// 各区块FSMC启动
	fsmc_config_1_3();
	fsmc_config_1_4();
	// 使能
	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, DISABLE);
	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM2, DISABLE);
	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM3, ENABLE);
	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM4, ENABLE);

}

}
}
