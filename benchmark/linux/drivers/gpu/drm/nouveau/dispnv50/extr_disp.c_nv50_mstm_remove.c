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
struct nv50_mstm {int /*<<< orphan*/  mgr; } ;

/* Variables and functions */
 int /*<<< orphan*/  drm_dp_mst_topology_mgr_set_mst (int /*<<< orphan*/ *,int) ; 

void
nv50_mstm_remove(struct nv50_mstm *mstm)
{
	if (mstm)
		drm_dp_mst_topology_mgr_set_mst(&mstm->mgr, false);
}