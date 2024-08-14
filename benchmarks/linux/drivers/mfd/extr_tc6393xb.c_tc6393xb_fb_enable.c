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
typedef  int /*<<< orphan*/  u16 ;
struct tc6393xb {int /*<<< orphan*/  lock; scalar_t__ scr; } ;
struct TYPE_2__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; } ;

/* Variables and functions */
 scalar_t__ SCR_CCR ; 
 int /*<<< orphan*/  SCR_CCR_MCLK_48 ; 
 int /*<<< orphan*/  SCR_CCR_MCLK_MASK ; 
 struct tc6393xb* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  tmio_ioread16 (scalar_t__) ; 
 int /*<<< orphan*/  tmio_iowrite16 (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static int tc6393xb_fb_enable(struct platform_device *dev)
{
	struct tc6393xb *tc6393xb = dev_get_drvdata(dev->dev.parent);
	unsigned long flags;
	u16 ccr;

	raw_spin_lock_irqsave(&tc6393xb->lock, flags);

	ccr = tmio_ioread16(tc6393xb->scr + SCR_CCR);
	ccr &= ~SCR_CCR_MCLK_MASK;
	ccr |= SCR_CCR_MCLK_48;
	tmio_iowrite16(ccr, tc6393xb->scr + SCR_CCR);

	raw_spin_unlock_irqrestore(&tc6393xb->lock, flags);

	return 0;
}