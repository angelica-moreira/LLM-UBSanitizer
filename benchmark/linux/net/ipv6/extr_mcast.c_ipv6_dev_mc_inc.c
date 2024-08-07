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
struct in6_addr {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MCAST_EXCLUDE ; 
 int __ipv6_dev_mc_inc (struct net_device*,struct in6_addr const*,int /*<<< orphan*/ ) ; 

int ipv6_dev_mc_inc(struct net_device *dev, const struct in6_addr *addr)
{
	return __ipv6_dev_mc_inc(dev, addr, MCAST_EXCLUDE);
}