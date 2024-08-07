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
struct irq_data {int /*<<< orphan*/  irq; } ;

/* Variables and functions */
 int /*<<< orphan*/  zeus_irq_enabled_mask ; 
 int /*<<< orphan*/  zeus_irq_to_bitmask (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void zeus_mask_irq(struct irq_data *d)
{
	zeus_irq_enabled_mask &= ~(zeus_irq_to_bitmask(d->irq));
}