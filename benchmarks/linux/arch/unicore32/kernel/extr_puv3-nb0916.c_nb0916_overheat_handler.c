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
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  machine_halt () ; 

__attribute__((used)) static irqreturn_t nb0916_overheat_handler(int irq, void *dev_id)
{
	machine_halt();
	/* SYSTEM HALT, NO RETURN */
	return IRQ_HANDLED;
}