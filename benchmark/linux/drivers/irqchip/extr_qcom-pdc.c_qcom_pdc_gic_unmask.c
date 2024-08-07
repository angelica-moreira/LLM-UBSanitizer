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
struct irq_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  irq_chip_unmask_parent (struct irq_data*) ; 
 int /*<<< orphan*/  pdc_enable_intr (struct irq_data*,int) ; 

__attribute__((used)) static void qcom_pdc_gic_unmask(struct irq_data *d)
{
	pdc_enable_intr(d, true);
	irq_chip_unmask_parent(d);
}