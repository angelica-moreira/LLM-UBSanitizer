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
struct ccp_device {int /*<<< orphan*/  irq_tasklet; scalar_t__ use_tasklet; int /*<<< orphan*/  total_interrupts; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  ccp5_disable_queue_interrupts (struct ccp_device*) ; 
 int /*<<< orphan*/  ccp5_irq_bh (unsigned long) ; 
 int /*<<< orphan*/  tasklet_schedule (int /*<<< orphan*/ *) ; 

__attribute__((used)) static irqreturn_t ccp5_irq_handler(int irq, void *data)
{
	struct ccp_device *ccp = (struct ccp_device *)data;

	ccp5_disable_queue_interrupts(ccp);
	ccp->total_interrupts++;
	if (ccp->use_tasklet)
		tasklet_schedule(&ccp->irq_tasklet);
	else
		ccp5_irq_bh((unsigned long)ccp);
	return IRQ_HANDLED;
}