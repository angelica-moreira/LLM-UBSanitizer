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
typedef  int u_int ;
struct fb_var_screeninfo {int bits_per_pixel; } ;

/* Variables and functions */

__attribute__((used)) static inline u_int palette_pbs(struct fb_var_screeninfo *var)
{
	int ret = 0;
	switch (var->bits_per_pixel) {
	case 4:  ret = 0 << 12;	break;
	case 8:  ret = 1 << 12; break;
	case 16: ret = 2 << 12; break;
	}
	return ret;
}