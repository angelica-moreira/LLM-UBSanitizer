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
struct irq_domain {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  irq_domain_remove (struct irq_domain*) ; 

__attribute__((used)) static void stm32_exti_remove_irq(void *data)
{
	struct irq_domain *domain = data;

	irq_domain_remove(domain);
}