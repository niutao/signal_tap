/**
 * @file vcd.h
 * <h2>License</h2>
 * Copyright (c) 2011-2013 PITAYA TECHNLOLGY
 *
 * This source code is released for SHENZHEN PITAYA TECHNLOLGY CO., LTD 
 * under the terms of PITAYA
 *
 * @author will.niu <niutao0602@gmail.com>
 * @version v1.0
 * @date Tue Nov 26 16:03:54 CST 2013
 *
 * @brief  
 */

#ifndef __VCD_H__
#define __VCD_H__

#include <vcd_header.h>

int vcd_open(const char *filename, int overwrite);
int vcd_close(int fd);

#endif /* __VCD_H__ */

