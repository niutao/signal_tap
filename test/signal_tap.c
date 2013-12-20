/**
 * @file signal_tap.c
 * <h2>License</h2>
 * Copyright (c) 2011-2013 PITAYA TECHNLOLGY
 *
 * This source code is released for SHENZHEN PITAYA TECHNLOLGY CO., LTD 
 * under the terms of PITAYA
 *
 * @author will.niu <niutao0602@gmail.com>
 * @version v1.0
 * @date Mon Nov 25 13:51:53 CST 2013
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
#include "project_version.h"

#include "st_usb.h"
#include "signal_tap.h"
#include "mkvcd.h"
#include "mkfst.h"

void usage(char *progname)
{
	printf("\nUsage: %s MODE [TIME] [WAVE_TYPE] FILENAME\n\n"
	       "  MODE     the operation code:\n"
	       "    0    capture the signal from device\n"
	       "    1    output the signal to device\n\n"
	       "  TIME     the time in seconds, only used in capture mode\n"
	       "  WAVE_TYPE the output type of wave file, current we support vcd,fst,wlf\n"
	       "    0    fst format\n"
	       "    1    wlf format\n"
	       "    2    vcd format\n"
	       "  FILENAME the file name which used to be save the data\n\n",
	       basename(progname)
	      );
	exit(1);
}
int main(int argc, char *argv[])
{
	int mode;

	if (argc < 3)
		usage(argv[0]);

	mode = atoi(argv[1]);
	switch (mode) {
	case 0:
		if (argc < 5)
			usage(argv[0]);
		signal_cap(atoi(argv[2]), atoi(argv[3]), argv[4]);
		break;
	case 1:
		signal_out(argv[2]);
		break;
	}
	return 0;
}
