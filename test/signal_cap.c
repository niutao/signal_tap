/**
 * @file signal_cap.c
 * <h2>License</h2>
 * Copyright (c) 2011-2013 PITAYA TECHNLOLGY
 *
 * This source code is released for SHENZHEN PITAYA TECHNLOLGY CO., LTD 
 * under the terms of PITAYA
 *
 * @author will.niu <niutao0602@gmail.com>
 * @version v1.0
 * @date Wed Dec  4 18:57:14 CST 2013
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
#include "util.h"

#define SAMPLING_RATE (16 * 1024 * 1024)

struct st_usb *g_stu;
int g_stop_flag = 1;
void sigalrm_callback(int sig)
{
	char data[128];
	g_stop_flag = 0;
	st_usb_control_msg(g_stu,
		USB_ENDPOINT_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
		ST_CMD_STOP_CAP,
		0x0,
		data,
		0,
		USB_CTRL_SET_TIMEOUT);
}
int signal_cap(int sec, int type, char *fname)
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

	signal(SIGALRM, sigalrm_callback);
	alarm(sec);

	unlink(filename);
	if ((fd = open(filename, O_WRONLY | O_CREAT, 0644)) == -1) {
		perror(filename);
		goto err1;
	}
	printf("Create capture file\n");

	st_usb_control_msg(g_stu,
		USB_ENDPOINT_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
		ST_CMD_START_CAP,
		0x0,
		data,
		0,
		USB_CTRL_SET_TIMEOUT);
	printf("Start capture\n");

	len = 1;
	int progress_total = SAMPLING_RATE * sec / 2048;
	int show = 0;

	while (len > 0) {
		len = st_usb_bulk_read(g_stu, 0x86, buffer, 2048, USB_CTRL_SET_TIMEOUT);
		write(fd, buffer, len);
		show++;
		if (show % (progress_total / 100) == 0)
			progress_update(progress_total, show);
	}

	if (show != progress_total)
		progress_update(progress_total, progress_total);

	close(fd);

	printf("Stop capture\n");

	st_usb_exit(g_stu);
	printf("Close signal tap device\n");

	printf("Convert capture stream\n");
	switch (type) {
	case 0:
	default:
		mkfst(fname, 16);
		break;
#if 0
	case 1:
		mkwlf(fname, 16);
		break;
#endif
	case 2:
		mkvcd(fname, 16);
		break;
	}
	
	return 0;
err1:
	st_usb_exit(g_stu);

	return -1;
}
