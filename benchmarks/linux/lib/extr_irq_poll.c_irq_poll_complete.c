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
struct irq_poll {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __irq_poll_complete (struct irq_poll*) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 

void irq_poll_complete(struct irq_poll *iop)
{
	unsigned long flags;

	local_irq_save(flags);
	__irq_poll_complete(iop);
	local_irq_restore(flags);
}