#ifndef __FSMC_H__
#define __FSMC_H__

#include "stm32f10x.h"

namespace QIU{
namespace PJ0{

#define BANK1_SRAM_LENGTH  ((u32)(0x04000000))
#define BANK1_SRAM1_ADDR   ((u32)(0x60000000))
#define BANK1_SRAM2_ADDR   ((u32)(0x64000000))
#define BANK1_SRAM3_ADDR   ((u32)(0x68000000))
#define BANK1_SRAM4_ADDR   ((u32)(0x6C000000))
/**
 * FSMC功能配置
 */
extern void fsmc_config(void);

}
}

#endif // __FSMC_H__
