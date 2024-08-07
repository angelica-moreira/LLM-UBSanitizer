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

/* Variables and functions */
 unsigned long imx_iomuxv1_readl (unsigned int) ; 
 int /*<<< orphan*/  imx_iomuxv1_writel (unsigned long,unsigned int) ; 

__attribute__((used)) static inline void imx_iomuxv1_rmwl(unsigned offset,
		unsigned long mask, unsigned long value)
{
	unsigned long reg = imx_iomuxv1_readl(offset);

	reg &= ~mask;
	reg |= value;

	imx_iomuxv1_writel(reg, offset);
}