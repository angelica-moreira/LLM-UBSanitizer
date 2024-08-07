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
struct uvesafb_par {int nocrtc; } ;
struct fb_info {struct uvesafb_par* par; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 struct fb_info* dev_get_drvdata (struct device*) ; 

__attribute__((used)) static ssize_t uvesafb_store_nocrtc(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct fb_info *info = dev_get_drvdata(dev);
	struct uvesafb_par *par = info->par;

	if (count > 0) {
		if (buf[0] == '0')
			par->nocrtc = 0;
		else
			par->nocrtc = 1;
	}
	return count;
}