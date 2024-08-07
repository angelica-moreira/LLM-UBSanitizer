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
struct TYPE_2__ {int /*<<< orphan*/  ptr; } ;
struct clockdomain {TYPE_1__ pwrdm; } ;

/* Variables and functions */
 int /*<<< orphan*/  clkdm_deny_idle_nolock (struct clockdomain*) ; 
 int /*<<< orphan*/  pwrdm_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pwrdm_unlock (int /*<<< orphan*/ ) ; 

void clkdm_deny_idle(struct clockdomain *clkdm)
{
	pwrdm_lock(clkdm->pwrdm.ptr);
	clkdm_deny_idle_nolock(clkdm);
	pwrdm_unlock(clkdm->pwrdm.ptr);
}