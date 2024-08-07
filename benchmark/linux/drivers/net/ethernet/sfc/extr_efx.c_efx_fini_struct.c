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
struct efx_nic {int /*<<< orphan*/ * workqueue; int /*<<< orphan*/  vpd_sn; int /*<<< orphan*/ * channel; int /*<<< orphan*/  rps_hash_table; } ;

/* Variables and functions */
 int EFX_MAX_CHANNELS ; 
 int /*<<< orphan*/  destroy_workqueue (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void efx_fini_struct(struct efx_nic *efx)
{
	int i;

#ifdef CONFIG_RFS_ACCEL
	kfree(efx->rps_hash_table);
#endif

	for (i = 0; i < EFX_MAX_CHANNELS; i++)
		kfree(efx->channel[i]);

	kfree(efx->vpd_sn);

	if (efx->workqueue) {
		destroy_workqueue(efx->workqueue);
		efx->workqueue = NULL;
	}
}