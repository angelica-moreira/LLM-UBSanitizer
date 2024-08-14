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
struct ethtool_modinfo {int dummy; } ;
struct ef4_nic {int /*<<< orphan*/  mac_lock; TYPE_1__* phy_op; } ;
struct TYPE_2__ {int (* get_module_info ) (struct ef4_nic*,struct ethtool_modinfo*) ;} ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct ef4_nic* netdev_priv (struct net_device*) ; 
 int stub1 (struct ef4_nic*,struct ethtool_modinfo*) ; 

__attribute__((used)) static int ef4_ethtool_get_module_info(struct net_device *net_dev,
				       struct ethtool_modinfo *modinfo)
{
	struct ef4_nic *efx = netdev_priv(net_dev);
	int ret;

	if (!efx->phy_op || !efx->phy_op->get_module_info)
		return -EOPNOTSUPP;

	mutex_lock(&efx->mac_lock);
	ret = efx->phy_op->get_module_info(efx, modinfo);
	mutex_unlock(&efx->mac_lock);

	return ret;
}