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
struct mlxsw_sp2_acl_tcam_region {int /*<<< orphan*/  aregion; } ;

/* Variables and functions */
 void* mlxsw_sp_acl_atcam_rehash_hints_get (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void *mlxsw_sp2_acl_tcam_region_rehash_hints_get(void *region_priv)
{
	struct mlxsw_sp2_acl_tcam_region *region = region_priv;

	return mlxsw_sp_acl_atcam_rehash_hints_get(&region->aregion);
}