#include "tft.h"

namespace QIU {
namespace PJ0 {

s32 tft_cmd_tmp;
// 设置操作区域
extern void TFT_SetArea(u16 col_start, u16 col_end, u16 row_start,
		u16 row_end) {
	TFT_Cmd_2A_CASET(col_start, col_end);
	TFT_Cmd_2B_PASET(row_start, row_end);
	TFT_Cmd_2C_RAMWR();
}
// 以某种颜色清屏
extern void TFT_ClearScreen(u16 color_code) {
	u16 i, j;
	TFT_SetArea(0, TFT_MAX_COL, 0, TFT_MAX_ROW);
	for (i = 0; i < TFT_MAX_COL + 1; i++) {
		for (j = 0; j < TFT_MAX_ROW + 1; j++) {
			TFT_WriteDat(color_code);
		}
	}
}
// 初始化命令
extern void TFT_Init(void) {
	TFT_Cmd_E9_SETIMAGE(0x20);
	TFT_Cmd_11_SLPOUT();
	TFT_Cmd_3A_COLMOD(0x55);

	// ******** 中间这段见鬼的代码真心分析不出来了 *****
	TFT_WriteCmd(0xD1);
	TFT_WriteDat(0x00);
	TFT_WriteDat(0x65);
	TFT_WriteDat(0x1F);

	TFT_WriteCmd(0xD0);
	TFT_WriteDat(0x07);
	TFT_WriteDat(0x07);
	TFT_WriteDat(0x80);

	TFT_Cmd_36_MADCTL(0x48); //Set_address_mode

	TFT_WriteCmd(0xC1);
	TFT_WriteDat(0x10);
	TFT_WriteDat(0x10);
	TFT_WriteDat(0x02);
	TFT_WriteDat(0x02);

	TFT_WriteCmd(0xC0); //Set Default Gamma
	TFT_WriteDat(0x00);
	TFT_WriteDat(0x35);
	TFT_WriteDat(0x00);
	TFT_WriteDat(0x00);
	TFT_WriteDat(0x01);
	TFT_WriteDat(0x02);

	TFT_WriteCmd(0xC4);
	TFT_WriteDat(0x03);

	TFT_WriteCmd(0xC5); //Set frame rate
	TFT_WriteDat(0x01);

	TFT_WriteCmd(0xD2); //power setting
	TFT_WriteDat(0x01);
	TFT_WriteDat(0x22);

	TFT_WriteCmd(0xE7);
	TFT_WriteDat(0x38);

	TFT_WriteCmd(0xF3);
	TFT_WriteDat(0x08);
	TFT_WriteDat(0x12);
	TFT_WriteDat(0x12);
	TFT_WriteDat(0x08);

	TFT_WriteCmd(0xC8); //Set Gamma
	TFT_WriteDat(0x01);
	TFT_WriteDat(0x52);
	TFT_WriteDat(0x37);
	TFT_WriteDat(0x10);
	TFT_WriteDat(0x0d);
	TFT_WriteDat(0x01);
	TFT_WriteDat(0x04);
	TFT_WriteDat(0x51);
	TFT_WriteDat(0x77);
	TFT_WriteDat(0x01);
	TFT_WriteDat(0x01);
	TFT_WriteDat(0x0d);
	TFT_WriteDat(0x08);
	TFT_WriteDat(0x80);
	TFT_WriteDat(0x00);

	//***********************************

	TFT_Cmd_29_DISPON();
}

}
}
