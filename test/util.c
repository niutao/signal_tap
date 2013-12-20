/**
 * @file util.c
 * <h2>License</h2>
 * Copyright (c) 2011-2013 PITAYA TECHNLOLGY
 *
 * This source code is released for SHENZHEN PITAYA TECHNLOLGY CO., LTD 
 * under the terms of PITAYA
 *
 * @author will.niu <niutao0602@gmail.com>
 * @version v1.0
 * @date Wed Nov 27 20:29:13 CST 2013
 *
 * @brief  
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void progress_update(unsigned long total_max, unsigned long total_val)
{
	double total_percent;
	int i;
	char pstr[1024];

	if (total_max < 1)
		return;

	memset(pstr, 0, 1024);
	total_percent = 100.00 * total_val / total_max;
	sprintf(pstr, "Status:%6.2f%s", total_percent, "%");
	strcat(pstr, " [");
	for (i = 0; i < total_percent / 100 * 40; i++) {
		strcat(pstr, "=");
	}
	for (; i < 40; i++) {
		strcat(pstr, " ");
	}
	strcat(pstr, "]");

	fflush(stdout);
	for (i = 0; i < (strlen(pstr) * 1.5); i++) {
		printf("\b");
	}
	printf(pstr);
	if (total_max == total_val)
		printf(" done\n");
	return;
}


