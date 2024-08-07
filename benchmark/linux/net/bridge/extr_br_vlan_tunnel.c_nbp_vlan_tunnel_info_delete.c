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
struct net_bridge_vlan_group {int dummy; } ;
struct net_bridge_vlan {int dummy; } ;
struct net_bridge_port {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT_RTNL () ; 
 int ENOENT ; 
 struct net_bridge_vlan* br_vlan_find (struct net_bridge_vlan_group*,int /*<<< orphan*/ ) ; 
 struct net_bridge_vlan_group* nbp_vlan_group (struct net_bridge_port*) ; 
 int /*<<< orphan*/  vlan_tunnel_info_del (struct net_bridge_vlan_group*,struct net_bridge_vlan*) ; 

int nbp_vlan_tunnel_info_delete(struct net_bridge_port *port, u16 vid)
{
	struct net_bridge_vlan_group *vg;
	struct net_bridge_vlan *v;

	ASSERT_RTNL();

	vg = nbp_vlan_group(port);
	v = br_vlan_find(vg, vid);
	if (!v)
		return -ENOENT;

	vlan_tunnel_info_del(vg, v);

	return 0;
}