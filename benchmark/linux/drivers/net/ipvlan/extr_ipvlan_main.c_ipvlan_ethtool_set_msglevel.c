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
typedef  int /*<<< orphan*/  u32 ;
struct net_device {int dummy; } ;
struct ipvl_dev {int /*<<< orphan*/  msg_enable; } ;

/* Variables and functions */
 struct ipvl_dev* netdev_priv (struct net_device*) ; 

__attribute__((used)) static void ipvlan_ethtool_set_msglevel(struct net_device *dev, u32 value)
{
	struct ipvl_dev *ipvlan = netdev_priv(dev);

	ipvlan->msg_enable = value;
}