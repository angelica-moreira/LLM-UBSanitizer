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
struct rtnl_link_stats64 {int /*<<< orphan*/  tx_carrier_errors; scalar_t__ tx_aborted_errors; scalar_t__ rx_errors; scalar_t__ rx_crc_errors; scalar_t__ rx_frame_errors; scalar_t__ rx_over_errors; scalar_t__ rx_length_errors; int /*<<< orphan*/  collisions; int /*<<< orphan*/  multicast; scalar_t__ tx_errors; int /*<<< orphan*/  tx_bytes; int /*<<< orphan*/  rx_bytes; int /*<<< orphan*/  tx_packets; int /*<<< orphan*/  rx_packets; } ;
struct net_device {int dummy; } ;
struct b44_hw_stats {int /*<<< orphan*/  tx_carrier_lost; scalar_t__ tx_underruns; scalar_t__ rx_symbol_errs; scalar_t__ rx_align_errs; scalar_t__ rx_crc_errs; scalar_t__ rx_undersize; scalar_t__ rx_crc_align_errs; scalar_t__ rx_missed_pkts; scalar_t__ rx_oversize_pkts; scalar_t__ rx_jabber_pkts; int /*<<< orphan*/  tx_total_cols; int /*<<< orphan*/  rx_multicast_pkts; scalar_t__ tx_late_cols; scalar_t__ tx_excessive_cols; scalar_t__ tx_oversize_pkts; scalar_t__ tx_jabber_pkts; int /*<<< orphan*/  tx_octets; int /*<<< orphan*/  rx_octets; int /*<<< orphan*/  tx_pkts; int /*<<< orphan*/  rx_pkts; int /*<<< orphan*/  syncp; } ;
struct b44 {struct b44_hw_stats hw_stats; } ;

/* Variables and functions */
 struct b44* netdev_priv (struct net_device*) ; 
 unsigned int u64_stats_fetch_begin_irq (int /*<<< orphan*/ *) ; 
 scalar_t__ u64_stats_fetch_retry_irq (int /*<<< orphan*/ *,unsigned int) ; 

__attribute__((used)) static void b44_get_stats64(struct net_device *dev,
			    struct rtnl_link_stats64 *nstat)
{
	struct b44 *bp = netdev_priv(dev);
	struct b44_hw_stats *hwstat = &bp->hw_stats;
	unsigned int start;

	do {
		start = u64_stats_fetch_begin_irq(&hwstat->syncp);

		/* Convert HW stats into rtnl_link_stats64 stats. */
		nstat->rx_packets = hwstat->rx_pkts;
		nstat->tx_packets = hwstat->tx_pkts;
		nstat->rx_bytes   = hwstat->rx_octets;
		nstat->tx_bytes   = hwstat->tx_octets;
		nstat->tx_errors  = (hwstat->tx_jabber_pkts +
				     hwstat->tx_oversize_pkts +
				     hwstat->tx_underruns +
				     hwstat->tx_excessive_cols +
				     hwstat->tx_late_cols);
		nstat->multicast  = hwstat->rx_multicast_pkts;
		nstat->collisions = hwstat->tx_total_cols;

		nstat->rx_length_errors = (hwstat->rx_oversize_pkts +
					   hwstat->rx_undersize);
		nstat->rx_over_errors   = hwstat->rx_missed_pkts;
		nstat->rx_frame_errors  = hwstat->rx_align_errs;
		nstat->rx_crc_errors    = hwstat->rx_crc_errs;
		nstat->rx_errors        = (hwstat->rx_jabber_pkts +
					   hwstat->rx_oversize_pkts +
					   hwstat->rx_missed_pkts +
					   hwstat->rx_crc_align_errs +
					   hwstat->rx_undersize +
					   hwstat->rx_crc_errs +
					   hwstat->rx_align_errs +
					   hwstat->rx_symbol_errs);

		nstat->tx_aborted_errors = hwstat->tx_underruns;
#if 0
		/* Carrier lost counter seems to be broken for some devices */
		nstat->tx_carrier_errors = hwstat->tx_carrier_lost;
#endif
	} while (u64_stats_fetch_retry_irq(&hwstat->syncp, start));

}