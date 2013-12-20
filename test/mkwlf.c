/**
 * @file mkwlf.c
 * <h2>License</h2>
 * Copyright (c) 2013 ~ Niu Tao
 *
 * This source code is released for free distribution under the terms of the
 * GNU General Public License
 *
 * @author Niu Tao <niutao0602@gmail.com>
 * @version $Id
 * @date Thu 05 Dec 2013 10:11:36 PM CST
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
#include "wlf_api.h"
#include "util.h"

#define SAMPLING_RATE 62

#define ST0 0xd8
#define ST1 0xd9

int mkwlf(const char *name, int width)
{
	char filename[128];
	FILE *fp;
	int signal_len;
	struct stat st;
	char buffer[4096];
	short raw_data[2048];
	uint64_t i;
	int s;
	short signal_data;
	int show = 0;
	int status;
	WlfWrtFileId wlfFile;
	WlfSymbolId root, top;
	WlfSymbolId handle[width + 1];

	sprintf(filename, "%s.hex", name);
	fp = fopen(filename, "rb");
	if (fp == NULL) {
		perror(filename);
		return -errno;
	}
	stat(filename, &st);
	signal_len = st.st_size / (width / 8);

	sprintf(filename, "%s.wlf", name);
	unlink(filename);

	/* Initialize the WLF api */
	status = wlfInit();
	if (status != WLF_OK)
		return -1;

	wlfFile = wlfWrtFileCreate(filename, WLF_TIME_RES_1NS, WLF_FILE_COMPRESSED | WLF_FILE_OPTIMIZED);

	/* Create the WLF File */
	if (wlfFile == NULL)
		return -1;

	root = wlfWrtGetRoot(wlfFile);
	top = wlfWrtCreateRegion(root, WLF_SYMBOL_PACKAGE, "top", "lib", "top", "top");

	// sampling clock
	WlfTypeId tid = wlfWrtCreateNetType(wlfFile, 0, 0, 0);
	handle[0] = wlfWrtCreateSignal(top, "BASE", tid, WLF_PORTMODE_IN, NULL);
	wlfWrtNetSetValue(handle[0], WLFWRT_LOG_START, 0, 1);
	// create the signal
	for (s = 1; s <= width; s++) {
		sprintf(buffer, "S%d", s);
		tid = wlfWrtCreateNetType(wlfFile, 0, 0, 0);
		handle[s] = wlfWrtCreateSignal(top, buffer, tid, WLF_PORTMODE_IN, NULL);
		wlfWrtNetSetValue(handle[s], WLFWRT_LOG_START, 0, 1);
	}

	//signal_len /= 20;
	// write data
	int progress_total = signal_len / 2048;
	show = 0;
	for (i = 0; i < signal_len;) {
		int l = fread(raw_data, width / 8, 2048, fp);
		int j;
		for (j = 0; j < l; j++) {
			if (i + j != 0) {
				wlfWrtNetSetValue(handle[0], WLFWRT_LOG_EVENT, 0, ST0);
				wlfWrtTimeAdvance(wlfFile, (i + j) * SAMPLING_RATE - (SAMPLING_RATE / 2), 0);
			}
			wlfWrtNetSetValue(handle[0], WLFWRT_LOG_EVENT, 0, ST1);
			signal_data = raw_data[j];
			for (s = 0; s < width; s++) {
				wlfWrtNetSetValue(handle[s + 1], WLFWRT_LOG_EVENT, 0, 
						(signal_data & (1 << s)) ? ST1 : ST0);
			}
			wlfWrtTimeAdvance(wlfFile, (i + j) * SAMPLING_RATE, 0);
		}

		show++;
		if (show % (progress_total / 100) == 0)
			progress_update(progress_total, show);

		i += l;
	}
	progress_update(signal_len, signal_len);
	fclose(fp);

	wlfWrtFileFlush(wlfFile);
	wlfWrtFileClose(wlfFile, signal_len * SAMPLING_RATE);
	return 0;
}

