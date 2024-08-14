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
typedef  int u32 ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct aspeed_wdt {scalar_t__ base; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 scalar_t__ WDT_TIMEOUT_STATUS ; 
 int WDT_TIMEOUT_STATUS_BOOT_SECONDARY ; 
 struct aspeed_wdt* dev_get_drvdata (struct device*) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

__attribute__((used)) static ssize_t access_cs0_show(struct device *dev,
			       struct device_attribute *attr, char *buf)
{
	struct aspeed_wdt *wdt = dev_get_drvdata(dev);
	u32 status = readl(wdt->base + WDT_TIMEOUT_STATUS);

	return sprintf(buf, "%u\n",
		      !(status & WDT_TIMEOUT_STATUS_BOOT_SECONDARY));
}