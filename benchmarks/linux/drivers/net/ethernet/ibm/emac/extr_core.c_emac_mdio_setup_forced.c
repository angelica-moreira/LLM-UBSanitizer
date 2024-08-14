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
struct mii_phy {int speed; int duplex; int /*<<< orphan*/  autoneg; struct net_device* dev; } ;
struct emac_instance {int /*<<< orphan*/  phy_dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  AUTONEG_DISABLE ; 
 int emac_mdio_phy_start_aneg (struct mii_phy*,int /*<<< orphan*/ ) ; 
 struct emac_instance* netdev_priv (struct net_device*) ; 

__attribute__((used)) static int emac_mdio_setup_forced(struct mii_phy *phy, int speed, int fd)
{
	struct net_device *ndev = phy->dev;
	struct emac_instance *dev = netdev_priv(ndev);

	phy->autoneg = AUTONEG_DISABLE;
	phy->speed = speed;
	phy->duplex = fd;
	return emac_mdio_phy_start_aneg(phy, dev->phy_dev);
}