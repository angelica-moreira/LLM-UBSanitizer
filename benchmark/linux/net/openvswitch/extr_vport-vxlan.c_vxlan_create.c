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
struct vport_parms {int /*<<< orphan*/  name; } ;
struct vport {int dummy; } ;

/* Variables and functions */
 scalar_t__ IS_ERR (struct vport*) ; 
 struct vport* ovs_netdev_link (struct vport*,int /*<<< orphan*/ ) ; 
 struct vport* vxlan_tnl_create (struct vport_parms const*) ; 

__attribute__((used)) static struct vport *vxlan_create(const struct vport_parms *parms)
{
	struct vport *vport;

	vport = vxlan_tnl_create(parms);
	if (IS_ERR(vport))
		return vport;

	return ovs_netdev_link(vport, parms->name);
}