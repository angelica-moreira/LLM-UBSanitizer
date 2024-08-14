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
struct device_attribute {int dummy; } ;
struct device {int /*<<< orphan*/  parent; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ep93xx_rtc_get_swcomp (int /*<<< orphan*/ ,unsigned short*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sprintf (char*,char*,unsigned short) ; 

__attribute__((used)) static ssize_t comp_preload_show(struct device *dev,
				 struct device_attribute *attr, char *buf)
{
	unsigned short preload;

	ep93xx_rtc_get_swcomp(dev->parent, &preload, NULL);

	return sprintf(buf, "%d\n", preload);
}