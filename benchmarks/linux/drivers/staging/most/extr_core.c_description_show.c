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
struct most_interface {char* description; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,char*) ; 
 struct most_interface* to_most_interface (struct device*) ; 

__attribute__((used)) static ssize_t description_show(struct device *dev,
				struct device_attribute *attr,
				char *buf)
{
	struct most_interface *iface = to_most_interface(dev);

	return snprintf(buf, PAGE_SIZE, "%s\n", iface->description);
}