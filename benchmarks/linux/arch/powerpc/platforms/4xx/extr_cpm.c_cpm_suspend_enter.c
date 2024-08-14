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
typedef  int suspend_state_t ;
struct TYPE_2__ {int /*<<< orphan*/  suspend; int /*<<< orphan*/  standby; } ;

/* Variables and functions */
#define  PM_SUSPEND_MEM 129 
#define  PM_SUSPEND_STANDBY 128 
 TYPE_1__ cpm ; 
 int /*<<< orphan*/  cpm_suspend_standby (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int cpm_suspend_enter(suspend_state_t state)
{
	switch (state) {
	case PM_SUSPEND_STANDBY:
		cpm_suspend_standby(cpm.standby);
		break;
	case PM_SUSPEND_MEM:
		cpm_suspend_standby(cpm.suspend);
		break;
	}

	return 0;
}