#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct skd_device {int /*<<< orphan*/  lock; TYPE_1__* pdev; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  FIT_INT_STATUS_HOST ; 
 int /*<<< orphan*/  FIT_ISH_FW_STATE_CHANGE ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  SKD_READL (struct skd_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SKD_WRITEL (struct skd_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skd_isr_fwstate (struct skd_device*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static irqreturn_t skd_statec_isr(int irq, void *skd_host_data)
{
	struct skd_device *skdev = skd_host_data;
	unsigned long flags;

	spin_lock_irqsave(&skdev->lock, flags);
	dev_dbg(&skdev->pdev->dev, "MSIX = 0x%x\n",
		SKD_READL(skdev, FIT_INT_STATUS_HOST));
	SKD_WRITEL(skdev, FIT_ISH_FW_STATE_CHANGE, FIT_INT_STATUS_HOST);
	skd_isr_fwstate(skdev);
	spin_unlock_irqrestore(&skdev->lock, flags);
	return IRQ_HANDLED;
}