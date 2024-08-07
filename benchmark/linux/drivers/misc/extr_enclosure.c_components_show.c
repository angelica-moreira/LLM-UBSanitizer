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
struct enclosure_device {int components; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 
 struct enclosure_device* to_enclosure_device (struct device*) ; 

__attribute__((used)) static ssize_t components_show(struct device *cdev,
			       struct device_attribute *attr, char *buf)
{
	struct enclosure_device *edev = to_enclosure_device(cdev);

	return snprintf(buf, 40, "%d\n", edev->components);
}