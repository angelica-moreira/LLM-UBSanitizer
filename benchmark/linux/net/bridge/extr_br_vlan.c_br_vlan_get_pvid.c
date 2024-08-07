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
typedef  int /*<<< orphan*/  u16 ;
struct net_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT_RTNL () ; 
 int __br_vlan_get_pvid (struct net_device const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  br_port_get_check_rtnl (struct net_device const*) ; 

int br_vlan_get_pvid(const struct net_device *dev, u16 *p_pvid)
{
	ASSERT_RTNL();

	return __br_vlan_get_pvid(dev, br_port_get_check_rtnl(dev), p_pvid);
}