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
struct pci_dev {int dummy; } ;
struct efx_nic {int /*<<< orphan*/  net_dev; TYPE_1__* type; int /*<<< orphan*/  state; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* sriov_fini ) (struct efx_nic*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  STATE_UNINIT ; 
 int /*<<< orphan*/  dev_close (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drv ; 
 int /*<<< orphan*/  efx_disable_interrupts (struct efx_nic*) ; 
 int /*<<< orphan*/  efx_dissociate (struct efx_nic*) ; 
 int /*<<< orphan*/  efx_fini_io (struct efx_nic*) ; 
 int /*<<< orphan*/  efx_fini_struct (struct efx_nic*) ; 
 int /*<<< orphan*/  efx_mtd_remove (struct efx_nic*) ; 
 int /*<<< orphan*/  efx_pci_remove_main (struct efx_nic*) ; 
 int /*<<< orphan*/  efx_unregister_netdev (struct efx_nic*) ; 
 int /*<<< orphan*/  free_netdev (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  netif_dbg (struct efx_nic*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  pci_disable_pcie_error_reporting (struct pci_dev*) ; 
 struct efx_nic* pci_get_drvdata (struct pci_dev*) ; 
 int /*<<< orphan*/  rtnl_lock () ; 
 int /*<<< orphan*/  rtnl_unlock () ; 
 int /*<<< orphan*/  stub1 (struct efx_nic*) ; 

__attribute__((used)) static void efx_pci_remove(struct pci_dev *pci_dev)
{
	struct efx_nic *efx;

	efx = pci_get_drvdata(pci_dev);
	if (!efx)
		return;

	/* Mark the NIC as fini, then stop the interface */
	rtnl_lock();
	efx_dissociate(efx);
	dev_close(efx->net_dev);
	efx_disable_interrupts(efx);
	efx->state = STATE_UNINIT;
	rtnl_unlock();

	if (efx->type->sriov_fini)
		efx->type->sriov_fini(efx);

	efx_unregister_netdev(efx);

	efx_mtd_remove(efx);

	efx_pci_remove_main(efx);

	efx_fini_io(efx);
	netif_dbg(efx, drv, efx->net_dev, "shutdown successful\n");

	efx_fini_struct(efx);
	free_netdev(efx->net_dev);

	pci_disable_pcie_error_reporting(pci_dev);
}