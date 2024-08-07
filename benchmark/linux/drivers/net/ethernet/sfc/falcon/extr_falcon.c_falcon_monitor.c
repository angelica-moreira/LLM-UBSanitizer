#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct ef4_nic {TYPE_2__* phy_op; int /*<<< orphan*/  phy_mode; int /*<<< orphan*/  net_dev; int /*<<< orphan*/  mac_lock; } ;
struct TYPE_6__ {TYPE_1__* type; } ;
struct TYPE_5__ {int (* poll ) (struct ef4_nic*) ;} ;
struct TYPE_4__ {int (* monitor ) (struct ef4_nic*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int ERANGE ; 
 scalar_t__ LOOPBACK_INTERNAL (struct ef4_nic*) ; 
 int /*<<< orphan*/  PHY_MODE_LOW_POWER ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int __ef4_reconfigure_port (struct ef4_nic*) ; 
 int /*<<< orphan*/  ef4_link_status_changed (struct ef4_nic*) ; 
 TYPE_3__* falcon_board (struct ef4_nic*) ; 
 int /*<<< orphan*/  falcon_deconfigure_mac_wrapper (struct ef4_nic*) ; 
 int falcon_loopback_link_poll (struct ef4_nic*) ; 
 int /*<<< orphan*/  falcon_poll_xmac (struct ef4_nic*) ; 
 int falcon_reconfigure_xmac (struct ef4_nic*) ; 
 int /*<<< orphan*/  falcon_reset_macs (struct ef4_nic*) ; 
 int /*<<< orphan*/  falcon_start_nic_stats (struct ef4_nic*) ; 
 int /*<<< orphan*/  falcon_stop_nic_stats (struct ef4_nic*) ; 
 int /*<<< orphan*/  hw ; 
 int /*<<< orphan*/  mutex_is_locked (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  netif_err (struct ef4_nic*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,char*) ; 
 int stub1 (struct ef4_nic*) ; 
 int stub2 (struct ef4_nic*) ; 

__attribute__((used)) static void falcon_monitor(struct ef4_nic *efx)
{
	bool link_changed;
	int rc;

	BUG_ON(!mutex_is_locked(&efx->mac_lock));

	rc = falcon_board(efx)->type->monitor(efx);
	if (rc) {
		netif_err(efx, hw, efx->net_dev,
			  "Board sensor %s; shutting down PHY\n",
			  (rc == -ERANGE) ? "reported fault" : "failed");
		efx->phy_mode |= PHY_MODE_LOW_POWER;
		rc = __ef4_reconfigure_port(efx);
		WARN_ON(rc);
	}

	if (LOOPBACK_INTERNAL(efx))
		link_changed = falcon_loopback_link_poll(efx);
	else
		link_changed = efx->phy_op->poll(efx);

	if (link_changed) {
		falcon_stop_nic_stats(efx);
		falcon_deconfigure_mac_wrapper(efx);

		falcon_reset_macs(efx);
		rc = falcon_reconfigure_xmac(efx);
		BUG_ON(rc);

		falcon_start_nic_stats(efx);

		ef4_link_status_changed(efx);
	}

	falcon_poll_xmac(efx);
}