#ifndef __BEEP_H__
#define __BEEP_H__

#include "stm32f10x.h"

namespace QIU {
namespace PJ0 {
// 蜂鸣器播放声音的速度 非常的不精准
#define BEEP_PLAY_SPEED_066 ((u16) (11))
#define BEEP_PLAY_SPEED_072 ((u16) (10))
#define BEEP_PLAY_SPEED_080 ((u16)  (9))
#define BEEP_PLAY_SPEED_096 ((u16)  (8))
#define BEEP_PLAY_SPEED_108 ((u16)  (7))
#define BEEP_PLAY_SPEED_120 ((u16)  (6))
#define BEEP_PLAY_SPEED_144 ((u16)  (5))
// 蜂鸣器音高的定义
#define BEEP_PITCH_12   (12)
#define BEEP_PITCH_C    (0)
#define BEEP_PITCH_CpDb (1)
#define BEEP_PITCH_D    (2)
#define BEEP_PITCH_DpEb (3)
#define BEEP_PITCH_E    (4)
#define BEEP_PITCH_F    (5)
#define BEEP_PITCH_FpGb (6)
#define BEEP_PITCH_G    (7)
#define BEEP_PITCH_GpAb (8)
#define BEEP_PITCH_A    (9)
#define BEEP_PITCH_ApBb (10)
#define BEEP_PITCH_B    (11)
/**
 * 定义一个音符
 * 音符序列由多个音符组成
 */
typedef struct BEEP_PLAY_NOTE {
	// 音高(0~83)
	u8 note_pitch;
	// 响度(0~19)
	u8 note_level;
	// 拍子(1/8拍)
	u8 note_ticks;
	// 实际播放出来的拍子
	u8 note_ticks_avail;
} BNote;
/**
 * 根据表格里面的数据设置音高（0~83）
 */
extern void beep_set_pitch(u16 pitch);
/**
 * 直接通过分频系数设定音高
 * 慎用！传入的数据太大容易使蜂鸣器产生次声
 */
extern void beep_set_pitch_raw(u16 pitch);
/**
 * 设定响度
 */
extern void beep_set_level(u16 level);
/**
 * 播放一段音符序列
 * 播放速度是 speed X10毫秒/八分之一拍
 */
extern void beep_play(BNote* notearray, u32 len, u16 speed);
/**
 * 放置在任务序列里面的函数
 * 不可以在其他地方直接调用
 */
extern void beep_task_10ms(void);
/**
 * 初始化
 */
extern void beep_init(void);

}
}

#endif // __BEEP_H__
