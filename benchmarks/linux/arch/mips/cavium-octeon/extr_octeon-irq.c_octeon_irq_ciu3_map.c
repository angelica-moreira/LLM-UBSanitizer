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
typedef  int /*<<< orphan*/  irq_hw_number_t ;

/* Variables and functions */
 int /*<<< orphan*/  octeon_irq_chip_ciu3 ; 
 int octeon_irq_ciu3_mapx (struct irq_domain*,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int octeon_irq_ciu3_map(struct irq_domain *d,
			       unsigned int virq, irq_hw_number_t hw)
{
	return octeon_irq_ciu3_mapx(d, virq, hw, &octeon_irq_chip_ciu3);
}