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
struct ethtool_drvinfo {int /*<<< orphan*/  bus_info; int /*<<< orphan*/  version; int /*<<< orphan*/  driver; } ;
struct atl1c_adapter {int /*<<< orphan*/  pdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  atl1c_driver_name ; 
 int /*<<< orphan*/  atl1c_driver_version ; 
 struct atl1c_adapter* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  pci_name (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void atl1c_get_drvinfo(struct net_device *netdev,
		struct ethtool_drvinfo *drvinfo)
{
	struct atl1c_adapter *adapter = netdev_priv(netdev);

	strlcpy(drvinfo->driver,  atl1c_driver_name, sizeof(drvinfo->driver));
	strlcpy(drvinfo->version, atl1c_driver_version,
		sizeof(drvinfo->version));
	strlcpy(drvinfo->bus_info, pci_name(adapter->pdev),
		sizeof(drvinfo->bus_info));
}