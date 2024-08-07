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
struct gspca_dev {int* usb_buf; } ;
typedef  int s32 ;

/* Variables and functions */
 int /*<<< orphan*/  reg_w (struct gspca_dev*,int) ; 

__attribute__((used)) static void setcolors(struct gspca_dev *gspca_dev, s32 val)
{
	gspca_dev->usb_buf[0] = 0x5f;
	gspca_dev->usb_buf[1] = val << 3;
	gspca_dev->usb_buf[2] = ((val >> 2) & 0xf8) | 0x04;
	reg_w(gspca_dev, 3);
}