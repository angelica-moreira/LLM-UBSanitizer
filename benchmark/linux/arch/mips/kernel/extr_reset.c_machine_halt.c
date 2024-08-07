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

/* Variables and functions */
 int /*<<< orphan*/  _machine_halt () ; 
 int /*<<< orphan*/  machine_hang () ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  smp_send_stop () ; 

void machine_halt(void)
{
	if (_machine_halt)
		_machine_halt();

#ifdef CONFIG_SMP
	preempt_disable();
	smp_send_stop();
#endif
	machine_hang();
}