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
struct sbmac_softc {int /*<<< orphan*/  phy_dev; } ;
struct net_device {int dummy; } ;
struct ifreq {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 struct sbmac_softc* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_running (struct net_device*) ; 
 int phy_mii_ioctl (int /*<<< orphan*/ ,struct ifreq*,int) ; 

__attribute__((used)) static int sbmac_mii_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
	struct sbmac_softc *sc = netdev_priv(dev);

	if (!netif_running(dev) || !sc->phy_dev)
		return -EINVAL;

	return phy_mii_ioctl(sc->phy_dev, rq, cmd);
}