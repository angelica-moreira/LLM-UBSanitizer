#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct sd {int flags; TYPE_2__* vflip; TYPE_1__* hflip; } ;
struct gspca_dev {int dummy; } ;
struct TYPE_4__ {int val; } ;
struct TYPE_3__ {int val; } ;

/* Variables and functions */
 int FL_HFLIP ; 
 int FL_VFLIP ; 
 int /*<<< orphan*/  reg_w (struct gspca_dev*,int,int) ; 

__attribute__((used)) static void sethvflip(struct gspca_dev *gspca_dev)
{
	struct sd *sd = (struct sd *) gspca_dev;
	u8 data, hflip, vflip;

	hflip = sd->hflip->val;
	if (sd->flags & FL_HFLIP)
		hflip = !hflip;
	vflip = sd->vflip->val;
	if (sd->flags & FL_VFLIP)
		vflip = !vflip;

	reg_w(gspca_dev, 0xff, 0x03);			/* page 3 */
	data = (hflip ? 0x08 : 0x00) | (vflip ? 0x04 : 0x00);
	reg_w(gspca_dev, 0x21, data);

	/* load registers to sensor (Bit 0, auto clear) */
	reg_w(gspca_dev, 0x11, 0x01);
}