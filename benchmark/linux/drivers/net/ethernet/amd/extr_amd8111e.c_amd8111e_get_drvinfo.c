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
struct pci_dev {int dummy; } ;
struct net_device {int dummy; } ;
struct ethtool_drvinfo {int /*<<< orphan*/  bus_info; int /*<<< orphan*/  fw_version; int /*<<< orphan*/  version; int /*<<< orphan*/  driver; } ;
struct amd8111e_priv {struct pci_dev* pci_dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  MODULE_NAME ; 
 int /*<<< orphan*/  MODULE_VERS ; 
 int chip_version ; 
 struct amd8111e_priv* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  pci_name (struct pci_dev*) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void amd8111e_get_drvinfo(struct net_device *dev,
				 struct ethtool_drvinfo *info)
{
	struct amd8111e_priv *lp = netdev_priv(dev);
	struct pci_dev *pci_dev = lp->pci_dev;
	strlcpy(info->driver, MODULE_NAME, sizeof(info->driver));
	strlcpy(info->version, MODULE_VERS, sizeof(info->version));
	snprintf(info->fw_version, sizeof(info->fw_version),
		"%u", chip_version);
	strlcpy(info->bus_info, pci_name(pci_dev), sizeof(info->bus_info));
}