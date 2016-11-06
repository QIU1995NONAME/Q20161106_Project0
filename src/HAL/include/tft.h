#ifndef __TFT_H__
#define __TFT_H__

#include "stm32f10x.h"
#include "systick.h"

namespace QIU {
namespace PJ0 {
/**
 * 由于个人能力有限，这个文件中存在大量的无用代码，先留档，以后再说
 */
// 寄存器地址 FIXME 为什么是7FE?
#define TFT_BASE ((uint32_t)( 0x6C000000 | 0x000007FE ))
// 控制用的结构体
typedef struct TFT_TypeStruct {
	u16 TFT_CMD;
	u16 TFT_DAT;
} TFT_TypeDef;
#define TFT ( (TFT_TypeDef *) TFT_BASE )
// 屏幕大小
#define TFT_MAX_COL (319) // 320 - 1
#define TFT_MAX_ROW (479) // 480 - 1
// 最基本的操作 写命令
inline void TFT_WriteCmd(u16 cmd) {
	TFT->TFT_CMD = cmd;
}
// 最基本的操作 写数据
inline void TFT_WriteDat(u16 dat) {
	TFT->TFT_DAT = dat;
}
// 最基本的操作 读数据
inline void TFT_ReadData(u16* dat) {
	*dat = TFT->TFT_DAT;
}
// 临时变量
extern s32 tft_cmd_tmp;
// 空命令 没有任何显示效果 FIXME 还没写完用法
inline void TFT_Cmd_00_NOP(void) {
	TFT_WriteCmd(0x00);
}
// 软重启 触发一次Software RESET
// 显示屏会瞬间变空 GRAM的内容不受影响
inline void TFT_Cmd_01_SWRESET(void) {
	TFT_WriteCmd(0x01);
}
// 未定义的命令
inline void TFT_Cmd_02(void) {
	TFT_WriteCmd(0x02);
}
// 未定义的命令
inline void TFT_Cmd_03(void) {
	TFT_WriteCmd(0x03);
}
// FIXME 未写注释
inline void TFT_Cmd_04_RDDIDIF(void) {
	TFT_WriteCmd(0x04);
}
// FIXME 未写注释
inline void TFT_Cmd_05_RDNUMPE(void) {
	TFT_WriteCmd(0x05);
}
// FIXME 未写注释
inline void TFT_Cmd_06_RDRED(void) {
	TFT_WriteCmd(0x06);
}
// FIXME 未写注释
inline void TFT_Cmd_07_RDGREEN(void) {
	TFT_WriteCmd(0x07);
}
// FIXME 未写注释
inline void TFT_Cmd_08_RDBLUE(void) {
	TFT_WriteCmd(0x08);
}
// 未定义的命令
inline void TFT_Cmd_09(void) {
	TFT_WriteCmd(0x09);
}
// FIXME 未写注释
inline void TFT_Cmd_0A_RDDPM(void) {
	TFT_WriteCmd(0x0A);
}
// FIXME 未写注释
inline void TFT_Cmd_0B_RDDMADCTL(void) {
	TFT_WriteCmd(0x0B);
}
// FIXME 未写注释
inline void TFT_Cmd_0C_RDDCOLMOD(void) {
	TFT_WriteCmd(0x0C);
}
// FIXME 未写注释
inline void TFT_Cmd_0D_RDDIM(void) {
	TFT_WriteCmd(0x0D);
}
// FIXME 未写注释
inline void TFT_Cmd_0E_RDDSM(void) {
	TFT_WriteCmd(0x0E);
}
// FIXME 未写注释
inline void TFT_Cmd_0F_RDDSDR(void) {
	TFT_WriteCmd(0x0F);
}
// 进入休眠状态
inline void TFT_Cmd_10_SLPIN(void) {
	TFT_WriteCmd(0x10);
}
// 退出休眠状态
// 需要120ms的时间
inline void TFT_Cmd_11_SLPOUT(void) {
	TFT_WriteCmd(0x11);
	delay_ms(120);
}
// 进入局部(Partial)模式
// 局部定义需要用命令30H设定 FIXME 有待考察
// 退出局部模式使用13H命令
inline void TFT_Cmd_12_PTLON(void) {
	TFT_WriteCmd(0x12);
}
// 进入普通模式
// 该命令意味着局部模式(12H)关闭，滚动模式(FIXME 滚动模式的代码)关闭
inline void TFT_Cmd_13_NORON(void) {
	TFT_WriteCmd(0x13);
}
// 未定义的命令
inline void TFT_Cmd_14(void) {
	TFT_WriteCmd(0x14);
}
// 未定义的命令
inline void TFT_Cmd_15(void) {
	TFT_WriteCmd(0x15);
}
// 未定义的命令
inline void TFT_Cmd_16(void) {
	TFT_WriteCmd(0x16);
}
// 未定义的命令
inline void TFT_Cmd_17(void) {
	TFT_WriteCmd(0x17);
}
// 未定义的命令
inline void TFT_Cmd_18(void) {
	TFT_WriteCmd(0x18);
}
// 未定义的命令
inline void TFT_Cmd_19(void) {
	TFT_WriteCmd(0x19);
}
// 未定义的命令
inline void TFT_Cmd_1A(void) {
	TFT_WriteCmd(0x1A);
}
// 未定义的命令
inline void TFT_Cmd_1B(void) {
	TFT_WriteCmd(0x1B);
}
// 未定义的命令
inline void TFT_Cmd_1C(void) {
	TFT_WriteCmd(0x1C);
}
// 未定义的命令
inline void TFT_Cmd_1D(void) {
	TFT_WriteCmd(0x1D);
}
// 未定义的命令
inline void TFT_Cmd_1E(void) {
	TFT_WriteCmd(0x1E);
}
// 未定义的命令
inline void TFT_Cmd_1F(void) {
	TFT_WriteCmd(0x1F);
}
// 关闭颜色反转模式
// 用于退出反转模式
inline void TFT_Cmd_20_INVOFF(void) {
	TFT_WriteCmd(0x20);
}
// 进入/启动颜色反转模式
inline void TFT_Cmd_21_INVON(void) {
	TFT_WriteCmd(0x21);
}
// 黑屏
// 所有像素显示为黑,而非进入休眠状态
inline void TFT_Cmd_22_ALLPOFF(void) {
	TFT_WriteCmd(0x22);
}
// 白屏
// 所有像素显示为白,而非进入休眠状态
inline void TFT_Cmd_23_ALLPON(void) {
	TFT_WriteCmd(0x23);
}
// 未定义的命令
inline void TFT_Cmd_24(void) {
	TFT_WriteCmd(0x24);
}
// 未定义的命令
inline void TFT_Cmd_25(void) {
	TFT_WriteCmd(0x25);
}
// 设定当前状态的GAMMA值
// FIXME 参数详细用法用到的时候再写
inline void TFT_Cmd_26_GAMSET(u8 arg) {
	TFT_WriteCmd(0x26);
	TFT_WriteDat(arg);
}
// 未定义的命令
inline void TFT_Cmd_27(void) {
	TFT_WriteCmd(0x27);
}
// 关闭屏幕 暂时禁用显存 并不会清除显存
inline void TFT_Cmd_28_DISPOFF(void) {
	TFT_WriteCmd(0x28);
}
// 打开屏幕 并把显存中的数据显示出来
inline void TFT_Cmd_29_DISPON(void) {
	TFT_WriteCmd(0x29);
}
// 列地址选择 指定MCU可以访问的显存区域
inline void TFT_Cmd_2A_CASET(u16 col_start, u16 col_end) {
	TFT_WriteCmd(0x2A);
	TFT_WriteDat(col_start >> 8);
	TFT_WriteDat(col_start & 0xFF);
	TFT_WriteDat(col_end >> 8);
	TFT_WriteDat(col_end & 0xFF);
}
// 页(行)地址选择
inline void TFT_Cmd_2B_PASET(u16 page_start, u16 page_end) {
	TFT_WriteCmd(0x2B);
	TFT_WriteDat(page_start >> 8);
	TFT_WriteDat(page_start & 0xFF);
	TFT_WriteDat(page_end >> 8);
	TFT_WriteDat(page_end & 0xFF);
}
// 写入显存 FIXME 这个函数还需要再设计
inline void TFT_Cmd_2C_RAMWR(void) {
	TFT_WriteCmd(0x2C);
}
// 未定义的命令
inline void TFT_Cmd_2D(void) {
	TFT_WriteCmd(0x2D);
}
// 读取显存 FIXME 这个函数还需要测试和设计
inline void TFT_Cmd_2E_RAMRD(void) {
	TFT_WriteCmd(0x2E);
}
// 未定义的命令
inline void TFT_Cmd_2F(void) {
	TFT_WriteCmd(0x2F);
}
// 区域选择 FIXME 更多的注释用到的时候再写
inline void TFT_Cmd_30_PLTAR(u16 row_start, u16 row_end) {
	TFT_WriteCmd(0x30);
	TFT_WriteDat(row_start >> 8);
	TFT_WriteDat(row_start & 0xFF);
	TFT_WriteDat(row_end >> 8);
	TFT_WriteDat(row_end & 0xFF);
}
// 未定义的命令
inline void TFT_Cmd_31(void) {
	TFT_WriteCmd(0x31);
}
// 未定义的命令
inline void TFT_Cmd_32(void) {
	TFT_WriteCmd(0x32);
}
// 纵向滚动定义
inline void TFT_Cmd_33_VSCRDEF(u16 top_fixed, u16 bottom_fixed) {
	TFT_WriteCmd(0x33);
	tft_cmd_tmp = TFT_MAX_ROW + 1 - top_fixed - bottom_fixed;
	if (tft_cmd_tmp > 0) {
		TFT_WriteDat(top_fixed >> 8);
		TFT_WriteDat(top_fixed & 0xFF);
		TFT_WriteDat(tft_cmd_tmp >> 8);
		TFT_WriteDat(tft_cmd_tmp & 0xFF);
		TFT_WriteDat(bottom_fixed >> 8);
		TFT_WriteDat(bottom_fixed & 0xFF);
	} else {
		TFT_Cmd_00_NOP();
	}
}
// 关闭 Tearing Effect
inline void TFT_Cmd_34_TEOFF(void) {
	TFT_WriteCmd(0x34);
}
// 启动 Tearing Effect FIXME 详细用法用到再说
inline void TFT_Cmd_35_TEON(u8 te_mode) {
	TFT_WriteCmd(0x35);
	TFT_WriteDat(te_mode != 0 ? 0x01 : 0x00);
}
// 内存访问控制
// 参数详细
// Bit7: MY  页(行)地址顺序
// Bit6: MX  列地址顺序
// Bit5: MV  行/列选择
// Bit4: ML  纵向刷新顺序
// Bit3: BGR RGB/BGR
// Bit2: SS  横向刷新方向
// Bit1: 0
// Bit0: 0
inline void TFT_Cmd_36_MADCTL(u8 arg) {
	TFT_WriteCmd(0x36);
	TFT_WriteDat(arg & ~(0x02));
}
// 纵向滚动起始地址  FIXME 详细用法用到再说
inline void TFT_Cmd_37_VSCRSADD(u16 vsp) {
	TFT_WriteCmd(0x37);
	TFT_WriteDat(vsp >> 8);
	TFT_WriteDat(vsp & 0xFF);
}
// 关闭懒惰模式
inline void TFT_Cmd_38_IDMOFF(void) {
	TFT_WriteCmd(0x38);
}
// 启动懒惰模式
// 所有显示的颜色仅最高位有效
// 屏幕仅能显示8色
inline void TFT_Cmd_39_IDMON(void) {
	TFT_WriteCmd(0x39);
}
// 颜色模式
// 参数高4位定义DPI界面模式
// 0x5~ 16位色
// 0x6~ 18位色
// 0x7~ 24位色
// 参数低4位定义DBI界面模式
// 0x~3 12位色
// 0x~5 16位色
// 0x~6 18位色
// 0x~7 24位色
inline void TFT_Cmd_3A_COLMOD(u8 arg) {
	TFT_WriteCmd(0x3A);
	TFT_WriteDat(arg);
}
// 继续写内存 FIXME 不明白干啥用的
inline void TFT_Cmd_3B_WriteMemoryContinue(void) {
	TFT_WriteCmd(0x3B);
}
// 未定义的命令
inline void TFT_Cmd_3C(void) {
	TFT_WriteCmd(0x3C);
}
// 未定义的命令
inline void TFT_Cmd_3D(void) {
	TFT_WriteCmd(0x3D);
}
// 继续读内存 FIXME 不明白干啥用的
inline void TFT_Cmd_3E_ReadMemoryContinue(void) {
	TFT_WriteCmd(0x3E);
}
// 未定义的命令
inline void TFT_Cmd_3F(void) {
	TFT_WriteCmd(0x3F);
}
// 未定义的命令
inline void TFT_Cmd_40(void) {
	TFT_WriteCmd(0x40);
}
// 未定义的命令
inline void TFT_Cmd_41(void) {
	TFT_WriteCmd(0x41);
}
// 未定义的命令
inline void TFT_Cmd_42(void) {
	TFT_WriteCmd(0x42);
}
// 未定义的命令
inline void TFT_Cmd_43(void) {
	TFT_WriteCmd(0x43);
}
// 设置 Tear Effect 扫描行 FIXME 用到再说
inline void TFT_Cmd_44_TESL(u16 arg) {
	TFT_WriteCmd(0x44);
	TFT_WriteDat(arg >> 8);
	TFT_WriteDat(arg & 0xFF);
}
// 获取扫描行  FIXME 用到再说
inline void TFT_Cmd_45_GETSL(void) {
	TFT_WriteCmd(0x45);
}
// 未定义的命令
inline void TFT_Cmd_46(void) {
	TFT_WriteCmd(0x46);
}
// 未定义的命令
inline void TFT_Cmd_47(void) {
	TFT_WriteCmd(0x47);
}
// 未定义的命令
inline void TFT_Cmd_48(void) {
	TFT_WriteCmd(0x48);
}
// 未定义的命令
inline void TFT_Cmd_49(void) {
	TFT_WriteCmd(0x49);
}
// 未定义的命令
inline void TFT_Cmd_4A(void) {
	TFT_WriteCmd(0x4A);
}
// 未定义的命令
inline void TFT_Cmd_4B(void) {
	TFT_WriteCmd(0x4B);
}
// 未定义的命令
inline void TFT_Cmd_4C(void) {
	TFT_WriteCmd(0x4C);
}
// 未定义的命令
inline void TFT_Cmd_4D(void) {
	TFT_WriteCmd(0x4D);
}
// 未定义的命令
inline void TFT_Cmd_4E(void) {
	TFT_WriteCmd(0x4E);
}
// 未定义的命令
inline void TFT_Cmd_4F(void) {
	TFT_WriteCmd(0x4F);
}
// 未定义的命令
inline void TFT_Cmd_50(void) {
	TFT_WriteCmd(0x50);
}
// 设置屏幕显示亮度
inline void TFT_Cmd_51_WRDISBV(u8 arg) {
	TFT_WriteCmd(0x51);
	TFT_WriteDat(arg);
}
// 获取屏幕亮度
inline void TFT_Cmd_52_RDDISBV(u16* arg) {
	TFT_WriteCmd(0x52);
	TFT_WriteDat(0x00); //Dummy
	TFT_ReadData(arg);
}
// Write Control Display XXX 这个鬼怎么翻译
// Bit 5: BCTRL  亮度控制块
// Bit 3: DD     屏幕变暗
// Bit 2: BL     背光
inline void TFT_Cmd_53(u8 arg) {
	TFT_WriteCmd(0x53);
	TFT_WriteDat(arg);
}
// Read Control Display XXX 这个鬼怎么翻译
inline void TFT_Cmd_54(u16* arg) {
	TFT_WriteCmd(0x54);
	TFT_WriteDat(0x00); //Dummy
	TFT_ReadData(arg);
}
// FIXME 用到再说
inline void TFT_Cmd_55_WRCABC(void) {
	TFT_WriteCmd(0x55);
}
// FIXME 用到再说
inline void TFT_Cmd_56_RDCABC(void) {
	TFT_WriteCmd(0x56);
}
// 未定义的命令
inline void TFT_Cmd_57(void) {
	TFT_WriteCmd(0x57);
}
// 未定义的命令
inline void TFT_Cmd_58(void) {
	TFT_WriteCmd(0x58);
}
// 未定义的命令
inline void TFT_Cmd_59(void) {
	TFT_WriteCmd(0x59);
}
// 未定义的命令
inline void TFT_Cmd_5A(void) {
	TFT_WriteCmd(0x5A);
}
// 未定义的命令
inline void TFT_Cmd_5B(void) {
	TFT_WriteCmd(0x5B);
}
// 未定义的命令
inline void TFT_Cmd_5C(void) {
	TFT_WriteCmd(0x5C);
}
// 未定义的命令
inline void TFT_Cmd_5D(void) {
	TFT_WriteCmd(0x5D);
}
// FIXME 用到再说
inline void TFT_Cmd_5E_WRCABCMB(void) {
	TFT_WriteCmd(0x5E);
}
// FIXME 用到再说
inline void TFT_Cmd_5F_RDCABCMB(void) {
	TFT_WriteCmd(0x5F);
}
// 未定义的命令
inline void TFT_Cmd_60(void) {
	TFT_WriteCmd(0x60);
}
// 未定义的命令
inline void TFT_Cmd_61(void) {
	TFT_WriteCmd(0x61);
}
// 未定义的命令
inline void TFT_Cmd_62(void) {
	TFT_WriteCmd(0x62);
}
// 未定义的命令
inline void TFT_Cmd_63(void) {
	TFT_WriteCmd(0x63);
}
// 未定义的命令
inline void TFT_Cmd_64(void) {
	TFT_WriteCmd(0x64);
}
// 未定义的命令
inline void TFT_Cmd_65(void) {
	TFT_WriteCmd(0x65);
}
// 未定义的命令
inline void TFT_Cmd_66(void) {
	TFT_WriteCmd(0x66);
}
// 未定义的命令
inline void TFT_Cmd_67(void) {
	TFT_WriteCmd(0x67);
}
// FIXME 用到再说
inline void TFT_Cmd_68_RDABCSDR(void) {
	TFT_WriteCmd(0x68);
}
// 未定义的命令
inline void TFT_Cmd_69(void) {
	TFT_WriteCmd(0x69);
}
// 未定义的命令
inline void TFT_Cmd_6A(void) {
	TFT_WriteCmd(0x6A);
}
// 未定义的命令
inline void TFT_Cmd_6B(void) {
	TFT_WriteCmd(0x6B);
}
// 未定义的命令
inline void TFT_Cmd_6C(void) {
	TFT_WriteCmd(0x6C);
}
// 未定义的命令
inline void TFT_Cmd_6D(void) {
	TFT_WriteCmd(0x6D);
}
// 未定义的命令
inline void TFT_Cmd_6E(void) {
	TFT_WriteCmd(0x6E);
}
// 未定义的命令
inline void TFT_Cmd_6F(void) {
	TFT_WriteCmd(0x6F);
}
// FIXME 用到再说
inline void TFT_Cmd_70_RDBWLK(void) {
	TFT_WriteCmd(0x70);
}
// FIXME 用到再说
inline void TFT_Cmd_71_RDBkx(void) {
	TFT_WriteCmd(0x71);
}
// FIXME 用到再说
inline void TFT_Cmd_72_RDBky(void) {
	TFT_WriteCmd(0x72);
}
// FIXME 用到再说
inline void TFT_Cmd_73_RDWx(void) {
	TFT_WriteCmd(0x73);
}
// FIXME 用到再说
inline void TFT_Cmd_74_RDWy(void) {
	TFT_WriteCmd(0x74);
}
// FIXME 用到再说
inline void TFT_Cmd_75_RDRGLB(void) {
	TFT_WriteCmd(0x75);
}
// FIXME 用到再说
inline void TFT_Cmd_76_RDRx(void) {
	TFT_WriteCmd(0x76);
}
// FIXME 用到再说
inline void TFT_Cmd_77_RDRy(void) {
	TFT_WriteCmd(0x77);
}
// FIXME 用到再说
inline void TFT_Cmd_78_RDGx(void) {
	TFT_WriteCmd(0x78);
}
// FIXME 用到再说
inline void TFT_Cmd_79_RDGy(void) {
	TFT_WriteCmd(0x79);
}
// FIXME 用到再说
inline void TFT_Cmd_7A_RDBALB(void) {
	TFT_WriteCmd(0x7A);
}
// FIXME 用到再说
inline void TFT_Cmd_7B_RDBx(void) {
	TFT_WriteCmd(0x7B);
}
// FIXME 用到再说
inline void TFT_Cmd_7C_RDBy(void) {
	TFT_WriteCmd(0x7C);
}
// FIXME 用到再说
inline void TFT_Cmd_7D_RDAx(void) {
	TFT_WriteCmd(0x7D);
}
// FIXME 用到再说
inline void TFT_Cmd_7E_RDAy(void) {
	TFT_WriteCmd(0x7E);
}
// 未定义的命令
inline void TFT_Cmd_7F(void) {
	TFT_WriteCmd(0x7F);
}
// 未定义的命令
inline void TFT_Cmd_80(void) {
	TFT_WriteCmd(0x80);
}
// 未定义的命令
inline void TFT_Cmd_81(void) {
	TFT_WriteCmd(0x81);
}
// 未定义的命令
inline void TFT_Cmd_82(void) {
	TFT_WriteCmd(0x82);
}
// 未定义的命令
inline void TFT_Cmd_83(void) {
	TFT_WriteCmd(0x83);
}
// 未定义的命令
inline void TFT_Cmd_84(void) {
	TFT_WriteCmd(0x84);
}
// 未定义的命令
inline void TFT_Cmd_85(void) {
	TFT_WriteCmd(0x85);
}
// 未定义的命令
inline void TFT_Cmd_86(void) {
	TFT_WriteCmd(0x86);
}
// 未定义的命令
inline void TFT_Cmd_87(void) {
	TFT_WriteCmd(0x87);
}
// 未定义的命令
inline void TFT_Cmd_88(void) {
	TFT_WriteCmd(0x88);
}
// 未定义的命令
inline void TFT_Cmd_89(void) {
	TFT_WriteCmd(0x89);
}
// 未定义的命令
inline void TFT_Cmd_8A(void) {
	TFT_WriteCmd(0x8A);
}
// 未定义的命令
inline void TFT_Cmd_8B(void) {
	TFT_WriteCmd(0x8B);
}
// 未定义的命令
inline void TFT_Cmd_8C(void) {
	TFT_WriteCmd(0x8C);
}
// 未定义的命令
inline void TFT_Cmd_8D(void) {
	TFT_WriteCmd(0x8D);
}
// 未定义的命令
inline void TFT_Cmd_8E(void) {
	TFT_WriteCmd(0x8E);
}
// 未定义的命令
inline void TFT_Cmd_8F(void) {
	TFT_WriteCmd(0x8F);
}
// 未定义的命令
inline void TFT_Cmd_90(void) {
	TFT_WriteCmd(0x90);
}
// 未定义的命令
inline void TFT_Cmd_91(void) {
	TFT_WriteCmd(0x91);
}
// 未定义的命令
inline void TFT_Cmd_92(void) {
	TFT_WriteCmd(0x92);
}
// 未定义的命令
inline void TFT_Cmd_93(void) {
	TFT_WriteCmd(0x93);
}
// 未定义的命令
inline void TFT_Cmd_94(void) {
	TFT_WriteCmd(0x94);
}
// 未定义的命令
inline void TFT_Cmd_95(void) {
	TFT_WriteCmd(0x95);
}
// 未定义的命令
inline void TFT_Cmd_96(void) {
	TFT_WriteCmd(0x96);
}
// 未定义的命令
inline void TFT_Cmd_97(void) {
	TFT_WriteCmd(0x97);
}
// 未定义的命令
inline void TFT_Cmd_98(void) {
	TFT_WriteCmd(0x98);
}
// 未定义的命令
inline void TFT_Cmd_99(void) {
	TFT_WriteCmd(0x99);
}
// 未定义的命令
inline void TFT_Cmd_9A(void) {
	TFT_WriteCmd(0x9A);
}
// 未定义的命令
inline void TFT_Cmd_9B(void) {
	TFT_WriteCmd(0x9B);
}
// 未定义的命令
inline void TFT_Cmd_9C(void) {
	TFT_WriteCmd(0x9C);
}
// 未定义的命令
inline void TFT_Cmd_9D(void) {
	TFT_WriteCmd(0x9D);
}
// 未定义的命令
inline void TFT_Cmd_9E(void) {
	TFT_WriteCmd(0x9E);
}
// 未定义的命令
inline void TFT_Cmd_9F(void) {
	TFT_WriteCmd(0x9F);
}
// 未定义的命令
inline void TFT_Cmd_A0(void) {
	TFT_WriteCmd(0xA0);
}
// FIXME 用到再说
inline void TFT_Cmd_A1_Read_DDB_Start(void) {
	TFT_WriteCmd(0xA1);
}
// 未定义的命令
inline void TFT_Cmd_A2(void) {
	TFT_WriteCmd(0xA2);
}
// 未定义的命令
inline void TFT_Cmd_A3(void) {
	TFT_WriteCmd(0xA3);
}
// 未定义的命令
inline void TFT_Cmd_A4(void) {
	TFT_WriteCmd(0xA4);
}
// 未定义的命令
inline void TFT_Cmd_A5(void) {
	TFT_WriteCmd(0xA5);
}
// 未定义的命令
inline void TFT_Cmd_A6(void) {
	TFT_WriteCmd(0xA6);
}
// 未定义的命令
inline void TFT_Cmd_A7(void) {
	TFT_WriteCmd(0xA7);
}
// FIXME 用到再说
inline void TFT_Cmd_A8_Read_DDB_Continue(void) {
	TFT_WriteCmd(0xA8);
}
// 未定义的命令
inline void TFT_Cmd_A9(void) {
	TFT_WriteCmd(0xA9);
}
// FIXME 用到再说
inline void TFT_Cmd_AA_RDFCS(void) {
	TFT_WriteCmd(0xAA);
}
// 未定义的命令
inline void TFT_Cmd_AB(void) {
	TFT_WriteCmd(0xAB);
}
// 未定义的命令
inline void TFT_Cmd_AC(void) {
	TFT_WriteCmd(0xAC);
}
// 未定义的命令
inline void TFT_Cmd_AD(void) {
	TFT_WriteCmd(0xAD);
}
// 未定义的命令
inline void TFT_Cmd_AE(void) {
	TFT_WriteCmd(0xAE);
}
// FIXME 用到再说
inline void TFT_Cmd_AF_RDCCS(void) {
	TFT_WriteCmd(0xAF);
}
// FIXME 用到再说
inline void TFT_Cmd_B0_SETOSC(void) {
	TFT_WriteCmd(0xB0);
}
// FIXME 用到再说
inline void TFT_Cmd_B1_SETPOWER(void) {
	TFT_WriteCmd(0xB1);
}
// FIXME 用到再说
inline void TFT_Cmd_B2_SETDISPLAY(void) {
	TFT_WriteCmd(0xB2);
}
// FIXME 用到再说
inline void TFT_Cmd_B3_SETRGBIF(void) {
	TFT_WriteCmd(0xB3);
}
// FIXME 用到再说
inline void TFT_Cmd_B4_SETCYC(void) {
	TFT_WriteCmd(0xB4);
}
// FIXME 用到再说
inline void TFT_Cmd_B5_SETPTBA(void) {
	TFT_WriteCmd(0xB5);
}
// FIXME 用到再说
inline void TFT_Cmd_B6_SETCOM(void) {
	TFT_WriteCmd(0xB6);
}
// 未定义的命令
inline void TFT_Cmd_B7_SETOTP(void) {
	TFT_WriteCmd(0xB7);
}
// 未定义的命令
inline void TFT_Cmd_B8(void) {
	TFT_WriteCmd(0xB8);
}
// FIXME 用到再说
inline void TFT_Cmd_B9_SETEXTC(void) {
	TFT_WriteCmd(0xB9);
}
// 未定义的命令
inline void TFT_Cmd_BA(void) {
	TFT_WriteCmd(0xBA);
}
// 未定义的命令
inline void TFT_Cmd_BB(void) {
	TFT_WriteCmd(0xBB);
}
// 未定义的命令
inline void TFT_Cmd_BC(void) {
	TFT_WriteCmd(0xBC);
}
// 未定义的命令
inline void TFT_Cmd_BD(void) {
	TFT_WriteCmd(0xBD);
}
// 未定义的命令
inline void TFT_Cmd_BE(void) {
	TFT_WriteCmd(0xBE);
}
// 未定义的命令
inline void TFT_Cmd_BF(void) {
	TFT_WriteCmd(0xBF);
}
// FIXME 用到再说
inline void TFT_Cmd_C0_SETSTBA(void) {
	TFT_WriteCmd(0xC0);
}
// FIXME 用到再说
inline void TFT_Cmd_C1_SETDGC(void) {
	TFT_WriteCmd(0xC1);
}
// 未定义的命令
inline void TFT_Cmd_C2(void) {
	TFT_WriteCmd(0xC2);
}
// FIXME 用到再说
inline void TFT_Cmd_C3_SETID(void) {
	TFT_WriteCmd(0xC3);
}
// FIXME 用到再说
inline void TFT_Cmd_C4_SETDDB(void) {
	TFT_WriteCmd(0xC4);
}
// 未定义的命令
inline void TFT_Cmd_C5(void) {
	TFT_WriteCmd(0xC5);
}
// 未定义的命令
inline void TFT_Cmd_C6(void) {
	TFT_WriteCmd(0xC6);
}
// 未定义的命令
inline void TFT_Cmd_C7(void) {
	TFT_WriteCmd(0xC7);
}
// 未定义的命令
inline void TFT_Cmd_C8(void) {
	TFT_WriteCmd(0xC8);
}
// FIXME 用到再说
inline void TFT_Cmd_C9_SETCABC(void) {
	TFT_WriteCmd(0xC9);
}
// 未定义的命令
inline void TFT_Cmd_CA(void) {
	TFT_WriteCmd(0xCA);
}
// 未定义的命令
inline void TFT_Cmd_CB(void) {
	TFT_WriteCmd(0xCB);
}
// 未定义的命令
inline void TFT_Cmd_CC_SETPANEL(void) {
	TFT_WriteCmd(0xCC);
}
// 未定义的命令
inline void TFT_Cmd_CD(void) {
	TFT_WriteCmd(0xCD);
}
// 未定义的命令
inline void TFT_Cmd_CE(void) {
	TFT_WriteCmd(0xCE);
}
// 未定义的命令
inline void TFT_Cmd_CF(void) {
	TFT_WriteCmd(0xCF);
}
// 未定义的命令
inline void TFT_Cmd_D0_GETICID(void) {
	TFT_WriteCmd(0xD0);
}
// 未定义的命令
inline void TFT_Cmd_D1(void) {
	TFT_WriteCmd(0xD1);
}
// 未定义的命令
inline void TFT_Cmd_D2(void) {
	TFT_WriteCmd(0xD2);
}
// 未定义的命令
inline void TFT_Cmd_D3(void) {
	TFT_WriteCmd(0xD3);
}
// 未定义的命令
inline void TFT_Cmd_D4(void) {
	TFT_WriteCmd(0xD4);
}
// 未定义的命令
inline void TFT_Cmd_D5(void) {
	TFT_WriteCmd(0xD5);
}
// 未定义的命令
inline void TFT_Cmd_D6(void) {
	TFT_WriteCmd(0xD6);
}
// 未定义的命令
inline void TFT_Cmd_D7(void) {
	TFT_WriteCmd(0xD7);
}
// 未定义的命令
inline void TFT_Cmd_D8(void) {
	TFT_WriteCmd(0xD8);
}
// 未定义的命令
inline void TFT_Cmd_D9(void) {
	TFT_WriteCmd(0xD9);
}
// FIXME 用到再说
inline void TFT_Cmd_DA_RDID1(void) {
	TFT_WriteCmd(0xDA);
}
// FIXME 用到再说
inline void TFT_Cmd_DB_RDID2(void) {
	TFT_WriteCmd(0xDB);
}
// FIXME 用到再说
inline void TFT_Cmd_DC_RDID3(void) {
	TFT_WriteCmd(0xDC);
}
// 未定义的命令
inline void TFT_Cmd_DD(void) {
	TFT_WriteCmd(0xDD);
}
// 未定义的命令
inline void TFT_Cmd_DE(void) {
	TFT_WriteCmd(0xDE);
}
// 未定义的命令
inline void TFT_Cmd_DF(void) {
	TFT_WriteCmd(0xDF);
}
// 设置Gamma曲线
inline void TFT_Cmd_E0_SETGAMMA(void) {
	TFT_WriteCmd(0xE0);
}
// 未定义的命令
inline void TFT_Cmd_E1(void) {
	TFT_WriteCmd(0xE1);
}
// 未定义的命令
inline void TFT_Cmd_E2(void) {
	TFT_WriteCmd(0xE2);
}
// 未定义的命令
inline void TFT_Cmd_E3(void) {
	TFT_WriteCmd(0xE3);
}
// 未定义的命令
inline void TFT_Cmd_E4(void) {
	TFT_WriteCmd(0xE4);
}
// 未定义的命令
inline void TFT_Cmd_E5(void) {
	TFT_WriteCmd(0xE5);
}
// 未定义的命令
inline void TFT_Cmd_E6(void) {
	TFT_WriteCmd(0xE6);
}
// 未定义的命令
inline void TFT_Cmd_E7(void) {
	TFT_WriteCmd(0xE7);
}
// 未定义的命令
inline void TFT_Cmd_E8(void) {
	TFT_WriteCmd(0xE8);
}
// 设置图像功能 FIXME 详细用法用到再写
inline void TFT_Cmd_E9_SETIMAGE(u8 arg) {
	TFT_WriteCmd(0xE9);
	TFT_WriteDat(arg);
}
// FIXME 用到再说
inline void TFT_Cmd_EA_SETMESSI(void) {
	TFT_WriteCmd(0xEA);
}
// FIXME 用到再说
inline void TFT_Cmd_EB_SETCOLOR(void) {
	TFT_WriteCmd(0xEB);
}
// 未定义的命令
inline void TFT_Cmd_EC(void) {
	TFT_WriteCmd(0xEC);
}
// 未定义的命令
inline void TFT_Cmd_ED(void) {
	TFT_WriteCmd(0xED);
}
// 未定义的命令
inline void TFT_Cmd_EE(void) {
	TFT_WriteCmd(0xEE);
}
// 未定义的命令
inline void TFT_Cmd_EF(void) {
	TFT_WriteCmd(0xEF);
}
// 未定义的命令
inline void TFT_Cmd_F0(void) {
	TFT_WriteCmd(0xF0);
}
// 未定义的命令
inline void TFT_Cmd_F1(void) {
	TFT_WriteCmd(0xF1);
}
// 未定义的命令
inline void TFT_Cmd_F2(void) {
	TFT_WriteCmd(0xF2);
}
// 未定义的命令
inline void TFT_Cmd_F3(void) {
	TFT_WriteCmd(0xF3);
}
// 未定义的命令
inline void TFT_Cmd_F4(void) {
	TFT_WriteCmd(0xF4);
}
// 未定义的命令
inline void TFT_Cmd_F5(void) {
	TFT_WriteCmd(0xF5);
}
// 未定义的命令
inline void TFT_Cmd_F6(void) {
	TFT_WriteCmd(0xF6);
}
// 未定义的命令
inline void TFT_Cmd_F7(void) {
	TFT_WriteCmd(0xF7);
}
// 未定义的命令
inline void TFT_Cmd_F8(void) {
	TFT_WriteCmd(0xF8);
}
// 未定义的命令
inline void TFT_Cmd_F9(void) {
	TFT_WriteCmd(0xF9);
}
// 未定义的命令
inline void TFT_Cmd_FA(void) {
	TFT_WriteCmd(0xFA);
}
// 未定义的命令
inline void TFT_Cmd_FB(void) {
	TFT_WriteCmd(0xFB);
}
// 未定义的命令
inline void TFT_Cmd_FC(void) {
	TFT_WriteCmd(0xFC);
}
// 未定义的命令
inline void TFT_Cmd_FD(void) {
	TFT_WriteCmd(0xFD);
}
// FIXME 用到再说
inline void TFT_Cmd_FE_SETREADINDEX(void) {
	TFT_WriteCmd(0xFE);
}
// FIXME 用到再说
inline void TFT_Cmd_FF_GETSPIREAD(void) {
	TFT_WriteCmd(0xFF);
}

extern void TFT_SetArea(u16 col_start, u16 col_end, u16 row_start, u16 row_end);
extern void TFT_ClearScreen(u16 color_code);
extern void TFT_Init(void);

}
}

#endif // __TFT_H__
