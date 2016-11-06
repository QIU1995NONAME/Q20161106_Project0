#ifndef __MEMORY_H__
#define __MEMORY_H__

#include "stm32f10x.h"
/**
 * 由于心情以及技术等原因，并不想制作非常精细的内存管理功能
 * 这里的功能主要是用来缓冲
 * 程序运行中千万不要碰板子两边的排针
 */
namespace QIU {
namespace PJ0 {

/**
 * 内存功能初始化
 * 初始化的时候需要校验内存的大小以及是否读写正常
 * @return 0 为正常
 *         1 为初始化遇到问题
 */
extern s8 memory_init(void);
/**
 * 释放掉分配的内存
 */
extern s8 memory_free(void * pointer);
/**
 * 分配内存 8K
 */
extern void * memory_alloc_8k(void);
/**
 * 分配内存 4K
 */
extern void * memory_alloc_4k(void);
/**
 * 分配内存 2K
 */
extern void * memory_alloc_2k(void);
/**
 * 分配内存 1K
 */
extern void * memory_alloc_1k(void);
/**
 * 分配内存 8K 并将内容清空
 */
extern void * memory_alloc0_8k(void);
/**
 * 分配内存 4K 并将内容清空
 */
extern void * memory_alloc0_4k(void);
/**
 * 分配内存 2K 并将内容清空
 */
extern void * memory_alloc0_2k(void);
/**
 * 分配内存 1K 并将内容清空
 */
extern void * memory_alloc0_1k(void);

}
}

#endif // __MEMORY_H__
