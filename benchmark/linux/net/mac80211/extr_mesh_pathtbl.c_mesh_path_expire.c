#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  mpp_paths; int /*<<< orphan*/  mesh_paths; } ;
struct TYPE_4__ {TYPE_1__ mesh; } ;
struct ieee80211_sub_if_data {TYPE_2__ u; } ;

/* Variables and functions */
 int /*<<< orphan*/  mesh_path_tbl_expire (struct ieee80211_sub_if_data*,int /*<<< orphan*/ ) ; 

void mesh_path_expire(struct ieee80211_sub_if_data *sdata)
{
	mesh_path_tbl_expire(sdata, sdata->u.mesh.mesh_paths);
	mesh_path_tbl_expire(sdata, sdata->u.mesh.mpp_paths);
}