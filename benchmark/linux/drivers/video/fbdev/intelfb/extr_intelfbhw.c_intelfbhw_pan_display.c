#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_6__ {int pan_offset; int pan_display; } ;
struct TYPE_5__ {int offset; } ;
struct intelfb_info {int pitch; TYPE_3__ vsync; TYPE_2__ fb; } ;
struct fb_var_screeninfo {int yoffset; int activate; int /*<<< orphan*/  xoffset; } ;
struct TYPE_4__ {scalar_t__ xres; scalar_t__ xres_virtual; scalar_t__ yres; scalar_t__ yres_virtual; int bits_per_pixel; } ;
struct fb_info {TYPE_1__ var; } ;

/* Variables and functions */
 int /*<<< orphan*/  DBG_MSG (char*) ; 
 int /*<<< orphan*/  DSPABASE ; 
 int EINVAL ; 
 int FB_ACTIVATE_VBL ; 
 struct intelfb_info* GET_DINFO (struct fb_info*) ; 
 int /*<<< orphan*/  OUTREG (int /*<<< orphan*/ ,int) ; 
 int ROUND_DOWN_TO (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  intelfbhw_enable_irq (struct intelfb_info*) ; 

int intelfbhw_pan_display(struct fb_var_screeninfo *var, struct fb_info *info)
{
	struct intelfb_info *dinfo = GET_DINFO(info);
	u32 offset, xoffset, yoffset;

#if VERBOSE > 0
	DBG_MSG("intelfbhw_pan_display\n");
#endif

	xoffset = ROUND_DOWN_TO(var->xoffset, 8);
	yoffset = var->yoffset;

	if ((xoffset + info->var.xres > info->var.xres_virtual) ||
	    (yoffset + info->var.yres > info->var.yres_virtual))
		return -EINVAL;

	offset = (yoffset * dinfo->pitch) +
		 (xoffset * info->var.bits_per_pixel) / 8;

	offset += dinfo->fb.offset << 12;

	dinfo->vsync.pan_offset = offset;
	if ((var->activate & FB_ACTIVATE_VBL) &&
	    !intelfbhw_enable_irq(dinfo))
		dinfo->vsync.pan_display = 1;
	else {
		dinfo->vsync.pan_display = 0;
		OUTREG(DSPABASE, offset);
	}

	return 0;
}