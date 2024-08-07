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
 int VIPER_HI_IRQ_STATUS ; 
 int VIPER_LO_IRQ_STATUS ; 
 int viper_irq_to_bitmask (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void viper_ack_irq(struct irq_data *d)
{
	int viper_irq = viper_irq_to_bitmask(d->irq);

	if (viper_irq & 0xff)
		VIPER_LO_IRQ_STATUS = viper_irq;
	else
		VIPER_HI_IRQ_STATUS = (viper_irq >> 8);
}