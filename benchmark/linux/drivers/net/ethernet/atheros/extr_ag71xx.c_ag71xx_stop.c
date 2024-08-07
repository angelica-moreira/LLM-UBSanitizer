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
struct net_device {int /*<<< orphan*/  phydev; } ;
struct ag71xx {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ag71xx_hw_disable (struct ag71xx*) ; 
 struct ag71xx* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  phy_disconnect (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  phy_stop (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ag71xx_stop(struct net_device *ndev)
{
	struct ag71xx *ag = netdev_priv(ndev);

	phy_stop(ndev->phydev);
	phy_disconnect(ndev->phydev);
	ag71xx_hw_disable(ag);

	return 0;
}