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
struct TYPE_2__ {int /*<<< orphan*/  driver; } ;
struct subchannel {TYPE_1__ dev; } ;
struct device {int dummy; } ;
struct css_driver {int (* restore ) (struct subchannel*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  css_update_ssd_info (struct subchannel*) ; 
 int stub1 (struct subchannel*) ; 
 struct css_driver* to_cssdriver (int /*<<< orphan*/ ) ; 
 struct subchannel* to_subchannel (struct device*) ; 

__attribute__((used)) static int css_pm_restore(struct device *dev)
{
	struct subchannel *sch = to_subchannel(dev);
	struct css_driver *drv;

	css_update_ssd_info(sch);
	if (!sch->dev.driver)
		return 0;
	drv = to_cssdriver(sch->dev.driver);
	return drv->restore ? drv->restore(sch) : 0;
}