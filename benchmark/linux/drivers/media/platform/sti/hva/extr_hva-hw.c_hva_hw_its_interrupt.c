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
struct hva_dev {scalar_t__ regs; void* sfl_reg; void* sts_reg; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 scalar_t__ HVA_HIF_FIFO_STS ; 
 scalar_t__ HVA_HIF_REG_IT_ACK ; 
 scalar_t__ HVA_HIF_REG_SFL ; 
 int /*<<< orphan*/  IRQ_WAKE_THREAD ; 
 void* readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static irqreturn_t hva_hw_its_interrupt(int irq, void *data)
{
	struct hva_dev *hva = data;

	/* read status registers */
	hva->sts_reg = readl_relaxed(hva->regs + HVA_HIF_FIFO_STS);
	hva->sfl_reg = readl_relaxed(hva->regs + HVA_HIF_REG_SFL);

	/* acknowledge interruption */
	writel_relaxed(0x1, hva->regs + HVA_HIF_REG_IT_ACK);

	return IRQ_WAKE_THREAD;
}