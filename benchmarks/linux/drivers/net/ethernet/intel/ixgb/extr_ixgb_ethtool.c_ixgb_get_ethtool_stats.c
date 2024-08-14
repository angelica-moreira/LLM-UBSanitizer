#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct net_device {int dummy; } ;
struct ixgb_adapter {int dummy; } ;
struct ethtool_stats {int dummy; } ;
struct TYPE_2__ {int type; int sizeof_stat; int /*<<< orphan*/  stat_offset; } ;

/* Variables and functions */
#define  IXGB_STATS 129 
 int IXGB_STATS_LEN ; 
#define  NETDEV_STATS 128 
 TYPE_1__* ixgb_gstrings_stats ; 
 int /*<<< orphan*/  ixgb_update_stats (struct ixgb_adapter*) ; 
 struct ixgb_adapter* netdev_priv (struct net_device*) ; 

__attribute__((used)) static void
ixgb_get_ethtool_stats(struct net_device *netdev,
		struct ethtool_stats *stats, u64 *data)
{
	struct ixgb_adapter *adapter = netdev_priv(netdev);
	int i;
	char *p = NULL;

	ixgb_update_stats(adapter);
	for (i = 0; i < IXGB_STATS_LEN; i++) {
		switch (ixgb_gstrings_stats[i].type) {
		case NETDEV_STATS:
			p = (char *) netdev +
					ixgb_gstrings_stats[i].stat_offset;
			break;
		case IXGB_STATS:
			p = (char *) adapter +
					ixgb_gstrings_stats[i].stat_offset;
			break;
		}

		data[i] = (ixgb_gstrings_stats[i].sizeof_stat ==
			sizeof(u64)) ? *(u64 *)p : *(u32 *)p;
	}
}