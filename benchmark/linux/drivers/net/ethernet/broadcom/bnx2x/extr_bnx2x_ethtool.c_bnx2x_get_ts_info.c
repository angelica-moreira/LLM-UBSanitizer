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
struct ethtool_ts_info {int so_timestamping; int phc_index; int rx_filters; int tx_types; } ;
struct bnx2x {int flags; scalar_t__ ptp_clock; } ;

/* Variables and functions */
 int HWTSTAMP_FILTER_NONE ; 
 int HWTSTAMP_FILTER_PTP_V1_L4_EVENT ; 
 int HWTSTAMP_FILTER_PTP_V2_EVENT ; 
 int HWTSTAMP_FILTER_PTP_V2_L4_EVENT ; 
 int HWTSTAMP_TX_OFF ; 
 int HWTSTAMP_TX_ON ; 
 int PTP_SUPPORTED ; 
 int SOF_TIMESTAMPING_RAW_HARDWARE ; 
 int SOF_TIMESTAMPING_RX_HARDWARE ; 
 int SOF_TIMESTAMPING_RX_SOFTWARE ; 
 int SOF_TIMESTAMPING_SOFTWARE ; 
 int SOF_TIMESTAMPING_TX_HARDWARE ; 
 int SOF_TIMESTAMPING_TX_SOFTWARE ; 
 int ethtool_op_get_ts_info (struct net_device*,struct ethtool_ts_info*) ; 
 struct bnx2x* netdev_priv (struct net_device*) ; 
 int ptp_clock_index (scalar_t__) ; 

__attribute__((used)) static int bnx2x_get_ts_info(struct net_device *dev,
			     struct ethtool_ts_info *info)
{
	struct bnx2x *bp = netdev_priv(dev);

	if (bp->flags & PTP_SUPPORTED) {
		info->so_timestamping = SOF_TIMESTAMPING_TX_SOFTWARE |
					SOF_TIMESTAMPING_RX_SOFTWARE |
					SOF_TIMESTAMPING_SOFTWARE |
					SOF_TIMESTAMPING_TX_HARDWARE |
					SOF_TIMESTAMPING_RX_HARDWARE |
					SOF_TIMESTAMPING_RAW_HARDWARE;

		if (bp->ptp_clock)
			info->phc_index = ptp_clock_index(bp->ptp_clock);
		else
			info->phc_index = -1;

		info->rx_filters = (1 << HWTSTAMP_FILTER_NONE) |
				   (1 << HWTSTAMP_FILTER_PTP_V1_L4_EVENT) |
				   (1 << HWTSTAMP_FILTER_PTP_V2_L4_EVENT) |
				   (1 << HWTSTAMP_FILTER_PTP_V2_EVENT);

		info->tx_types = (1 << HWTSTAMP_TX_OFF)|(1 << HWTSTAMP_TX_ON);

		return 0;
	}

	return ethtool_op_get_ts_info(dev, info);
}