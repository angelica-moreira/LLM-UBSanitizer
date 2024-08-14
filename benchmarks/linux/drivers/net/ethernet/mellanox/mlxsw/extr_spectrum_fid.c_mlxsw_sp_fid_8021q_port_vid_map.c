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
struct TYPE_2__ {scalar_t__* port_fid_mappings; } ;

/* Variables and functions */
 int __mlxsw_sp_fid_port_vid_map (struct mlxsw_sp*,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int mlxsw_sp_fid_8021q_port_vid_map(struct mlxsw_sp_fid *fid,
					   struct mlxsw_sp_port *mlxsw_sp_port,
					   u16 vid)
{
	struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
	u8 local_port = mlxsw_sp_port->local_port;

	/* In case there are no {Port, VID} => FID mappings on the port,
	 * we can use the global VID => FID mapping we created when the
	 * FID was configured.
	 */
	if (mlxsw_sp->fid_core->port_fid_mappings[local_port] == 0)
		return 0;
	return __mlxsw_sp_fid_port_vid_map(mlxsw_sp, fid->fid_index, local_port,
					   vid, true);
}