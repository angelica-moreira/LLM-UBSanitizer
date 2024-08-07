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
typedef  int /*<<< orphan*/  uint64_t ;
struct net_device {struct dsa_port* dsa_ptr; } ;
struct ethtool_stats {int dummy; } ;
struct ethtool_ops {int (* get_sset_count ) (struct net_device*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* get_ethtool_stats ) (struct net_device*,struct ethtool_stats*,int /*<<< orphan*/ *) ;} ;
struct dsa_switch {TYPE_1__* ops; } ;
struct dsa_port {int index; struct dsa_switch* ds; struct ethtool_ops* orig_ethtool_ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* get_ethtool_stats ) (struct dsa_switch*,int,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  ETH_SS_STATS ; 
 int stub1 (struct net_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (struct net_device*,struct ethtool_stats*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub3 (struct dsa_switch*,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void dsa_master_get_ethtool_stats(struct net_device *dev,
					 struct ethtool_stats *stats,
					 uint64_t *data)
{
	struct dsa_port *cpu_dp = dev->dsa_ptr;
	const struct ethtool_ops *ops = cpu_dp->orig_ethtool_ops;
	struct dsa_switch *ds = cpu_dp->ds;
	int port = cpu_dp->index;
	int count = 0;

	if (ops->get_sset_count && ops->get_ethtool_stats) {
		count = ops->get_sset_count(dev, ETH_SS_STATS);
		ops->get_ethtool_stats(dev, stats, data);
	}

	if (ds->ops->get_ethtool_stats)
		ds->ops->get_ethtool_stats(ds, port, data + count);
}