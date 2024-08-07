#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct kernel_param {int dummy; } ;
struct TYPE_2__ {unsigned int cyl; unsigned int head; unsigned int sect; } ;

/* Variables and functions */
 int EINVAL ; 
 unsigned int INT_MAX ; 
 unsigned int MAX_DRIVES ; 
 unsigned int MAX_HWIFS ; 
 int ide_disks ; 
 TYPE_1__* ide_disks_chs ; 
 int sscanf (char const*,char*,unsigned int*,unsigned int*,unsigned int*,...) ; 

__attribute__((used)) static int ide_set_disk_chs(const char *str, const struct kernel_param *kp)
{
	unsigned int a, b, c = 0, h = 0, s = 0, i, j = 1;

	/* controller . device (0 or 1) : Cylinders , Heads , Sectors */
	/* controller . device (0 or 1) : 1 (use CHS) | 0 (ignore CHS) */
	if (sscanf(str, "%u.%u:%u,%u,%u", &a, &b, &c, &h, &s) != 5 &&
	    sscanf(str, "%u.%u:%u", &a, &b, &j) != 3)
		return -EINVAL;

	i = a * MAX_DRIVES + b;

	if (i >= MAX_HWIFS * MAX_DRIVES || j > 1)
		return -EINVAL;

	if (c > INT_MAX || h > 255 || s > 255)
		return -EINVAL;

	if (j)
		ide_disks |= (1 << i);
	else
		ide_disks &= ~(1 << i);

	ide_disks_chs[i].cyl  = c;
	ide_disks_chs[i].head = h;
	ide_disks_chs[i].sect = s;

	return 0;
}