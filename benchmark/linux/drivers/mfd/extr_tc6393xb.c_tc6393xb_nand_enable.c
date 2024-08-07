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
struct tc6393xb {int /*<<< orphan*/  lock; scalar_t__ scr; } ;
struct TYPE_2__ {int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_1__ dev; } ;

/* Variables and functions */
 scalar_t__ SCR_GPI_BCR (int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*) ; 
 struct tc6393xb* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  tmio_iowrite8 (int,scalar_t__) ; 

__attribute__((used)) static int tc6393xb_nand_enable(struct platform_device *nand)
{
	struct tc6393xb *tc6393xb = dev_get_drvdata(nand->dev.parent);
	unsigned long flags;

	raw_spin_lock_irqsave(&tc6393xb->lock, flags);

	/* SMD buffer on */
	dev_dbg(nand->dev.parent, "SMD buffer on\n");
	tmio_iowrite8(0xff, tc6393xb->scr + SCR_GPI_BCR(1));

	raw_spin_unlock_irqrestore(&tc6393xb->lock, flags);

	return 0;
}