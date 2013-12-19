/**
 * @file vcd_header.c
 * <h2>License</h2>
 * Copyright (c) 2011-2013 PITAYA TECHNLOLGY
 *
 * This source code is released for SHENZHEN PITAYA TECHNLOLGY CO., LTD 
 * under the terms of PITAYA
 *
 * @author will.niu <niutao0602@gmail.com>
 * @version v1.0
 * @date Tue Nov 26 15:06:42 CST 2013
 *
 * @brief  
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "vcd_header.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

/**
 * @brief create $date
 *
 * @param vcd
 * @param date
 *
 * @return 
 */
int vcd_create_date(int vcd, const char *date)
{
	time_t now;
	struct tm *tm;
	char buffer[128];
	int len;

	if (vcd < 0)
		return -EINVAL;

	if (!date) {
		time(&now);
		tm = localtime(&now);
		len = sprintf(buffer, "$date %s $end\n", asctime(tm));
	} else {
		len = sprintf(buffer, "$date %s $end\n", date);
	}

	return write(vcd, buffer, len);
}

int vcd_create_version(int vcd, const char *version)
{
	char buffer[128];
	int len;

	if (vcd < 0)
		return -EINVAL;

	if (!version) {
		len = sprintf(buffer, "$version V1.0 $end\n");
	} else {
		len = sprintf(buffer, "$version %s $end\n", version);
	}

	return write(vcd, buffer, len);
}

int vcd_create_timescale(int vcd, const char *timescale)
{
	char buffer[128];
	int len;

	if (vcd < 0)
		return -EINVAL;

	if (!timescale) {
		len = sprintf(buffer, "$timescale 1ps $end\n");
	} else {
		len = sprintf(buffer, "$timescale %s $end\n", timescale);
	}

	return write(vcd, buffer, len);
}

int vcd_create_scope(int vcd, const char *scope)
{
	char buffer[128];
	int len;

	if (vcd < 0)
		return -EINVAL;

	if (!scope) {
		len = sprintf(buffer, "$scope module top $end\n");
	} else {
		len = sprintf(buffer, "$scope %s $end\n", scope);
	}

	return write(vcd, buffer, len);
}

int vcd_create_var(int vcd, int var_type, int size, 
		const char *identifier, const char *reference)
{
	const char *vcd_var_type_strings[] = {
		"inval",
		"event",
		"integer",
		"parameter",
		"real",
		"reg",
		"supply0",
		"supply1",
		"time",
		"tri",
		"triand",
		"trior",
		"trireg",
		"tri0",
		"tri1",
		"wand",
		"wire",
		"wor"
	};
	char buffer[128];
	int len;

	if (vcd < 0)
		return -EINVAL;

	if (var_type <= VCD_VT_INVAL || var_type >= VCD_VT_NUMBER)
		return -EINVAL;
	
	if (size <= 0 || !identifier || !reference)
		return -EINVAL;

	len = sprintf(buffer, "$var %s %d %s %s $end\n", vcd_var_type_strings[var_type],
			size, identifier, reference);

	return write(vcd, buffer, len);
}

int vcd_create_header_end(int vcd)
{
	char buffer[128];
	int len;

	if (vcd < 0)
		return -EINVAL;

	len = sprintf(buffer, 
			"$upscope $end\n"
			"$enddefinitions $end\n");

	return write(vcd, buffer, len);
}

int vcd_create_time_value(int vcd, int time)
{
	char buffer[128];
	int len;

	if (vcd < 0)
		return -EINVAL;

	len = sprintf(buffer, "#%d\n", time);

	return write(vcd, buffer, len);
}

int vcd_create_value(int vcd, int size, const char *identifier, const char *bin_values)
{
	char buffer[256];
	int len;

	if (vcd < 0)
		return -EINVAL;

	if (size <= 0 || !identifier || !bin_values)
		return -EINVAL;

	len = sprintf(buffer, "%s%s%s%s\n", 
			size == 1 ? "" : "b",
			bin_values,
			size == 1 ? "" : " ",
			identifier);

	return write(vcd, buffer, len);
}

/**
 * @brief convert the every bit of the number to binary string
 *
 * @param number
 * @param size size in bit
 * @param string output the binary string
 *
 * @return 
 */
int vcd_n2s(const unsigned char *number, int size, char *string)
{
	int i;
	int index;
	int len;
	unsigned char data;

	len = 0;

	if ((size % 8) != 0) {
		index = size / 8;
		data = number[index];
		index = size % 8 - 1;
		for (i = index; i >= 0; i--)
			len += sprintf(string + len, "%d", !!(data & (1 << i)));
		size = size / 8 * 8;		
	}

	for (index = size / 8 - 1; index >= 0; index--) {
		data = number[index];
		for (i = 7; i >= 0; i--)
			len += sprintf(string + len, "%d", !!(data & (1 << i)));
	}

	return len;
}

