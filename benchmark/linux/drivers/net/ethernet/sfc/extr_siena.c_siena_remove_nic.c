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
struct efx_nic {int /*<<< orphan*/ * nic_data; int /*<<< orphan*/  irq_status; } ;

/* Variables and functions */
 int /*<<< orphan*/  RESET_TYPE_ALL ; 
 int /*<<< orphan*/  efx_mcdi_detach (struct efx_nic*) ; 
 int /*<<< orphan*/  efx_mcdi_fini (struct efx_nic*) ; 
 int /*<<< orphan*/  efx_mcdi_mon_remove (struct efx_nic*) ; 
 int /*<<< orphan*/  efx_mcdi_reset (struct efx_nic*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  efx_nic_free_buffer (struct efx_nic*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void siena_remove_nic(struct efx_nic *efx)
{
	efx_mcdi_mon_remove(efx);

	efx_nic_free_buffer(efx, &efx->irq_status);

	efx_mcdi_reset(efx, RESET_TYPE_ALL);

	efx_mcdi_detach(efx);
	efx_mcdi_fini(efx);

	/* Tear down the private nic state */
	kfree(efx->nic_data);
	efx->nic_data = NULL;
}