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
struct mac_device {int /*<<< orphan*/  (* adjust_link ) (struct mac_device*) ;} ;
struct dpaa_priv {struct mac_device* mac_dev; } ;

/* Variables and functions */
 struct dpaa_priv* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  stub1 (struct mac_device*) ; 

__attribute__((used)) static void dpaa_adjust_link(struct net_device *net_dev)
{
	struct mac_device *mac_dev;
	struct dpaa_priv *priv;

	priv = netdev_priv(net_dev);
	mac_dev = priv->mac_dev;
	mac_dev->adjust_link(mac_dev);
}