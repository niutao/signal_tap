/**
 * @file vcd.c
 * <h2>License</h2>
 * Copyright (c) 2011-2013 PITAYA TECHNLOLGY
 *
 * This source code is released for SHENZHEN PITAYA TECHNLOLGY CO., LTD 
 * under the terms of PITAYA
 *
 * @author will.niu <niutao0602@gmail.com>
 * @version v1.0
 * @date Tue Nov 26 15:07:18 CST 2013
 *
 * @brief  
 */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * @brief create a file for save the vcd format data
 *
 * @param filename the file name
 * @param overwrite if the file is exist and overwrite 
 *        flag is true, the file will be delete and
 *        then create
 *
 * @return the file descriptor
 */
int vcd_open(const char *filename, int overwrite)
{
	if (!filename)
		return -EINVAL;

	if (overwrite)
		unlink(filename);

	return open(filename, O_WRONLY | O_CREAT, 0644);
}

/**
 * @brief close the vcd file
 *
 * @param fd
 *
 * @return 
 */
int vcd_close(int fd)
{
	if (fd < 0)
		return -EINVAL;

	close(fd);

	return 0;
}
