#include "memory.h"
#include "fsmc.h"
#include "gui.h"
#include "q_misc.h"
#include "systick.h"
#include "led.h"
// 这个标记用于打印调试信息
#define __MEMORY_INIT_DEBUG_INFO__

namespace QIU {
namespace PJ0 {

#ifdef __MEMORY_INIT_DEBUG_INFO__
// 这个缓冲只用于调试
s8 memory_debug_buffer[32];
#endif

// 用来存放以及管理数据的结构
typedef struct MEMORY_BUFFER_STRUCT {
	u16 BufferTag; // 标记
	u16 BufferSize; // 大小 按K计算 左移10为可以得到真正的大小
	u32 BufferPointer; // 指针
} Buffer;
#define MEMORY_BASE_ADDR  BANK1_SRAM3_ADDR
// TAG 格式 (u16)
// 0000-0000 0000-0000
// 0              000   暂定为0
//  ???                 代表第几缓冲区 000: 8K ; 001 : 4K ; 010: 2K ; 011 : 1K
//      ???? ????       代表某一缓冲区的第几个缓冲
//                   ?  代表此缓冲是否被使用 0 未被使用 1 被使用

// MEMORY 总大小 1MB(2的指数,单位KB)
#define MEMORY_SIZE_INDEX (10)
// BUFFER 管理区大小 32KB(2的指数,单位KB)
#define MEMORY_BUFFER_ARRAY_INDEX (5)
// 够用就行了 各个缓冲区的数量，不要超过0x80
#define MEM_BUFFER_8K_NUM (0x08)
#define MEM_BUFFER_4K_NUM (0x10)
#define MEM_BUFFER_2K_NUM (0x20)
#define MEM_BUFFER_1K_NUM (0x40)
// 内存管理功能是否可用 0为可用 1为内存容量不正确  2为内存读写错误
s8 memory_status = 3;
// 关于内存管理的部分
// 管理区可以存放的数据量  初始化的时候使用
s32 MemoryBufferArraySizeAll = 0;
// 管理区实际可用的数据量 运行过程中使用
s32 MemoryBufferArraySizeAvail = 0;
Buffer * MemoryBufferArray = (Buffer *) MEMORY_BASE_ADDR;

// ////////////////////////////////////////////////////////////////////////
// 下面开始函数部分
// SRAM內存检查 只能在初始化任务中使用！
// 参数用于标记检测的稀疏程度（逐字节验证实在是太慢了）
// 返回代码：
// 0 没问题
// 1 读写错误
// 2 容量错误
inline s8 memory_0_check(u8 gap_index) {
//#ifdef __MEMORY_INIT_DEBUG_INFO__
//	gui_print_next_line();
//#endif
	gap_index = gap_index > 5 ? 5 : gap_index;
	s8 * ptr = (s8*) MEMORY_BASE_ADDR;
	u32 length = 1 << 10 << MEMORY_SIZE_INDEX;
	s8 flag = 0xFE; // 验证用的第0字节
	s8 data = 0x12; // 写入SRAM的数据
	for (u32 i = 0; i < length >> gap_index; i++) {
//#ifdef __MEMORY_INIT_DEBUG_INFO__
//		misc_int2string_a(memory_debug_buffer, i << gap_index);
//		gui_clear_line(GUI_COLOR_000);
//		gui_print_inner_char(memory_debug_buffer, GUI_COLOR_888, GUI_COLOR_000);
//#endif
		//保证每次写入的数据都不一样同时保证大于0
		data++;
		data = data < 0 ? 0x12 : data; //防止溢出
		*(ptr + (i << gap_index)) = (i == 0) ? flag : data;
		// 整个内存段里面只有第一个字节是负数 如果第一个字节和现在写入的字节相等
		// 说明内存已满
		if (i != 0 && *ptr == data) {
			return 2;		//容量有问题
		}
		if (i != 0 && *(ptr + (i << gap_index)) != data) {
			return 1;		//读写错误
		}
	}
	// 能够安稳的走完整个循环说明没有问题
	return 0;
}
extern s8 memory_init(void) {
#ifdef __MEMORY_INIT_DEBUG_INFO__
	gui_print_inner_char((s8*) "Memory Testing...  ", GUI_COLOR_CCC,
	GUI_COLOR_000);
#endif
	// 0:内存检测
	memory_status = memory_0_check(5);
	if (memory_status) {
#ifdef __MEMORY_INIT_DEBUG_INFO__
		if (memory_status == 1) {
			gui_print_inner_char((s8*) "R/W ERROR!", GUI_COLOR_F88,
			GUI_COLOR_800);
		} else if (memory_status == 2) {
			gui_print_inner_char((s8*) "Size ERROR!", GUI_COLOR_F88,
			GUI_COLOR_800);
		}
		gui_print_next_line();
#endif
		return memory_status;
	}
#ifdef __MEMORY_INIT_DEBUG_INFO__
	gui_print_inner_char((s8*) "OK!", GUI_COLOR_0F0, GUI_COLOR_444);
	gui_print_next_line();
	gui_print_inner_char((s8*) "Creating Buffer...  ", GUI_COLOR_CCC,
	GUI_COLOR_000);
#endif
	// 1:管理区初始化
	MemoryBufferArraySizeAll = (1 << 10 << MEMORY_BUFFER_ARRAY_INDEX)
			/ sizeof(Buffer);
	MemoryBufferArraySizeAvail = MEM_BUFFER_8K_NUM + MEM_BUFFER_4K_NUM
			+ MEM_BUFFER_2K_NUM + MEM_BUFFER_1K_NUM;
	if (MemoryBufferArraySizeAll < MemoryBufferArraySizeAvail) {

#ifdef __MEMORY_INIT_DEBUG_INFO__
		gui_print_inner_char((s8*) "Not enough memory!", GUI_COLOR_F88,
		GUI_COLOR_800);
#endif
		gui_print_next_line();
		return 2;		//内存容量有问题
	}
	//刷空内存
	for (u32 i = 0; i < (1 << 10 << MEMORY_BUFFER_ARRAY_INDEX); i++) {
		*((s8*) (MEMORY_BASE_ADDR + i)) = 0;
	}
	// 2: 创建各个缓冲区(不刷0)
	u32 next_ptr = MEMORY_BASE_ADDR + (1 << 10 << MEMORY_BUFFER_ARRAY_INDEX);
	// 2.1: 8K缓冲
	Buffer * bufferarray = MemoryBufferArray;
	for (u32 i = 0; i < MEM_BUFFER_8K_NUM; i++) {
		(bufferarray + i)->BufferTag = 0x0000 | 0x0000 | (i << 4);
		(bufferarray + i)->BufferSize = 8;
		(bufferarray + i)->BufferPointer = next_ptr;
		next_ptr += 1 << 13;		//8K
	}
	// 2.2: 4K缓冲
	bufferarray += MEM_BUFFER_8K_NUM;
	for (u32 i = 0; i < MEM_BUFFER_4K_NUM; i++) {
		(bufferarray + i)->BufferTag = 0x0000 | 0x1000 | (i << 4);
		(bufferarray + i)->BufferSize = 4;
		(bufferarray + i)->BufferPointer = next_ptr;
		next_ptr += 1 << 12;		//4K
	}
	// 2.3: 2K缓冲
	bufferarray += MEM_BUFFER_4K_NUM;
	for (u32 i = 0; i < MEM_BUFFER_2K_NUM; i++) {
		(bufferarray + i)->BufferTag = 0x0000 | 0x2000 | (i << 4);
		(bufferarray + i)->BufferSize = 2;
		(bufferarray + i)->BufferPointer = next_ptr;
		next_ptr += 1 << 11;		//2K
	}
	// 2.4: 1K缓冲
	bufferarray += MEM_BUFFER_2K_NUM;
	for (u32 i = 0; i < MEM_BUFFER_1K_NUM; i++) {
		(bufferarray + i)->BufferTag = 0x0000 | 0x3000 | (i << 4);
		(bufferarray + i)->BufferSize = 1;
		(bufferarray + i)->BufferPointer = next_ptr;
		next_ptr += 1 << 10;		//1K
	}
#ifdef __MEMORY_INIT_DEBUG_INFO__
	gui_print_inner_char((s8*) "  OK!", GUI_COLOR_0F0, GUI_COLOR_444);
	gui_print_next_line();
#endif
	return 0;
}
extern s8 memory_free(void * pointer) {
	// 转换数据类型
	u32 _pointer = (u32) pointer;
	Buffer * buffer;
	// 查找
	for (s32 i = 0; i < MemoryBufferArraySizeAvail; i++) {
		buffer = MemoryBufferArray + i;
		// 查找匹配的指针
		if (buffer->BufferPointer == _pointer) {
			//查看是否被分配
			if (buffer->BufferTag & 0x0001) {
				// 复位
				buffer->BufferTag &= ~((u16) (0x0001));
				return 0;
			}
			return 1;		//这个内存并没有被分配出去
		}
	}
	return 2;		//没有找到这个指针的信息
}
extern void * memory_alloc_8k(void) {
	Buffer * buffer;
	for (u16 i = 0; i < MEM_BUFFER_8K_NUM; i++) {
		buffer = (MemoryBufferArray + i);
		// 如果这块buffer没有被分配
		if (!(buffer->BufferTag & 0x0001)) {
			// 标记为被分配
			buffer->BufferTag |= 0x0001;
			return (void*) (buffer->BufferPointer);
		}
	}
	// 没有结果
	return (void *) 0;
}
extern void * memory_alloc_4k(void) {
	Buffer * buffer;
	for (u16 i = 0; i < MEM_BUFFER_4K_NUM; i++) {
		buffer = (MemoryBufferArray + MEM_BUFFER_8K_NUM + i);
		// 如果这块buffer没有被分配
		if (!(buffer->BufferTag & 0x0001)) {
			// 标记为被分配
			buffer->BufferTag |= 0x0001;
			return (void*) (buffer->BufferPointer);
		}
	}
	// 没有结果
	return (void *) 0;
}
extern void * memory_alloc_2k(void) {
	Buffer * buffer;
	for (u16 i = 0; i < MEM_BUFFER_2K_NUM; i++) {
		buffer =
				(MemoryBufferArray + MEM_BUFFER_8K_NUM + MEM_BUFFER_4K_NUM + i);
		// 如果这块buffer没有被分配
		if (!(buffer->BufferTag & 0x0001)) {
			// 标记为被分配
			buffer->BufferTag |= 0x0001;
			return (void*) (buffer->BufferPointer);
		}
	}
	// 没有结果
	return (void *) 0;
}
extern void * memory_alloc_1k(void) {
	Buffer * buffer;
	for (u16 i = 0; i < MEM_BUFFER_1K_NUM; i++) {
		buffer = (MemoryBufferArray + MEM_BUFFER_8K_NUM + MEM_BUFFER_4K_NUM
				+ MEM_BUFFER_2K_NUM + i);
		// 如果这块buffer没有被分配
		if (!(buffer->BufferTag & 0x0001)) {
			// 标记为被分配
			buffer->BufferTag |= 0x0001;
			return (void*) (buffer->BufferPointer);
		}
	}
	// 没有结果
	return (void *) 0;
}
inline void memory_write_0(void* pointer, u32 length) {
	if (pointer == 0) {
		return;
	}
	s8 * p = (s8*) pointer;
	for (u32 i = 0; i < length; i++) {
		*(p + i) = 0;
	}
}
// 分配内存 8K 并将内容清空
extern void * memory_alloc0_8k(void) {
	void * p = memory_alloc_8k();
	memory_write_0(p, 8192);
	return p;
}
// 分配内存 4K 并将内容清空
extern void * memory_alloc0_4k(void) {
	void * p = memory_alloc_4k();
	memory_write_0(p, 4096);
	return p;
}
// 分配内存 2K 并将内容清空
extern void * memory_alloc0_2k(void) {
	void * p = memory_alloc_2k();
	memory_write_0(p, 2048);
	return p;
}
// 分配内存 1K 并将内容清空
extern void * memory_alloc0_1k(void) {
	void * p = memory_alloc_1k();
	memory_write_0(p, 1024);
	return p;
}

}
}

