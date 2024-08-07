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
struct device {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int PAGE_SIZE ; 
 scalar_t__ snprintf (char*,int,char*) ; 

__attribute__((used)) static ssize_t w1_master_attribute_show_add(struct device *dev,
	struct device_attribute *attr, char *buf)
{
	int c = PAGE_SIZE;
	c -= snprintf(buf+PAGE_SIZE - c, c,
		"write device id xx-xxxxxxxxxxxx to add slave\n");
	return PAGE_SIZE - c;
}