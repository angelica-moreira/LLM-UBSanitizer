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
struct fimc_dev {scalar_t__ regs; } ;

/* Variables and functions */
 scalar_t__ FIMC_REG_MSCTRL ; 
 int /*<<< orphan*/  FIMC_REG_MSCTRL_ENVID ; 
 int /*<<< orphan*/  readl (scalar_t__) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

void fimc_hw_activate_input_dma(struct fimc_dev *dev, bool on)
{
	u32 cfg = readl(dev->regs + FIMC_REG_MSCTRL);
	if (on)
		cfg |= FIMC_REG_MSCTRL_ENVID;
	else
		cfg &= ~FIMC_REG_MSCTRL_ENVID;
	writel(cfg, dev->regs + FIMC_REG_MSCTRL);
}