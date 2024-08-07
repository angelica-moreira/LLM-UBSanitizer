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
struct net_device {int dummy; } ;
struct ethtool_wolinfo {int wolopts; } ;
struct amd8111e_priv {int options; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int EINVAL ; 
 int OPTION_WAKE_MAGIC_ENABLE ; 
 int OPTION_WAKE_PHY_ENABLE ; 
 int OPTION_WOL_ENABLE ; 
 int WAKE_MAGIC ; 
 int WAKE_PHY ; 
 struct amd8111e_priv* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int amd8111e_set_wol(struct net_device *dev, struct ethtool_wolinfo *wol_info)
{
	struct amd8111e_priv *lp = netdev_priv(dev);
	if (wol_info->wolopts & ~(WAKE_MAGIC|WAKE_PHY))
		return -EINVAL;
	spin_lock_irq(&lp->lock);
	if (wol_info->wolopts & WAKE_MAGIC)
		lp->options |=
			(OPTION_WOL_ENABLE | OPTION_WAKE_MAGIC_ENABLE);
	else if(wol_info->wolopts & WAKE_PHY)
		lp->options |=
			(OPTION_WOL_ENABLE | OPTION_WAKE_PHY_ENABLE);
	else
		lp->options &= ~OPTION_WOL_ENABLE;
	spin_unlock_irq(&lp->lock);
	return 0;
}