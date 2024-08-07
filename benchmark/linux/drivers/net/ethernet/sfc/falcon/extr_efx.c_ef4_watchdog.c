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
struct ef4_nic {int /*<<< orphan*/  port_enabled; int /*<<< orphan*/  net_dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  RESET_TYPE_TX_WATCHDOG ; 
 int /*<<< orphan*/  ef4_schedule_reset (struct ef4_nic*,int /*<<< orphan*/ ) ; 
 struct ef4_nic* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_err (struct ef4_nic*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tx_err ; 

__attribute__((used)) static void ef4_watchdog(struct net_device *net_dev)
{
	struct ef4_nic *efx = netdev_priv(net_dev);

	netif_err(efx, tx_err, efx->net_dev,
		  "TX stuck with port_enabled=%d: resetting channels\n",
		  efx->port_enabled);

	ef4_schedule_reset(efx, RESET_TYPE_TX_WATCHDOG);
}