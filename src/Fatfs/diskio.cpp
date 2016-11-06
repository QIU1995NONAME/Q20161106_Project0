/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2016        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "diskio.h"		/* FatFs lower layer API */
#include "sd.h"
using namespace QIU::PJ0;

/* Definitions of physical drive number for each drive */
#define DEV_SDCARD  (0x00)

/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status(BYTE pdrv) {
	// DSTATUS stat;
	// int result;

	switch (pdrv) {
	case DEV_SDCARD:
		if (!sd_is_available()) {
			sd_init();
		}
		if (!sd_is_available()) {
			return RES_ERROR;
		}
		return RES_OK;
	}
	return STA_NOINIT;
}

/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize(BYTE pdrv) {
	// DSTATUS stat;
	// int result;

	switch (pdrv) {
	case DEV_SDCARD:
		if (!sd_is_available()) {
			sd_init();
		}
		if (!sd_is_available()) {
			return RES_ERROR;
		}
		return RES_OK;
	}
	return STA_NOINIT;
}

/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read(BYTE pdrv, BYTE *buff, DWORD sector, UINT count) {
	// DRESULT res;
	// int result;

	switch (pdrv) {
	case DEV_SDCARD:
		if (sd_read_sector(buff, sector, count)) {
			return RES_ERROR;
		} else {
			return RES_OK;
		}
	}
	return RES_PARERR;
}

/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

DRESULT disk_write(BYTE pdrv, const BYTE *buff, DWORD sector, UINT count) {
	// DRESULT res;
	// int result;

	switch (pdrv) {
	case DEV_SDCARD:
		if (sd_write_sector(buff, sector, count)) {
			return RES_ERROR;
		} else {
			return RES_OK;
		}
	}
	return RES_PARERR;
}

/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/
// FIXME 这里是静态数据
DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void *buff) {
	DRESULT res;
	// int result;

	switch (pdrv) {
	case DEV_SDCARD:

		switch (cmd) {
		case CTRL_SYNC: //刷新磁盘
			res = RES_OK;
			break;
		case GET_SECTOR_SIZE: //得到扇区大小
			*(WORD*) buff = 512;
			res = RES_OK;
			break;
		case GET_BLOCK_SIZE: //块大小
			*(WORD*) buff = 8;
			res = RES_OK;
			break;
		case GET_SECTOR_COUNT: //扇区数
			if ((*((s32 *) buff) = sd_get_capacity()) > 0) {
				res = RES_OK;
			}
			break;
		default:
			break;
		}
		return res;
	}

	return RES_PARERR;
}

