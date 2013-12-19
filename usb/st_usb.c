/**
 * @file usb.c
 * <h2>License</h2>
 * Copyright (c) 2011-2013 PITAYA TECHNLOLGY
 *
 * This source code is released for SHENZHEN PITAYA TECHNLOLGY CO., LTD 
 * under the terms of PITAYA
 *
 * @author will.niu <niutao0602@gmail.com>
 * @version v1.0
 * @date Mon Nov 25 14:22:56 CST 2013
 *
 * @brief  
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include "st_usb.h"

/**
 * @brief init the lib usb
 *
 * @return st_usb init success\n
 *         NULL malloc fail
 */
struct st_usb *st_usb_init(void)
{
	struct st_usb *stu;

	usb_init();
	usb_find_busses();
	usb_find_devices();

	stu = (struct st_usb *)calloc(1, sizeof(struct st_usb));

	return stu;
}

/**
 * @brief find the usb device in usb busses
 *
 * @param idVendor the vendor id of the usb device which you want
 * @param idProduct the product id of the usb device which you want
 *
 * @return 0 success, otherwise failed
 */
int st_usb_find_device(struct st_usb *stu, uint16_t idVendor, uint16_t idProduct)
{
	struct usb_bus *bus;
	struct usb_device *dev, *dev_matched;

	if (!stu)
		return -EINVAL;

	dev_matched = NULL;

	for (bus = usb_busses; bus; bus = bus->next) {
		for (dev = bus->devices; dev; dev = dev->next) {
			if (!dev->config) {
				fprintf(stderr, " Couldn't retrieve descriptors\n");
				continue;
			}

			if (dev->descriptor.idVendor == idVendor &&
					dev->descriptor.idProduct == idProduct) {
				if (dev_matched) {
					fprintf(stderr, "two more device found\n");
					return -E2BIG;
				}
				fprintf(stdout, "device found\n");
				dev_matched = dev;
			}
		}
	}
	if (dev_matched) {
		stu->idVendor = idVendor;
		stu->idProduct = idProduct;
		stu->dev = dev_matched;
		return 0;
	} else {
		fprintf(stderr, "device not found\n");
		return -ENXIO;
	}
}

/**
 * @brief open the found usb device
 *
 * @param stu
 *
 * @return 0 success
 */
int st_usb_open(struct st_usb *stu)
{
	if (!stu || !stu->dev)
		return -EINVAL;

	stu->handle = usb_open(stu->dev);
	if (!stu->handle) {
		perror("can not open the usb device");
		return -EIO;
	}

	if (usb_claim_interface(stu->handle, 0) != 0) {
		perror("can not claim interface");
		usb_close(stu->handle);
		stu->handle = NULL;
		return -EIO;
	}

	return 0;
}

int st_usb_close(struct st_usb *stu)
{
	if (!stu)
		return -EINVAL;
	
	if (!stu->handle)
		return 0;

	usb_release_interface(stu->handle, 0);

	usb_close(stu->handle);

	stu->handle = NULL;

	return 0;

}

int st_usb_control_msg(struct st_usb *stu, int requesttype,
		int request, int value, char *data, int size, int timeout)
{
	if (!stu || !stu->handle)
		return -EINVAL;

	return usb_control_msg(stu->handle,
			requesttype,
			request,
			value,
			0,
			data,
			size,
			timeout);
}

int st_usb_bulk_read(struct st_usb *stu, int ep, char *data, 
		int size, int timeout)
{
	if (!stu || !stu->handle)
		return -EINVAL;

	return usb_bulk_read(stu->handle,
			ep,
			data,
			size,
			timeout);
}

int st_usb_bulk_write(struct st_usb *stu, int ep, char *data, 
		int size, int timeout)
{
	if (!stu || !stu->handle)
		return -EINVAL;

	return usb_bulk_write(stu->handle,
			ep,
			data,
			size,
			timeout);
}

int st_usb_exit(struct st_usb *stu)
{
	if (!stu)
		return -EINVAL;

	st_usb_close(stu);

	free(stu);

	return 0;
}
