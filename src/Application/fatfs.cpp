#include "fatfs.h"
#include "sd.h"
#include "ff.h"
#include "q_misc.h"
#include "gui.h"

#define __FATFS_INIT_DEBUG_INFO__

namespace QIU {
namespace PJ0 {
#ifdef __FATFS_INIT_DEBUG_INFO__
s8 fatfs_debug_buffer[32];
#endif // __FATFS_INIT_DEBUG_INFO__
FATFS file_system_0_sd;
s8 fatfs_0_avail = 0;
extern s8 fatfs_0_is_avail(void) {
	return fatfs_0_avail;
}

extern void fatfs_init(void) {
	// SD CARD & FAT FS Initial ========================
#ifdef __FATFS_INIT_DEBUG_INFO__
	gui_print_inner_char((s8*) "Finding SD...  ", GUI_COLOR_CCC, GUI_COLOR_000);
#endif // __FATFS_INIT_DEBUG_INFO__
	s16 retry = 100;
	while (!sd_is_available()) {
		if (retry < 0) {
			break;
		}
		sd_init();
		retry--;
	}
	if (sd_is_available()) {
#ifdef __FATFS_INIT_DEBUG_INFO__
		gui_print_inner_char((s8*) "OK!", GUI_COLOR_0F0, GUI_COLOR_444);
		gui_print_next_line();
		gui_print_inner_char((s8*) "Mounting SD to \"0:\" ...",
		GUI_COLOR_CCC, GUI_COLOR_000);
#endif // __FATFS_INIT_DEBUG_INFO__
		// 如果SD卡可用 激活FATFS初始化程序
		if (f_mount(&file_system_0_sd, "0:", 1) == FR_OK) {
			fatfs_0_avail = 1;
#ifdef __FATFS_INIT_DEBUG_INFO__
			gui_print_inner_char((s8*) "OK!", GUI_COLOR_0F0, GUI_COLOR_444);
			gui_print_next_line();
#endif // __FATFS_INIT_DEBUG_INFO__
		} else {
#ifdef __FATFS_INIT_DEBUG_INFO__
			gui_print_inner_char((s8*) "FAIL! Ignore SD.", GUI_COLOR_F88,
			GUI_COLOR_800);
			gui_print_next_line();
#endif // __FATFS_INIT_DEBUG_INFO__
		}
	} else {
#ifdef __FATFS_INIT_DEBUG_INFO__
		gui_print_inner_char((s8*) "FAIL! Ignore SD.", GUI_COLOR_F88,
		GUI_COLOR_800);
		gui_print_next_line();
#endif // __FATFS_INIT_DEBUG_INFO__
	}

}
}
}
