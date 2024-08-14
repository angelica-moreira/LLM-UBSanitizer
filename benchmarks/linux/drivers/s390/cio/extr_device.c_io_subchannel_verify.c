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
struct subchannel {int dummy; } ;
struct ccw_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEV_EVENT_VERIFY ; 
 int /*<<< orphan*/  dev_fsm_event (struct ccw_device*,int /*<<< orphan*/ ) ; 
 struct ccw_device* sch_get_cdev (struct subchannel*) ; 

__attribute__((used)) static void io_subchannel_verify(struct subchannel *sch)
{
	struct ccw_device *cdev;

	cdev = sch_get_cdev(sch);
	if (cdev)
		dev_fsm_event(cdev, DEV_EVENT_VERIFY);
}