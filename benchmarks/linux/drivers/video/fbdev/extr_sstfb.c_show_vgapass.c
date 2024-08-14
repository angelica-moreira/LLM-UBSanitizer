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
struct sstfb_par {int vgapass; } ;
struct fb_info {struct sstfb_par* par; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 struct fb_info* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static ssize_t show_vgapass(struct device *device, struct device_attribute *attr,
			char *buf)
{
	struct fb_info *info = dev_get_drvdata(device);
	struct sstfb_par *par = info->par;
	return snprintf(buf, PAGE_SIZE, "%d\n", par->vgapass);
}