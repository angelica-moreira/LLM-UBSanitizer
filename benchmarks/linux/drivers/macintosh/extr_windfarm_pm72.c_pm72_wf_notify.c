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
struct notifier_block {int dummy; } ;

/* Variables and functions */
#define  WF_EVENT_NEW_CONTROL 130 
#define  WF_EVENT_NEW_SENSOR 129 
#define  WF_EVENT_TICK 128 
 int /*<<< orphan*/  have_all_controls ; 
 int /*<<< orphan*/  have_all_sensors ; 
 int /*<<< orphan*/  pm72_new_control (void*) ; 
 int /*<<< orphan*/  pm72_new_sensor (void*) ; 
 int /*<<< orphan*/  pm72_tick () ; 

__attribute__((used)) static int pm72_wf_notify(struct notifier_block *self,
			  unsigned long event, void *data)
{
	switch (event) {
	case WF_EVENT_NEW_SENSOR:
		pm72_new_sensor(data);
		break;
	case WF_EVENT_NEW_CONTROL:
		pm72_new_control(data);
		break;
	case WF_EVENT_TICK:
		if (have_all_controls && have_all_sensors)
			pm72_tick();
	}
	return 0;
}