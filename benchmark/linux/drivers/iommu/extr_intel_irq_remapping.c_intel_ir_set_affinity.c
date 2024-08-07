#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct irq_data {TYPE_1__* chip; struct irq_data* parent_data; } ;
struct irq_cfg {int dummy; } ;
struct cpumask {int dummy; } ;
struct TYPE_2__ {int (* irq_set_affinity ) (struct irq_data*,struct cpumask const*,int) ;} ;

/* Variables and functions */
 int IRQ_SET_MASK_OK_DONE ; 
 int /*<<< orphan*/  intel_ir_reconfigure_irte (struct irq_data*,int) ; 
 struct irq_cfg* irqd_cfg (struct irq_data*) ; 
 int /*<<< orphan*/  send_cleanup_vector (struct irq_cfg*) ; 
 int stub1 (struct irq_data*,struct cpumask const*,int) ; 

__attribute__((used)) static int
intel_ir_set_affinity(struct irq_data *data, const struct cpumask *mask,
		      bool force)
{
	struct irq_data *parent = data->parent_data;
	struct irq_cfg *cfg = irqd_cfg(data);
	int ret;

	ret = parent->chip->irq_set_affinity(parent, mask, force);
	if (ret < 0 || ret == IRQ_SET_MASK_OK_DONE)
		return ret;

	intel_ir_reconfigure_irte(data, false);
	/*
	 * After this point, all the interrupts will start arriving
	 * at the new destination. So, time to cleanup the previous
	 * vector allocation.
	 */
	send_cleanup_vector(cfg);

	return IRQ_SET_MASK_OK_DONE;
}