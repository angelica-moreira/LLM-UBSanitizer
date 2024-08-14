#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct mlxsw_sp_port {size_t local_port; struct mlxsw_sp* mlxsw_sp; } ;
struct mlxsw_sp_fid {int /*<<< orphan*/  fid_index; } ;
struct mlxsw_sp {TYPE_1__* fid_core; } ;
struct TYPE_2__ {int /*<<< orphan*/ * port_fid_mappings; } ;

/* Variables and functions */
 int __mlxsw_sp_fid_port_vid_map (struct mlxsw_sp*,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ ,int) ; 
 int mlxsw_sp_port_vp_mode_trans (struct mlxsw_sp_port*) ; 

__attribute__((used)) static int mlxsw_sp_fid_8021d_port_vid_map(struct mlxsw_sp_fid *fid,
					   struct mlxsw_sp_port *mlxsw_sp_port,
					   u16 vid)
{
	struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
	u8 local_port = mlxsw_sp_port->local_port;
	int err;

	err = __mlxsw_sp_fid_port_vid_map(mlxsw_sp, fid->fid_index,
					  mlxsw_sp_port->local_port, vid, true);
	if (err)
		return err;

	if (mlxsw_sp->fid_core->port_fid_mappings[local_port]++ == 0) {
		err = mlxsw_sp_port_vp_mode_trans(mlxsw_sp_port);
		if (err)
			goto err_port_vp_mode_trans;
	}

	return 0;

err_port_vp_mode_trans:
	mlxsw_sp->fid_core->port_fid_mappings[local_port]--;
	__mlxsw_sp_fid_port_vid_map(mlxsw_sp, fid->fid_index,
				    mlxsw_sp_port->local_port, vid, false);
	return err;
}