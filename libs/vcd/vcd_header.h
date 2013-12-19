/**
 * @file vcd_header.h
 * <h2>License</h2>
 * Copyright (c) 2011-2013 PITAYA TECHNLOLGY
 *
 * This source code is released for SHENZHEN PITAYA TECHNLOLGY CO., LTD 
 * under the terms of PITAYA
 *
 * @author will.niu <niutao0602@gmail.com>
 * @version v1.0
 * @date Tue Nov 26 15:26:32 CST 2013
 *
 * @brief  
 */

#ifndef __VCD_HEADER_H__
#define __VCD_HEADER_H__

enum vcd_var_type {
	VCD_VT_INVAL,
	VCD_VT_EVENT,
	VCD_VT_INTEGER,
	VCD_VT_PARAMETER,
	VCD_VT_REAL,
	VCD_VT_REG,
	VCD_VT_SUPPLY0,
	VCD_VT_SUPPLY1,
	VCD_VT_TIME,
	VCD_VT_TRI,
	VCD_VT_TRIAND,
	VCD_VT_TRIOR,
	VCD_VT_TRIREG,
	VCD_VT_TRI0,
	VCD_VT_TRI1,
	VCD_VT_WAND,
	VCD_VT_WIRE,
	VCD_VT_WOR,
	VCD_VT_NUMBER
};

int vcd_create_date(int vcd, const char *date);
int vcd_create_version(int vcd, const char *version);
int vcd_create_timescale(int vcd, const char *timescale);
int vcd_create_scope(int vcd, const char *scope);
int vcd_create_var(int vcd, int var_type, int size, 
		const char *identifier, const char *reference);
int vcd_create_header_end(int vcd);
int vcd_create_time_value(int vcd, int time);
int vcd_create_value(int vcd, int size, const char *identifier, const char *bin_values);
int vcd_n2s(const unsigned char *number, int size, char *string);
#endif /* __VCD_HEADER_H__ */

