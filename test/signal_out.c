/**
 * @file signal_out.c
 * <h2>License</h2>
 * Copyright (c) 2011-2013 PITAYA TECHNLOLGY
 *
 * This source code is released for SHENZHEN PITAYA TECHNLOLGY CO., LTD 
 * under the terms of PITAYA
 *
 * @author will.niu <niutao0602@gmail.com>
 * @version v1.0
 * @date Wed Dec  4 19:03:24 CST 2013
 *
 * @brief  
 */

#include <stdio.h>
#include <stdlib.h>
#include <usb.h>
#include <libgen.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "st_usb.h"
#include "signal_tap.h"
#include "mkvcd.h"
#include "mkfst.h"

struct st_usb *g_stu;

int signal_out(char *fname)
{
	int ret;
	char data[128];
	char filename[128];

	char buffer[512 * 4];
	int len;
	int fd;

	sprintf(filename, "%s.hex", fname);

	printf("Init signal tap device\n");
	g_stu = st_usb_init();
	ret = st_usb_find_device(g_stu, ST_ID_VENDOR, ST_ID_PRODUCT);
	if (ret != 0)
		return ret;

	ret = st_usb_open(g_stu);
	if (ret != 0)
		return ret;

	if ((fd = open(filename, O_RDONLY)) == -1) {
		perror(filename);
		goto err1;
	}

	st_usb_control_msg(g_stu,
		USB_ENDPOINT_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
		ST_CMD_START_OUT,
		0x0,
		data,
		0,
		USB_CTRL_SET_TIMEOUT);
	printf("Start output the signal\n");

	len = 1;
	while (len > 0) {
		len = read(fd, buffer, 2048);
		st_usb_bulk_write(g_stu, 0x02, buffer, 2048, USB_CTRL_SET_TIMEOUT);
	}

	close(fd);
	st_usb_control_msg(g_stu,
		USB_ENDPOINT_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
		ST_CMD_STOP_OUT,
		0x0,
		data,
		0,
		USB_CTRL_SET_TIMEOUT);
	printf("Stop send\n");

	st_usb_exit(g_stu);
	printf("Close signal tap device\n");

	return 0;
err1:
	st_usb_exit(g_stu);

	return 0;
}

