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
struct platform_device {int dummy; } ;
struct cplds {scalar_t__ base; int /*<<< orphan*/  irq_mask; } ;

/* Variables and functions */
 scalar_t__ FPGA_IRQ_MASK_EN ; 
 struct cplds* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static int cplds_resume(struct platform_device *pdev)
{
	struct cplds *fpga = platform_get_drvdata(pdev);

	writel(fpga->irq_mask, fpga->base + FPGA_IRQ_MASK_EN);

	return 0;
}