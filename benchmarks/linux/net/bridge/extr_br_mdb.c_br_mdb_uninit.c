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

/* Variables and functions */
 int /*<<< orphan*/  PF_BRIDGE ; 
 int /*<<< orphan*/  RTM_DELMDB ; 
 int /*<<< orphan*/  RTM_GETMDB ; 
 int /*<<< orphan*/  RTM_NEWMDB ; 
 int /*<<< orphan*/  rtnl_unregister (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void br_mdb_uninit(void)
{
	rtnl_unregister(PF_BRIDGE, RTM_GETMDB);
	rtnl_unregister(PF_BRIDGE, RTM_NEWMDB);
	rtnl_unregister(PF_BRIDGE, RTM_DELMDB);
}