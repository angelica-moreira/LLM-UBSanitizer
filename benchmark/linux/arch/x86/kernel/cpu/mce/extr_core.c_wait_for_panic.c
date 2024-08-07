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
struct TYPE_2__ {scalar_t__ panic_timeout; } ;

/* Variables and functions */
 long PANIC_TIMEOUT ; 
 long USEC_PER_SEC ; 
 int /*<<< orphan*/  local_irq_enable () ; 
 TYPE_1__ mca_cfg ; 
 int /*<<< orphan*/  panic (char*) ; 
 scalar_t__ panic_timeout ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static void wait_for_panic(void)
{
	long timeout = PANIC_TIMEOUT*USEC_PER_SEC;

	preempt_disable();
	local_irq_enable();
	while (timeout-- > 0)
		udelay(1);
	if (panic_timeout == 0)
		panic_timeout = mca_cfg.panic_timeout;
	panic("Panicing machine check CPU died");
}