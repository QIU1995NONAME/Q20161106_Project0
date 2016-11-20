#include "sampling_private.h"

#include "memory.h"
#include "fatfs.h"
#include "ff.h"

namespace QIU {
namespace PJ0 {
// 采样间隔 - 1(毫秒)
u16 sampling_data_interval = 4;
// 缓冲区第一个数据
u16 sampling_data_first = 0;
// 缓冲区接下来可以用的数据区
u16 sampling_data_next_write = 0;
// 主缓冲区
SamplingData * sampling_data_buffer = 0;
// 指向SD文件的指针
FILE * sampling_data_file = 0;
// 这个文件中最多存放记录的数目(0x020000 4M多一点)
#define SAMPLING_DATA_FILE_RECORD_COUNT_MAX ((u32) 0x020000)
// 这个文件中存放了多少条记录
u32 sampling_data_file_record_count = 0;
// //////////////////////////////////////////////
//        FUNCTIONS

/**
 * 设置底层采样间隔(毫秒)
 * @param interval 采样间隔
 */
extern void sampling_data_set_interval(u16 interval) {
	if (interval < SAMPLING_DATA_INTERVAL_MIN) {
		interval = SAMPLING_DATA_INTERVAL_MIN;
	}
	if (interval > SAMPLING_DATA_INTERVAL_MAX) {
		interval = SAMPLING_DATA_INTERVAL_MAX;
	}
	sampling_data_interval = interval - 1;
}
/**
 * 获取当前底层采样间隔
 * @return 采样间隔
 */
extern u16 sampling_data_get_interval(void) {
	return sampling_data_interval + 1;
}
/**
 * 获取下一个缓存写入指针
 * 仅用于中断！要保证中断在调用了这个函数之后，必须立即把对应的数据进行赋值，否则会出现无法预知的错误。
 * @return 0 获取失败
 */
extern SamplingData * sampling_write_next(void) {
	// 如果缓冲区已经满了
	if (sampling_data_is_full()) {
		// 如果缓冲区可用
		if (sampling_data_buffer) {
			// 直接抹杀掉缓冲区最开始的数据
			sampling_data_remove_first();
		} else {
			return 0;
		}
	}
	SamplingData * psdata = sampling_data_buffer + sampling_data_next_write;
	sampling_data_next_write++;
	if (sampling_data_next_write >= SAMPLING_DATA_LENGTH_MAX) {
		sampling_data_next_write -= SAMPLING_DATA_LENGTH_MAX;
	}
	return psdata;
}
/**
 * 向文件中追加一条记录
 * @param data 记录
 * @return 0 成功
 *         其他 失败
 */
extern s8 sampling_file_append(const SamplingData * data) {
	if (data == 0) {
		return 0xFF; // 数据不能为空
	}
	if (sampling_data_file == 0) {
		return 0x60; // 文件不可用
	}
	void * buf = memory_alloc_1k();
	if (buf == 0) {
		return 0x7F; // 内存不足
	}
	// 复制数据 防止中断等抹掉数据
	memory_copy(buf, data, sizeof(SamplingData));
	f_write(sampling_data_file, buf, sizeof(SamplingData), 0);
	sampling_data_file_record_count++;
	memory_free(buf);
	if ((sampling_data_file_record_count & 0x03FF) == 0) {
		// 每插入1000多条记录时，保存一次文件
		f_sync(sampling_data_file);
	}
	if (sampling_data_file_record_count >= SAMPLING_DATA_FILE_RECORD_COUNT_MAX) {
		// 更换保存用的文件
		sampling_file_close_create();
	}
	return 0;
}
/**
 * 创建或者重新创建一个用于存储时时采样记录的文件。
 * 创建之前如果当前文件打开，则关闭。
 * @return 0 成功
 *         其它 失败
 */
extern s8 sampling_file_close_create(void) {
	// 首先SD卡必须可用
	if (!fatfs_0_is_avail()) {
		return 0xFF; //SD卡不可用
	}
	u32 res = 0;
	// 如果文件夹不存在，则创建这个用于存放历史文件的文件夹
	res = f_chdir("\\QPJ0SDH"); // QIU Project0 Sampling Data History
	// 如果不存在这个文件夹，创建之。
	if (res == FR_NO_PATH) {
		res = f_mkdir("\\QPJ0SDH");
		res = f_chdir("\\QPJ0SDH");
		if (res != FR_OK) {
			return 0x71;	//文件夹创建/切换失败
		}
	} else if (res != FR_OK) {
		return 0x71;	//文件夹创建/切换失败
	}
	// 文件夹已经成功切换
	// 如果当前有打开的文件，关之。
	if (sampling_data_file != 0) {
		f_close(sampling_data_file);
		delete sampling_data_file;
		sampling_data_file = 0;
	}
	sampling_data_file_record_count = 0;
	// 创建内存缓冲区(1K)
	void * buffer = memory_alloc_1k();
	if (buffer == 0) {
		return 0x60;	// 内存不足
	}
	char * file_name = (char *) buffer;
	// 创建一个对象
	FILE * file = new FILE();
	// 准备文件名
	for (u32 i = 0; i < 9999999; i++) {
		*(file_name + 0) = 'Q';
		*(file_name + 1) = '0' + (i % 10000000) / 1000000;
		*(file_name + 2) = '0' + (i % 1000000) / 100000;
		*(file_name + 3) = '0' + (i % 100000) / 10000;
		*(file_name + 4) = '0' + (i % 10000) / 1000;
		*(file_name + 5) = '0' + (i % 1000) / 100;
		*(file_name + 6) = '0' + (i % 100) / 10;
		*(file_name + 7) = '0' + (i % 10);
		*(file_name + 8) = '.';
		*(file_name + 9) = 'S';
		*(file_name + 10) = 'D';
		*(file_name + 11) = 'H';
		*(file_name + 12) = 0;
		// 尝试创建文件
		res = f_open(file, file_name, FA_CREATE_NEW | FA_WRITE);
		// 如果成功创建
		if (res == FR_OK) {
			sampling_data_file = file;
			break;
		}
		// 如果出错原因不是文件已经存在
		if (res != FR_EXIST) {
			delete file;
			return 0x72;	//文件创建失败
		}
	}
	// 如果没有成功创建文件
	if (sampling_data_file == 0) {
		delete file;
		return 0x72;	//文件创建失败
	}
	// 文件创建成功 写入元信息META(64字节)
	/*
	 * META信息结构：
	 *     魔数8字节 "QPJ0SDH\0"
	 *     文件版本信息 8字节(version(1).major(1).minor(2).update(4))
	 *     在这个版本中没有什么特殊的配置。预留48字节的地方
	 */
	char * meta = (char*) buffer;
	memory_copy(meta, "QPJ0SDH\0", 8);
	unsigned int pointer = 8;
	// 这么傻的代码还是需要优化滴。目前不考虑版本问题。因为只有一个版本。
	*(meta + pointer++) = 0x00;	//Version
	*(meta + pointer++) = 0x00;	//Version.Major
	*(meta + pointer++) = 0x01;	//Version.Minor0
	*(meta + pointer++) = 0x00;	//Version.Minor1
	*(meta + pointer++) = 0x00;	//Version.Update0
	*(meta + pointer++) = 0x00;	//Version.Update1
	*(meta + pointer++) = 0x00;	//Version.Update2
	*(meta + pointer++) = 0x00;	//Version.Update3
	// 刷0接下来的48字节
	memory_copy(meta, 0, 48);
	// 写入文件
	f_write(sampling_data_file, meta, 64, &pointer);
	// 文件META信息已经写好。可以投入使用
	memory_free(meta);
	return 0;
}
/**
 * 强制初始化。
 * 包括初始化一个大一些的缓冲，
 * 创建环形缓冲列表等。
 * @return 0 为初始化成功
 *         否则为初始化失败
 */
extern s8 sampling_init_0(void) {
	if (sampling_data_buffer) {
		memory_free(sampling_data_buffer);
		sampling_data_buffer = 0;
	}
	void * p = memory_alloc0_8k();
	if (!p) {
		// 内存不足
		return -1;
	}
	sampling_data_buffer = (SamplingData *) (p);
	sampling_data_first = 0;
	sampling_data_next_write = 0;
	sampling_data_interval = 4;
	return 0;
}

}
}
