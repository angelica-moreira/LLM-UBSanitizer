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
struct TYPE_2__ {int /*<<< orphan*/  active; } ;
struct intel_th_device {TYPE_1__ output; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  scnprintf (char*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 struct intel_th_device* to_intel_th_device (struct device*) ; 

__attribute__((used)) static ssize_t active_show(struct device *dev, struct device_attribute *attr,
			   char *buf)
{
	struct intel_th_device *thdev = to_intel_th_device(dev);

	return scnprintf(buf, PAGE_SIZE, "%d\n", thdev->output.active);
}