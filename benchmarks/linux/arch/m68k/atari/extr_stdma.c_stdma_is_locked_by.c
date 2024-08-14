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
typedef  scalar_t__ irq_handler_t ;

/* Variables and functions */
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 scalar_t__ stdma_isr ; 
 scalar_t__ stdma_locked ; 

int stdma_is_locked_by(irq_handler_t handler)
{
	unsigned long flags;
	int result;

	local_irq_save(flags);
	result = stdma_locked && (stdma_isr == handler);
	local_irq_restore(flags);

	return result;
}