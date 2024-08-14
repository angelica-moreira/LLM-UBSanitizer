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
struct lio {scalar_t__ ptp_clock; } ;
struct ethtool_ts_info {int so_timestamping; int phc_index; int tx_types; int rx_filters; } ;

/* Variables and functions */
 struct lio* GET_LIO (struct net_device*) ; 
 int HWTSTAMP_FILTER_NONE ; 
 int HWTSTAMP_FILTER_PTP_V1_L4_EVENT ; 
 int HWTSTAMP_FILTER_PTP_V2_L2_EVENT ; 
 int HWTSTAMP_FILTER_PTP_V2_L4_EVENT ; 
 int HWTSTAMP_TX_OFF ; 
 int HWTSTAMP_TX_ON ; 
 int SOF_TIMESTAMPING_RAW_HARDWARE ; 
 int SOF_TIMESTAMPING_RX_HARDWARE ; 
 int SOF_TIMESTAMPING_RX_SOFTWARE ; 
 int SOF_TIMESTAMPING_SOFTWARE ; 
 int SOF_TIMESTAMPING_TX_HARDWARE ; 
 int SOF_TIMESTAMPING_TX_SOFTWARE ; 
 int ptp_clock_index (scalar_t__) ; 

__attribute__((used)) static int lio_get_ts_info(struct net_device *netdev,
			   struct ethtool_ts_info *info)
{
	struct lio *lio = GET_LIO(netdev);

	info->so_timestamping =
#ifdef PTP_HARDWARE_TIMESTAMPING
		SOF_TIMESTAMPING_TX_HARDWARE |
		SOF_TIMESTAMPING_RX_HARDWARE |
		SOF_TIMESTAMPING_RAW_HARDWARE |
		SOF_TIMESTAMPING_TX_SOFTWARE |
#endif
		SOF_TIMESTAMPING_RX_SOFTWARE |
		SOF_TIMESTAMPING_SOFTWARE;

	if (lio->ptp_clock)
		info->phc_index = ptp_clock_index(lio->ptp_clock);
	else
		info->phc_index = -1;

#ifdef PTP_HARDWARE_TIMESTAMPING
	info->tx_types = (1 << HWTSTAMP_TX_OFF) | (1 << HWTSTAMP_TX_ON);

	info->rx_filters = (1 << HWTSTAMP_FILTER_NONE) |
			   (1 << HWTSTAMP_FILTER_PTP_V1_L4_EVENT) |
			   (1 << HWTSTAMP_FILTER_PTP_V2_L2_EVENT) |
			   (1 << HWTSTAMP_FILTER_PTP_V2_L4_EVENT);
#endif

	return 0;
}