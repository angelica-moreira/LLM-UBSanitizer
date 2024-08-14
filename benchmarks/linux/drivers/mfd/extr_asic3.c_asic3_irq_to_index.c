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
struct asic3 {int irq_base; } ;

/* Variables and functions */

__attribute__((used)) static inline int asic3_irq_to_index(struct asic3 *asic, int irq)
{
	return (irq - asic->irq_base) & 0xf;
}