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
struct falcon_nic_data {int xmac_poll_required; } ;
struct ef4_nic {struct falcon_nic_data* nic_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  ef4_farch_filter_sync_rx_mode (struct ef4_nic*) ; 
 int /*<<< orphan*/  falcon_ack_status_intr (struct ef4_nic*) ; 
 int /*<<< orphan*/  falcon_reconfigure_mac_wrapper (struct ef4_nic*) ; 
 int /*<<< orphan*/  falcon_reconfigure_xgxs_core (struct ef4_nic*) ; 
 int /*<<< orphan*/  falcon_reconfigure_xmac_core (struct ef4_nic*) ; 
 int /*<<< orphan*/  falcon_xmac_link_ok_retry (struct ef4_nic*,int) ; 

__attribute__((used)) static int falcon_reconfigure_xmac(struct ef4_nic *efx)
{
	struct falcon_nic_data *nic_data = efx->nic_data;

	ef4_farch_filter_sync_rx_mode(efx);

	falcon_reconfigure_xgxs_core(efx);
	falcon_reconfigure_xmac_core(efx);

	falcon_reconfigure_mac_wrapper(efx);

	nic_data->xmac_poll_required = !falcon_xmac_link_ok_retry(efx, 5);
	falcon_ack_status_intr(efx);

	return 0;
}