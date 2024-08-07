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
struct irq_sim_devres {int /*<<< orphan*/  sim; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  irq_sim_fini (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void devm_irq_sim_release(struct device *dev, void *res)
{
	struct irq_sim_devres *this = res;

	irq_sim_fini(this->sim);
}