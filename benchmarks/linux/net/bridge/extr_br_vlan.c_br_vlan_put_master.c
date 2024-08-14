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
struct net_bridge_vlan_group {int /*<<< orphan*/  vlan_hash; } ;
struct net_bridge_vlan {int /*<<< orphan*/  rcu; int /*<<< orphan*/  vnode; int /*<<< orphan*/  refcnt; int /*<<< orphan*/  br; } ;

/* Variables and functions */
 int /*<<< orphan*/  __vlan_del_list (struct net_bridge_vlan*) ; 
 int /*<<< orphan*/  br_master_vlan_rcu_free ; 
 struct net_bridge_vlan_group* br_vlan_group (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  br_vlan_is_master (struct net_bridge_vlan*) ; 
 int /*<<< orphan*/  br_vlan_rht_params ; 
 int /*<<< orphan*/  call_rcu (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ refcount_dec_and_test (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rhashtable_remove_fast (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void br_vlan_put_master(struct net_bridge_vlan *masterv)
{
	struct net_bridge_vlan_group *vg;

	if (!br_vlan_is_master(masterv))
		return;

	vg = br_vlan_group(masterv->br);
	if (refcount_dec_and_test(&masterv->refcnt)) {
		rhashtable_remove_fast(&vg->vlan_hash,
				       &masterv->vnode, br_vlan_rht_params);
		__vlan_del_list(masterv);
		call_rcu(&masterv->rcu, br_master_vlan_rcu_free);
	}
}