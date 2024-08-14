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
struct bnx2x_vlan_mac_obj {struct bnx2x_credit_pool_obj* vlans_pool; } ;
struct bnx2x_credit_pool_obj {int (* get_entry ) (struct bnx2x_credit_pool_obj*,int*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ON (int) ; 
 int stub1 (struct bnx2x_credit_pool_obj*,int*) ; 

__attribute__((used)) static bool bnx2x_get_cam_offset_vlan(struct bnx2x_vlan_mac_obj *o, int *offset)
{
	struct bnx2x_credit_pool_obj *vp = o->vlans_pool;

	WARN_ON(!vp);

	return vp->get_entry(vp, offset);
}