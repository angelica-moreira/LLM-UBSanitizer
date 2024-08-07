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
struct ethtool_coalesce {int dummy; } ;
struct netsec_priv {struct ethtool_coalesce et_coalesce; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 struct netsec_priv* netdev_priv (struct net_device*) ; 

__attribute__((used)) static int netsec_et_get_coalesce(struct net_device *net_device,
				  struct ethtool_coalesce *et_coalesce)
{
	struct netsec_priv *priv = netdev_priv(net_device);

	*et_coalesce = priv->et_coalesce;

	return 0;
}