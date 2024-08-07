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
struct device {int dummy; } ;

/* Variables and functions */
 struct net_device* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  netif_device_detach (struct net_device*) ; 
 scalar_t__ netif_running (struct net_device*) ; 
 int /*<<< orphan*/  smc_phy_powerdown (struct net_device*) ; 
 int /*<<< orphan*/  smc_shutdown (struct net_device*) ; 

__attribute__((used)) static int smc_drv_suspend(struct device *dev)
{
	struct net_device *ndev = dev_get_drvdata(dev);

	if (ndev) {
		if (netif_running(ndev)) {
			netif_device_detach(ndev);
			smc_shutdown(ndev);
			smc_phy_powerdown(ndev);
		}
	}
	return 0;
}