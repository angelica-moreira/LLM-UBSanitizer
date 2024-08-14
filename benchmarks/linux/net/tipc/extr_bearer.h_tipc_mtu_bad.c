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
struct net_device {scalar_t__ mtu; } ;

/* Variables and functions */
 scalar_t__ TIPC_MIN_BEARER_MTU ; 
 int /*<<< orphan*/  netdev_warn (struct net_device*,char*) ; 

__attribute__((used)) static inline bool tipc_mtu_bad(struct net_device *dev, unsigned int reserve)
{
	if (dev->mtu >= TIPC_MIN_BEARER_MTU + reserve)
		return false;
	netdev_warn(dev, "MTU too low for tipc bearer\n");
	return true;
}