#include "beep.h"

namespace QIU {
namespace PJ0 {

#define BEEP_MAX_LEVEL (20    - 1)
#ifdef __BEEP_USE_PITCH_HZ__
// 音高的频率
// 由于提前使用算法将各个频率转化成了分频系数
// 所以这个常数数组暂时不用
const double BEEP_PITCH_HZ[84] = { 32.70, 34.65, 36.71, 38.89, 41.20, 43.65,
		46.25, 49.00, 51.91, 55.00, 58.27, 61.74, 65.41, 69.30, 73.42, 77.78,
		82.41, 87.31, 92.50, 98.00, 103.83, 110.00, 116.54, 123.47, 130.81,
		138.59, 146.83, 155.56, 164.81, 174.61, 185.00, 196.00, 207.65, 220.00,
		233.08, 246.94, 261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99,
		392.00, 415.30, 440.00, 466.16, 493.88, 523.25, 554.37, 587.33, 622.25,
		659.26, 698.46, 739.99, 783.99, 830.61, 880.00, 932.33, 987.77, 1046.50,
		1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98, 1661.22,
		1760.00, 1864.66, 1975.53, 2093.00, 2217.46, 2349.32, 2489.02, 2637.02,
		2793.83, 2959.96, 3135.96, 3322.44, 3520.00, 3729.31, 3951.07 };
#endif
const u16 BEEP_PITCH_PRESCALE[84] = { 0xD706, 0xCAEC, 0xBF89, 0xB4CC, 0xAAA9,
		0xA115, 0x9807, 0x8F7F, 0x8773, 0x7FD7, 0x78AB, 0x71E3, 0x6B7F, 0x6576,
		0x5FC4, 0x5A66, 0x5552, 0x5088, 0x4C03, 0x47BF, 0x43B8, 0x3FEC, 0x3C55,
		0x38F2, 0x35C0, 0x32BC, 0x2FE3, 0x2D33, 0x2AAA, 0x2845, 0x2602, 0x23E0,
		0x21DC, 0x1FF6, 0x1E2B, 0x1C79, 0x1AE0, 0x195E, 0x17F2, 0x1699, 0x1555,
		0x1422, 0x1301, 0x11F0, 0x10EE, 0x0FFB, 0x0F15, 0x0E3D, 0x0D70, 0x0CAF,
		0x0BF9, 0x0B4D, 0x0AAA, 0x0A11, 0x0980, 0x08F8, 0x0877, 0x07FD, 0x078B,
		0x071E, 0x06B8, 0x0657, 0x05FC, 0x05A6, 0x0555, 0x0509, 0x04C0, 0x047C,
		0x043C, 0x03FF, 0x03C5, 0x038F, 0x035C, 0x032C, 0x02FE, 0x02D3, 0x02AB,
		0x0284, 0x0260, 0x023E, 0x021E, 0x01FF, 0x01E3, 0x01C8 };
extern void beep_set_pitch(u16 index) {
	index = index >= 84 ? 84 - 12 + index % 12 : index;
	beep_set_pitch_raw(BEEP_PITCH_PRESCALE[index]);
}
extern void beep_set_pitch_raw(u16 pitch) {
	TIM3->PSC = pitch;
	TIM3->EGR = TIM_PSCReloadMode_Immediate;
}
extern void beep_set_level(u16 level) {
	level = level > BEEP_MAX_LEVEL ? BEEP_MAX_LEVEL : level;
	TIM_SetCompare2(TIM3, level);
}
// =======================================
// 是否播放
s8 beep_is_play = 0;
// 当前载入的音符序列
BNote* beep_note_array = 0;
// 当前音符序列的速度 转换为1拍多少毫秒
u16 beep_note_array_speed;
// 音符序列总长度
u32 beep_note_array_length;
// 当前音符的指针
u32 beep_note_array_pointer;
// 当前音符的节拍
u8 beep_note_current_tick;
// 用来计时的变量
u8 beep_current_counter = 0;
// =======================================

extern void beep_play(BNote* notearray, u32 len, u16 speed){
	beep_note_array = notearray;
	beep_note_array_speed = speed;
	beep_note_array_length = len;
	beep_note_array_pointer = 0;
	beep_note_current_tick = 0;
	beep_current_counter = 0;
	beep_is_play = 1;
}
extern void beep_task_10ms(void){
	if(beep_note_array == 0){
		return;
	}
	if(beep_is_play == 0){
		return;
	}
	if(beep_note_array_pointer >= beep_note_array_length){
		// 播放完了
		beep_is_play = 0;
		return;
	}
	if(++beep_current_counter < beep_note_array_speed){
		return;
	}
	beep_current_counter = 0;
	// ======== 验证通过 开始处理 ========
	// 当前音符指针
	BNote * note = beep_note_array + beep_note_array_pointer;
	if(beep_note_current_tick == 0){// 刚刚切换到这个音符
		beep_set_level(note->note_level);
		beep_set_pitch(note->note_pitch);
	}
	if(beep_note_current_tick >= note->note_ticks_avail){
		beep_set_level(0);
	}
	// ======== 处理完成之后========
	beep_note_current_tick ++;
	// 进行切换 如果这个音符结束了
	if(beep_note_current_tick >= note->note_ticks ){
		beep_note_current_tick =0;
		beep_note_array_pointer ++;
	}
	// 如果序列结束了
	if(beep_note_array_pointer >= beep_note_array_length){
		beep_set_level(0);
		beep_is_play = 0;
	}
}
extern void beep_init(void) {
	beep_set_level(0);
	beep_is_play = 0;
}

}
}
