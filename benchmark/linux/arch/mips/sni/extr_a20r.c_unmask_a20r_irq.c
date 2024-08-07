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
struct irq_data {int irq; } ;

/* Variables and functions */
 int SNI_A20R_IRQ_BASE ; 
 int /*<<< orphan*/  irq_enable_hazard () ; 
 int /*<<< orphan*/  set_c0_status (int) ; 

__attribute__((used)) static inline void unmask_a20r_irq(struct irq_data *d)
{
	set_c0_status(0x100 << (d->irq - SNI_A20R_IRQ_BASE));
	irq_enable_hazard();
}