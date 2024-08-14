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
struct net_device {int dummy; } ;
struct ethtool_wolinfo {int wolopts; } ;
struct b44 {TYPE_1__* sdev; int /*<<< orphan*/  lock; int /*<<< orphan*/  flags; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  B44_FLAG_WOL_ENABLE ; 
 int WAKE_MAGIC ; 
 int /*<<< orphan*/  device_set_wakeup_enable (int /*<<< orphan*/ ,int) ; 
 struct b44* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int b44_set_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
	struct b44 *bp = netdev_priv(dev);

	spin_lock_irq(&bp->lock);
	if (wol->wolopts & WAKE_MAGIC)
		bp->flags |= B44_FLAG_WOL_ENABLE;
	else
		bp->flags &= ~B44_FLAG_WOL_ENABLE;
	spin_unlock_irq(&bp->lock);

	device_set_wakeup_enable(bp->sdev->dev, wol->wolopts & WAKE_MAGIC);
	return 0;
}