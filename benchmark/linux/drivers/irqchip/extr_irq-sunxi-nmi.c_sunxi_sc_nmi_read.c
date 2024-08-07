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
typedef  int /*<<< orphan*/  u32 ;
struct irq_chip_generic {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  irq_reg_readl (struct irq_chip_generic*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u32 sunxi_sc_nmi_read(struct irq_chip_generic *gc, u32 off)
{
	return irq_reg_readl(gc, off);
}