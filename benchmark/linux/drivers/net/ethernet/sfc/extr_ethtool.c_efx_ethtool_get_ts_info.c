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
struct ethtool_ts_info {int so_timestamping; int phc_index; } ;
struct efx_nic {int dummy; } ;

/* Variables and functions */
 int SOF_TIMESTAMPING_RX_SOFTWARE ; 
 int SOF_TIMESTAMPING_SOFTWARE ; 
 int /*<<< orphan*/  efx_ptp_get_ts_info (struct efx_nic*,struct ethtool_ts_info*) ; 
 struct efx_nic* netdev_priv (struct net_device*) ; 

__attribute__((used)) static int efx_ethtool_get_ts_info(struct net_device *net_dev,
				   struct ethtool_ts_info *ts_info)
{
	struct efx_nic *efx = netdev_priv(net_dev);

	/* Software capabilities */
	ts_info->so_timestamping = (SOF_TIMESTAMPING_RX_SOFTWARE |
				    SOF_TIMESTAMPING_SOFTWARE);
	ts_info->phc_index = -1;

	efx_ptp_get_ts_info(efx, ts_info);
	return 0;
}