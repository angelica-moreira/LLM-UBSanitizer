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
struct efx_nic {int dummy; } ;

/* Variables and functions */
 int efx_ef10_pci_sriov_disable (struct efx_nic*,int) ; 
 int efx_ef10_pci_sriov_enable (struct efx_nic*,int) ; 

int efx_ef10_sriov_configure(struct efx_nic *efx, int num_vfs)
{
	if (num_vfs == 0)
		return efx_ef10_pci_sriov_disable(efx, false);
	else
		return efx_ef10_pci_sriov_enable(efx, num_vfs);
}