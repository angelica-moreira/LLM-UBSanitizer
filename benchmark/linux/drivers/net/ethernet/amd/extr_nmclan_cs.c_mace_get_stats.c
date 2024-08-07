#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct net_device_stats {int dummy; } ;
struct net_device {struct net_device_stats stats; int /*<<< orphan*/  name; int /*<<< orphan*/  base_addr; } ;
struct TYPE_3__ {int /*<<< orphan*/  mace_stats; } ;
typedef  TYPE_1__ mace_private ;

/* Variables and functions */
 TYPE_1__* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  pr_debug (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_linux_stats (struct net_device_stats*) ; 
 int /*<<< orphan*/  pr_mace_stats (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  update_stats (int /*<<< orphan*/ ,struct net_device*) ; 

__attribute__((used)) static struct net_device_stats *mace_get_stats(struct net_device *dev)
{
  mace_private *lp = netdev_priv(dev);

  update_stats(dev->base_addr, dev);

  pr_debug("%s: updating the statistics.\n", dev->name);
  pr_linux_stats(&dev->stats);
  pr_mace_stats(&lp->mace_stats);

  return &dev->stats;
}