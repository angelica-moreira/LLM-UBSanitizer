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
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_WAKE_THREAD ; 
 int /*<<< orphan*/  disable_irq_nosync (int) ; 

__attribute__((used)) static irqreturn_t armada_overheat_isr(int irq, void *blob)
{
	/*
	 * Disable the IRQ and continue in thread context (thermal core
	 * notification and temperature monitoring).
	 */
	disable_irq_nosync(irq);

	return IRQ_WAKE_THREAD;
}