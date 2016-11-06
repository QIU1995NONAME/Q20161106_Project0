#include "touch.h"
#include "systick.h"
#include "spi.h"

namespace QIU {
namespace PJ0 {
/*********************************************
 * 命令字格式
 * u8 0000-0000
 *    ?___-____ S 需要被置1
 *    _???-____ A2 A1 A0 通道选择
 *    ____-?___ MODE 0:即将进行12位精度转换
 *                   1:即将进行8位精度转换
 *    ____-_?__ SER/~DFR 0:差分输入模式
 *                       1:单端输入模式
 *    ____-__?? PD1 PD0 低功率相关设置
 *
 ********************************************/
// 两个读取命令
#define TOUCH_CMD_READ_Y       (0x90)
#define TOUCH_CMD_READ_X       (0xD0)

// 采样次数(越大越准 但越大越慢 不要小于3)
#define TOUCH_READ_TIMES       (0x05)

// 读取某一个物理值(AD转换值)
// 参数代表要读的数据(命令字)
inline u16 touch_read_physical(u8 cmd) {
	u16 res;
	u16 read_buf[TOUCH_READ_TIMES];
	u32 r_sum = 0;
	// 比较用的变量 把最小值放到最大 把最大值放到最小 有利稍后的计算
	u16 r_min = 0xFFFF, r_max = 0x0000;
	for (u8 i = 0; i < TOUCH_READ_TIMES; i++) {
		spi_1_cs_touch();
		// 发送命令
		spi_1_transfer(cmd);
		// 读取数据(先高后低)
		*(read_buf + i) = spi_1_transfer(0xFF);
		*(read_buf + i) <<= 8;
		*(read_buf + i) |= spi_1_transfer(0xFF);
		// 略去最后3位无效值
		*(read_buf + i) >>= 3;
		spi_1_cs_none();
	}
	// 简单的数据处理
	// 求和 求最大 求最小
	for (u8 i = 0; i < TOUCH_READ_TIMES - 1; i++) {
		r_sum += *(read_buf + i);
		r_min = *(read_buf + i) < r_min ? *(read_buf + i) : r_min;
		r_max = *(read_buf + i) > r_max ? *(read_buf + i) : r_max;
	}
	// 掐头去尾求平均
	r_sum -= r_min;
	r_sum -= r_max;
	res = r_sum / (TOUCH_READ_TIMES - 2);
	return res;
}
// 读取现在的物理坐标
// 如果传入NULL指针则会被忽略
extern void touch_read_point(u16* x, u16* y) {
	// TODO 这里可以进行一些特殊的操作
	if (y != 0) {
		*y = touch_read_physical(TOUCH_CMD_READ_Y);
	}
	if (x != 0) {
		*x = touch_read_physical(TOUCH_CMD_READ_X);
	}
}
// 初始化函数
extern void touch_init(void) {
	// FIXME 暂时是空的 校准程序稍后写 以及将校准值放到Flash中
}

}
}
