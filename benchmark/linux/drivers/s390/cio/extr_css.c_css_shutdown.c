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
struct subchannel {TYPE_1__* driver; } ;
struct device {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* shutdown ) (struct subchannel*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct subchannel*) ; 
 struct subchannel* to_subchannel (struct device*) ; 

__attribute__((used)) static void css_shutdown(struct device *dev)
{
	struct subchannel *sch;

	sch = to_subchannel(dev);
	if (sch->driver && sch->driver->shutdown)
		sch->driver->shutdown(sch);
}