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
struct AdapterControlBlock {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  arcmsr_interrupt (struct AdapterControlBlock*) ; 

__attribute__((used)) static irqreturn_t arcmsr_do_interrupt(int irq, void *dev_id)
{
	irqreturn_t handle_state;
	struct AdapterControlBlock *acb = dev_id;

	handle_state = arcmsr_interrupt(acb);
	return handle_state;
}