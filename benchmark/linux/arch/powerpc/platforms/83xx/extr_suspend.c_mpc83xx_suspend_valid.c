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
typedef  scalar_t__ suspend_state_t ;

/* Variables and functions */
 scalar_t__ PM_SUSPEND_MEM ; 
 scalar_t__ PM_SUSPEND_STANDBY ; 

__attribute__((used)) static int mpc83xx_suspend_valid(suspend_state_t state)
{
	return state == PM_SUSPEND_STANDBY || state == PM_SUSPEND_MEM;
}