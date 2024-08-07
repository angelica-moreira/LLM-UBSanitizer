#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct cx231xx_i2c_xfer_data {int dev_addr; int saddr_len; int saddr_dat; int buf_size; int* p_buffer; scalar_t__ direction; } ;
struct cx231xx {int (* cx231xx_send_usb_command ) (int /*<<< orphan*/ *,struct cx231xx_i2c_xfer_data*) ;int /*<<< orphan*/ * i2c_bus; } ;

/* Variables and functions */
 int stub1 (int /*<<< orphan*/ *,struct cx231xx_i2c_xfer_data*) ; 
 int stub2 (int /*<<< orphan*/ *,struct cx231xx_i2c_xfer_data*) ; 
 int stub3 (int /*<<< orphan*/ *,struct cx231xx_i2c_xfer_data*) ; 

int cx231xx_write_i2c_master(struct cx231xx *dev, u8 dev_addr, u16 saddr,
			   u8 saddr_len, u32 data, u8 data_len, int master)
{
	int status = 0;
	u8 value[4] = { 0, 0, 0, 0 };
	struct cx231xx_i2c_xfer_data req_data;

	value[0] = (u8) data;
	value[1] = (u8) (data >> 8);
	value[2] = (u8) (data >> 16);
	value[3] = (u8) (data >> 24);

	if (saddr_len == 0)
		saddr = 0;
	else if (saddr_len == 1)
		saddr &= 0xff;

	/* prepare xfer_data struct */
	req_data.dev_addr = dev_addr >> 1;
	req_data.direction = 0;
	req_data.saddr_len = saddr_len;
	req_data.saddr_dat = saddr;
	req_data.buf_size = data_len;
	req_data.p_buffer = value;

	/* usb send command */
	if (master == 0)
		status = dev->cx231xx_send_usb_command(&dev->i2c_bus[0],
				 &req_data);
	else if (master == 1)
		status = dev->cx231xx_send_usb_command(&dev->i2c_bus[1],
				 &req_data);
	else if (master == 2)
		status = dev->cx231xx_send_usb_command(&dev->i2c_bus[2],
				 &req_data);

	return status;
}