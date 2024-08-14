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
struct mlxsw_sp_mr_route_key {int dummy; } ;
struct mlxsw_sp1_mr_tcam_route {int /*<<< orphan*/  parman_item; } ;
struct mlxsw_sp {int dummy; } ;
struct mlxsw_afa_block {int dummy; } ;

/* Variables and functions */
 int mlxsw_sp1_mr_tcam_route_replace (struct mlxsw_sp*,int /*<<< orphan*/ *,struct mlxsw_sp_mr_route_key*,struct mlxsw_afa_block*) ; 

__attribute__((used)) static int
mlxsw_sp1_mr_tcam_route_update(struct mlxsw_sp *mlxsw_sp,
			       void *route_priv,
			       struct mlxsw_sp_mr_route_key *key,
			       struct mlxsw_afa_block *afa_block)
{
	struct mlxsw_sp1_mr_tcam_route *route = route_priv;

	return mlxsw_sp1_mr_tcam_route_replace(mlxsw_sp, &route->parman_item,
					       key, afa_block);
}