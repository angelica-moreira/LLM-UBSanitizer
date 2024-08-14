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
typedef  int u32 ;
struct net_device {int dummy; } ;
struct ioc3_private {int /*<<< orphan*/  ioc3_lock; int /*<<< orphan*/  mii; } ;

/* Variables and functions */
 int mii_link_ok (int /*<<< orphan*/ *) ; 
 struct ioc3_private* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

__attribute__((used)) static u32 ioc3_get_link(struct net_device *dev)
{
	struct ioc3_private *ip = netdev_priv(dev);
	int rc;

	spin_lock_irq(&ip->ioc3_lock);
	rc = mii_link_ok(&ip->mii);
	spin_unlock_irq(&ip->ioc3_lock);

	return rc;
}