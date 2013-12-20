/**
 * @file gen_vcd.c
 * <h2>License</h2>
 * Copyright (c) 2011-2013 PITAYA TECHNLOLGY
 *
 * This source code is released for SHENZHEN PITAYA TECHNLOLGY CO., LTD 
 * under the terms of PITAYA
 *
 * @author will.niu <niutao0602@gmail.com>
 * @version v1.0
 * @date Tue Nov 26 16:11:11 CST 2013
 *
 * @brief  
 */

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <libgen.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <vcd.h>

#define SAMPLING_RATE 62

int mkvcd(const char *name, int width)
{
	char filename[128];
	int fd, vcd;
	int ret = 0;
	int signal_len;
	struct stat st;

	sprintf(filename, "%s.hex", name);
	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		perror(filename);
		return -errno;
	}
	fstat(fd, &st);
	signal_len = st.st_size / (width / 8);

	sprintf(filename, "%s.vcd", name);
	vcd = vcd_open(filename, 1);
	if (fd == -1) {
		perror(filename);
		ret = -errno;
		goto err1;
	}

	vcd_create_date(vcd,  NULL);
	vcd_create_version(vcd,  "Signal Tap V1.0");
	vcd_create_timescale(vcd,  "1 ns");
	vcd_create_scope(vcd,  NULL);

	int i;
	char identifier[2] = {'A', 0};
	char reference[3] = {'S', 'A', 0};
	for (i = 0; i < width; i++) {
		vcd_create_var(vcd, VCD_VT_WIRE, 1, identifier,  reference);
		identifier[0]++;
		reference[1]++;
	}

	vcd_create_header_end(vcd);

	int j;
	char bin_values[128], string_values[128];
	short signal_data;
	int show = 0;
	for (i = 0; i < signal_len; i++) {
		vcd_create_time_value(vcd, i * SAMPLING_RATE);
		read(fd, &signal_data, width / 8);
		signal_data = ((signal_data >> 8) & 0xFF) | ((signal_data << 8) & 0xFF00);
		vcd_n2s((void *)&signal_data, width, string_values);

		identifier[0] = 'A';
		for (j = 0; j < width; j++) {
			sprintf(bin_values, "%c", string_values[j]);
			vcd_create_value(vcd, 1,  identifier,  bin_values);
			identifier[0]++;
		}
		show++;
		if ((show % 1000) == 0) {
			printf(".");
			fflush(stdout);
		}
	}
	vcd_close(vcd);
err1:
	close(fd);
	return ret;
}

