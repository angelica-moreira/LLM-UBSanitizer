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
struct net_device {int /*<<< orphan*/ * dev_addr; } ;
struct in_ifaddr {int /*<<< orphan*/  ifa_address; } ;
struct in_device {int /*<<< orphan*/  ifa_list; } ;
struct ethhdr {scalar_t__ h_dest; scalar_t__ h_source; } ;

/* Variables and functions */
 int ETH_ALEN ; 
 struct in_device* __in_dev_get_rcu (struct net_device const*) ; 
 int /*<<< orphan*/  memcpy (scalar_t__,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  memset (scalar_t__,int,int) ; 
 struct in_ifaddr* rcu_dereference (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rcu_read_lock () ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 

__attribute__((used)) static void
plip_rewrite_address(const struct net_device *dev, struct ethhdr *eth)
{
	const struct in_device *in_dev;

	rcu_read_lock();
	in_dev = __in_dev_get_rcu(dev);
	if (in_dev) {
		/* Any address will do - we take the first */
		const struct in_ifaddr *ifa = rcu_dereference(in_dev->ifa_list);
		if (ifa) {
			memcpy(eth->h_source, dev->dev_addr, ETH_ALEN);
			memset(eth->h_dest, 0xfc, 2);
			memcpy(eth->h_dest+2, &ifa->ifa_address, 4);
		}
	}
	rcu_read_unlock();
}