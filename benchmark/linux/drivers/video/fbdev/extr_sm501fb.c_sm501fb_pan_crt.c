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
struct TYPE_5__ {unsigned long sm_addr; } ;
struct sm501fb_par {TYPE_2__ screen; struct sm501fb_info* info; } ;
struct sm501fb_info {scalar_t__ regs; } ;
struct fb_var_screeninfo {unsigned int xoffset; unsigned long yoffset; } ;
struct TYPE_6__ {unsigned long line_length; } ;
struct TYPE_4__ {int bits_per_pixel; } ;
struct fb_info {TYPE_3__ fix; TYPE_1__ var; struct sm501fb_par* par; } ;

/* Variables and functions */
 unsigned long SM501_ADDR_FLIP ; 
 scalar_t__ SM501_DC_CRT_CONTROL ; 
 unsigned long SM501_DC_CRT_CONTROL_PIXEL_MASK ; 
 scalar_t__ SM501_DC_CRT_FB_ADDR ; 
 int /*<<< orphan*/  sm501fb_sync_regs (struct sm501fb_info*) ; 
 unsigned long smc501_readl (scalar_t__) ; 
 int /*<<< orphan*/  smc501_writel (unsigned long,scalar_t__) ; 

__attribute__((used)) static int sm501fb_pan_crt(struct fb_var_screeninfo *var,
			   struct fb_info *info)
{
	struct sm501fb_par  *par = info->par;
	struct sm501fb_info *fbi = par->info;
	unsigned int bytes_pixel = info->var.bits_per_pixel / 8;
	unsigned long reg;
	unsigned long xoffs;

	xoffs = var->xoffset * bytes_pixel;

	reg = smc501_readl(fbi->regs + SM501_DC_CRT_CONTROL);

	reg &= ~SM501_DC_CRT_CONTROL_PIXEL_MASK;
	reg |= ((xoffs & 15) / bytes_pixel) << 4;
	smc501_writel(reg, fbi->regs + SM501_DC_CRT_CONTROL);

	reg = (par->screen.sm_addr + xoffs +
	       var->yoffset * info->fix.line_length);
	smc501_writel(reg | SM501_ADDR_FLIP, fbi->regs + SM501_DC_CRT_FB_ADDR);

	sm501fb_sync_regs(fbi);
	return 0;
}