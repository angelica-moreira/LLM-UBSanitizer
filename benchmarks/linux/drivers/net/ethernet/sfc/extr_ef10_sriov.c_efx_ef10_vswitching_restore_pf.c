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
struct efx_nic {struct efx_ef10_nic_data* nic_data; } ;
struct efx_ef10_nic_data {int must_probe_vswitching; } ;

/* Variables and functions */
 int efx_ef10_sriov_restore_vf_vswitching (struct efx_nic*) ; 
 int efx_ef10_vswitching_probe_pf (struct efx_nic*) ; 

int efx_ef10_vswitching_restore_pf(struct efx_nic *efx)
{
	struct efx_ef10_nic_data *nic_data = efx->nic_data;
	int rc;

	if (!nic_data->must_probe_vswitching)
		return 0;

	rc = efx_ef10_vswitching_probe_pf(efx);
	if (rc)
		goto fail;

	rc = efx_ef10_sriov_restore_vf_vswitching(efx);
	if (rc)
		goto fail;

	nic_data->must_probe_vswitching = false;
fail:
	return rc;
}