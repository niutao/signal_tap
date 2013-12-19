/**
 * @file st_usb.h
 * <h2>License</h2>
 * Copyright (c) 2011-2013 PITAYA TECHNLOLGY
 *
 * This source code is released for SHENZHEN PITAYA TECHNLOLGY CO., LTD 
 * under the terms of PITAYA
 *
 * @author will.niu <niutao0602@gmail.com>
 * @version v1.0
 * @date Mon Nov 25 14:46:25 CST 2013
 *
 * @brief  
 */

#ifndef __ST_USB_H__
#define __ST_USB_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#ifdef WIN32
#include "lusb0_usb.h"
#else
#include <usb.h>
#endif
#define USB_CTRL_GET_TIMEOUT    2000
#define USB_CTRL_SET_TIMEOUT    2000

struct st_usb {
	uint16_t idVendor;
	uint16_t idProduct;

	struct usb_device *dev;
	struct usb_dev_handle *handle;
};

struct st_usb *st_usb_init(void);
int st_usb_open(struct st_usb *stu);

int st_usb_find_device(struct st_usb *stu, uint16_t idVendor, uint16_t idProduct);

int st_usb_control_msg(struct st_usb *stu, int requesttype,
		int request, int value, char *data, int size, int timeout);

int st_usb_bulk_read(struct st_usb *stu, int ep, char *data, 
		int size, int timeout);

int st_usb_bulk_write(struct st_usb *stu, int ep, char *data, 
		int size, int timeout);
int st_usb_close(struct st_usb *stu);
int st_usb_exit(struct st_usb *stu);

#ifdef __cplusplus
}
#endif

#endif /* __ST_USB_H__ */

