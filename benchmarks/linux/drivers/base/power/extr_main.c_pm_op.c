#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct dev_pm_ops {int /*<<< orphan*/ * restore; int /*<<< orphan*/ * thaw; int /*<<< orphan*/ * poweroff; int /*<<< orphan*/ * freeze; int /*<<< orphan*/ * resume; int /*<<< orphan*/ * suspend; } ;
struct TYPE_3__ {int event; } ;
typedef  TYPE_1__ pm_message_t ;
typedef  int /*<<< orphan*/ * pm_callback_t ;

/* Variables and functions */
#define  PM_EVENT_FREEZE 135 
#define  PM_EVENT_HIBERNATE 134 
#define  PM_EVENT_QUIESCE 133 
#define  PM_EVENT_RECOVER 132 
#define  PM_EVENT_RESTORE 131 
#define  PM_EVENT_RESUME 130 
#define  PM_EVENT_SUSPEND 129 
#define  PM_EVENT_THAW 128 

__attribute__((used)) static pm_callback_t pm_op(const struct dev_pm_ops *ops, pm_message_t state)
{
	switch (state.event) {
#ifdef CONFIG_SUSPEND
	case PM_EVENT_SUSPEND:
		return ops->suspend;
	case PM_EVENT_RESUME:
		return ops->resume;
#endif /* CONFIG_SUSPEND */
#ifdef CONFIG_HIBERNATE_CALLBACKS
	case PM_EVENT_FREEZE:
	case PM_EVENT_QUIESCE:
		return ops->freeze;
	case PM_EVENT_HIBERNATE:
		return ops->poweroff;
	case PM_EVENT_THAW:
	case PM_EVENT_RECOVER:
		return ops->thaw;
		break;
	case PM_EVENT_RESTORE:
		return ops->restore;
#endif /* CONFIG_HIBERNATE_CALLBACKS */
	}

	return NULL;
}