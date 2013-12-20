/**
 * @file mkfs.c
 * <h2>License</h2>
 * Copyright (c) 2013 ~ Niu Tao
 *
 * This source code is released for free distribution under the terms of the
 * GNU General Public License
 *
 * @author Niu Tao <niutao0602@gmail.com>
 * @version $Id
 * @date Tue 26 Nov 2013 10:46:22 PM CST
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
#include <fstapi.h>
#include "util.h"

#define SAMPLING_RATE 62

static char *mkfst_build_date(char *date)
{
	time_t now;
	struct tm *tm;

	time(&now);
	tm = localtime(&now);
	sprintf(date, "%s", asctime(tm));

	return date;
}

int mkfst(const char *name, int width)
{
	char filename[128];
	FILE *fp;
	int ret = 0;
	int signal_len;
	struct stat st;
	void *ctx = NULL;

	char buffer[4096];
	short raw_data[2048];
	uint64_t i;
	int s;
	short signal_data;
	int show = 0;
	fstHandle handle[width + 1];

	sprintf(filename, "%s.hex", name);
	fp = fopen(filename, "rb");
	if (fp == NULL) {
		perror(filename);
		return -errno;
	}
	stat(filename, &st);
	signal_len = st.st_size / (width / 8);

	sprintf(filename, "%s.fst", name);
	unlink(filename);
	ctx = fstWriterCreate(filename, 1);

	fstWriterSetPackType(ctx, FST_WR_PT_ZLIB);
	fstWriterSetRepackOnClose(ctx, 0);
	fstWriterSetParallelMode(ctx, 1);

	fstWriterSetTimescale(ctx, -9);
	fstWriterSetDate(ctx, mkfst_build_date(buffer));
	fstWriterSetVersion(ctx, "Signal Tap V1.0");

	// sampling clock
	handle[0] = fstWriterCreateVar(ctx, FST_VT_VCD_WIRE, FST_VD_IMPLICIT, 1, "BASE", 0);
	// create the signal
	for (s = 1; s <= width; s++) {
		sprintf(buffer, "S%d", s);
		handle[s] = fstWriterCreateVar(ctx, FST_VT_VCD_WIRE, FST_VD_IMPLICIT, 1, buffer, 0);
	}

	// write data
	int progress_total = signal_len / 2048;
	show = 0;
	for (i = 0; i < signal_len;) {
		int l = fread(raw_data, width / 8, 2048, fp);
		int j;
		for (j = 0; j < l; j++) {
			if (i + j != 0) {
				fstWriterEmitTimeChange(ctx, (i + j) * SAMPLING_RATE - (SAMPLING_RATE / 2));
				fstWriterEmitValueChange(ctx, handle[0], "0");
			}
			fstWriterEmitTimeChange(ctx, (i + j) * SAMPLING_RATE);
			fstWriterEmitValueChange(ctx, handle[0], "1");
			signal_data = raw_data[j];
			for (s = 0; s < width; s++) {
				fstWriterEmitValueChange(ctx, handle[s + 1], 
						(signal_data & (1 << s)) ? "1" : "0");
			}
		}

		show++;
		if (show % (progress_total / 100) == 0)
			progress_update(progress_total, show);

		i += l;
	}
	if (show % (progress_total / 100) != 0)
		progress_update(signal_len, signal_len);
	fclose(fp);
	fstWriterEmitTimeChange(ctx, signal_len * SAMPLING_RATE - (SAMPLING_RATE / 2));

	fstWriterClose(ctx);

	return ret;
}
