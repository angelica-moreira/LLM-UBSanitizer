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
struct mlxsw_sp {int /*<<< orphan*/  core; } ;
struct devlink {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MLXSW_SP_DPIPE_TABLE_NAME_ADJ ; 
 int /*<<< orphan*/  MLXSW_SP_DPIPE_TABLE_RESOURCE_UNIT_ADJ ; 
 int /*<<< orphan*/  MLXSW_SP_RESOURCE_KVD_LINEAR ; 
 int devlink_dpipe_table_register (struct devlink*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct mlxsw_sp*,int) ; 
 int devlink_dpipe_table_resource_set (struct devlink*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devlink_dpipe_table_unregister (struct devlink*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlxsw_sp_dpipe_table_adj_ops ; 
 struct devlink* priv_to_devlink (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mlxsw_sp_dpipe_adj_table_init(struct mlxsw_sp *mlxsw_sp)
{
	struct devlink *devlink = priv_to_devlink(mlxsw_sp->core);
	int err;

	err = devlink_dpipe_table_register(devlink,
					   MLXSW_SP_DPIPE_TABLE_NAME_ADJ,
					   &mlxsw_sp_dpipe_table_adj_ops,
					   mlxsw_sp, false);
	if (err)
		return err;

	err = devlink_dpipe_table_resource_set(devlink,
					       MLXSW_SP_DPIPE_TABLE_NAME_ADJ,
					       MLXSW_SP_RESOURCE_KVD_LINEAR,
					       MLXSW_SP_DPIPE_TABLE_RESOURCE_UNIT_ADJ);
	if (err)
		goto err_resource_set;

	return 0;

err_resource_set:
	devlink_dpipe_table_unregister(devlink,
				       MLXSW_SP_DPIPE_TABLE_NAME_ADJ);
	return err;
}