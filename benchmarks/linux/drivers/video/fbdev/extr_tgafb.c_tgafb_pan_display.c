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
struct fb_var_screeninfo {int dummy; } ;
struct fb_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  tgafb_set_par (struct fb_info*) ; 

__attribute__((used)) static int tgafb_pan_display(struct fb_var_screeninfo *var, struct fb_info *info)
{
	/* We just use this to catch switches out of graphics mode. */
	tgafb_set_par(info); /* A bit of overkill for BASE_ADDR reset. */
	return 0;
}