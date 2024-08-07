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
struct net_device_stats {scalar_t__ tx_window_errors; scalar_t__ tx_heartbeat_errors; scalar_t__ tx_fifo_errors; scalar_t__ tx_carrier_errors; scalar_t__ tx_aborted_errors; scalar_t__ rx_missed_errors; scalar_t__ rx_fifo_errors; scalar_t__ rx_frame_errors; scalar_t__ rx_crc_errors; scalar_t__ rx_over_errors; scalar_t__ rx_length_errors; scalar_t__ collisions; scalar_t__ multicast; scalar_t__ tx_dropped; scalar_t__ rx_dropped; scalar_t__ tx_errors; scalar_t__ rx_errors; scalar_t__ tx_packets; scalar_t__ rx_packets; } ;

/* Variables and functions */
 int /*<<< orphan*/  pr_debug (char*,...) ; 

__attribute__((used)) static void pr_linux_stats(struct net_device_stats *pstats)
{
  pr_debug("pr_linux_stats\n");
  pr_debug(" rx_packets=%-7ld        tx_packets=%ld\n",
	(long)pstats->rx_packets, (long)pstats->tx_packets);
  pr_debug(" rx_errors=%-7ld         tx_errors=%ld\n",
	(long)pstats->rx_errors, (long)pstats->tx_errors);
  pr_debug(" rx_dropped=%-7ld        tx_dropped=%ld\n",
	(long)pstats->rx_dropped, (long)pstats->tx_dropped);
  pr_debug(" multicast=%-7ld         collisions=%ld\n",
	(long)pstats->multicast, (long)pstats->collisions);

  pr_debug(" rx_length_errors=%-7ld  rx_over_errors=%ld\n",
	(long)pstats->rx_length_errors, (long)pstats->rx_over_errors);
  pr_debug(" rx_crc_errors=%-7ld     rx_frame_errors=%ld\n",
	(long)pstats->rx_crc_errors, (long)pstats->rx_frame_errors);
  pr_debug(" rx_fifo_errors=%-7ld    rx_missed_errors=%ld\n",
	(long)pstats->rx_fifo_errors, (long)pstats->rx_missed_errors);

  pr_debug(" tx_aborted_errors=%-7ld tx_carrier_errors=%ld\n",
	(long)pstats->tx_aborted_errors, (long)pstats->tx_carrier_errors);
  pr_debug(" tx_fifo_errors=%-7ld    tx_heartbeat_errors=%ld\n",
	(long)pstats->tx_fifo_errors, (long)pstats->tx_heartbeat_errors);
  pr_debug(" tx_window_errors=%ld\n",
	(long)pstats->tx_window_errors);
}