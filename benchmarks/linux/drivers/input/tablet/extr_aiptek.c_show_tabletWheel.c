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
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct TYPE_2__ {scalar_t__ wheel; } ;
struct aiptek {TYPE_1__ curSetting; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 scalar_t__ AIPTEK_WHEEL_DISABLE ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 struct aiptek* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,...) ; 

__attribute__((used)) static ssize_t show_tabletWheel(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct aiptek *aiptek = dev_get_drvdata(dev);

	if (aiptek->curSetting.wheel == AIPTEK_WHEEL_DISABLE) {
		return snprintf(buf, PAGE_SIZE, "disable\n");
	} else {
		return snprintf(buf, PAGE_SIZE, "%d\n",
				aiptek->curSetting.wheel);
	}
}