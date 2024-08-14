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
struct mtk_ddp_comp {scalar_t__ regs; } ;

/* Variables and functions */
 unsigned int readl (scalar_t__) ; 
 int /*<<< orphan*/  writel (unsigned int,scalar_t__) ; 

__attribute__((used)) static void rdma_update_bits(struct mtk_ddp_comp *comp, unsigned int reg,
			     unsigned int mask, unsigned int val)
{
	unsigned int tmp = readl(comp->regs + reg);

	tmp = (tmp & ~mask) | (val & mask);
	writel(tmp, comp->regs + reg);
}