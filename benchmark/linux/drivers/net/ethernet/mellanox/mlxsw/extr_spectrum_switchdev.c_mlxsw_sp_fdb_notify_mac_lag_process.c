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
typedef  int /*<<< orphan*/  u16 ;
struct mlxsw_sp_port_vlan {int /*<<< orphan*/  vid; int /*<<< orphan*/  fid; struct mlxsw_sp_bridge_port* bridge_port; } ;
struct mlxsw_sp_port {int /*<<< orphan*/  dev; } ;
struct mlxsw_sp_bridge_port {int /*<<< orphan*/  dev; struct mlxsw_sp_bridge_device* bridge_device; } ;
struct mlxsw_sp_bridge_device {scalar_t__ vlan_enabled; } ;
struct mlxsw_sp {TYPE_1__* bus_info; } ;
typedef  enum switchdev_notifier_type { ____Placeholder_switchdev_notifier_type } switchdev_notifier_type ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int ETH_ALEN ; 
 int SWITCHDEV_FDB_ADD_TO_BRIDGE ; 
 int SWITCHDEV_FDB_DEL_TO_BRIDGE ; 
 int /*<<< orphan*/  dev_err_ratelimited (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mlxsw_reg_sfn_mac_lag_unpack (char*,int,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mlxsw_sp_fdb_call_notifiers (int,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 scalar_t__ mlxsw_sp_fid_is_dummy (struct mlxsw_sp*,int /*<<< orphan*/ ) ; 
 scalar_t__ mlxsw_sp_fid_lag_vid_valid (int /*<<< orphan*/ ) ; 
 struct mlxsw_sp_port* mlxsw_sp_lag_rep_port (struct mlxsw_sp*,int /*<<< orphan*/ ) ; 
 int mlxsw_sp_port_fdb_uc_lag_op (struct mlxsw_sp*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 struct mlxsw_sp_port_vlan* mlxsw_sp_port_vlan_find_by_fid (struct mlxsw_sp_port*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  netdev_err (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void mlxsw_sp_fdb_notify_mac_lag_process(struct mlxsw_sp *mlxsw_sp,
						char *sfn_pl, int rec_index,
						bool adding)
{
	struct mlxsw_sp_port_vlan *mlxsw_sp_port_vlan;
	struct mlxsw_sp_bridge_device *bridge_device;
	struct mlxsw_sp_bridge_port *bridge_port;
	struct mlxsw_sp_port *mlxsw_sp_port;
	enum switchdev_notifier_type type;
	char mac[ETH_ALEN];
	u16 lag_vid = 0;
	u16 lag_id;
	u16 vid, fid;
	bool do_notification = true;
	int err;

	mlxsw_reg_sfn_mac_lag_unpack(sfn_pl, rec_index, mac, &fid, &lag_id);
	mlxsw_sp_port = mlxsw_sp_lag_rep_port(mlxsw_sp, lag_id);
	if (!mlxsw_sp_port) {
		dev_err_ratelimited(mlxsw_sp->bus_info->dev, "Cannot find port representor for LAG\n");
		goto just_remove;
	}

	if (mlxsw_sp_fid_is_dummy(mlxsw_sp, fid))
		goto just_remove;

	mlxsw_sp_port_vlan = mlxsw_sp_port_vlan_find_by_fid(mlxsw_sp_port, fid);
	if (!mlxsw_sp_port_vlan) {
		netdev_err(mlxsw_sp_port->dev, "Failed to find a matching {Port, VID} following FDB notification\n");
		goto just_remove;
	}

	bridge_port = mlxsw_sp_port_vlan->bridge_port;
	if (!bridge_port) {
		netdev_err(mlxsw_sp_port->dev, "{Port, VID} not associated with a bridge\n");
		goto just_remove;
	}

	bridge_device = bridge_port->bridge_device;
	vid = bridge_device->vlan_enabled ? mlxsw_sp_port_vlan->vid : 0;
	lag_vid = mlxsw_sp_fid_lag_vid_valid(mlxsw_sp_port_vlan->fid) ?
		  mlxsw_sp_port_vlan->vid : 0;

do_fdb_op:
	err = mlxsw_sp_port_fdb_uc_lag_op(mlxsw_sp, lag_id, mac, fid, lag_vid,
					  adding, true);
	if (err) {
		dev_err_ratelimited(mlxsw_sp->bus_info->dev, "Failed to set FDB entry\n");
		return;
	}

	if (!do_notification)
		return;
	type = adding ? SWITCHDEV_FDB_ADD_TO_BRIDGE : SWITCHDEV_FDB_DEL_TO_BRIDGE;
	mlxsw_sp_fdb_call_notifiers(type, mac, vid, bridge_port->dev, adding);

	return;

just_remove:
	adding = false;
	do_notification = false;
	goto do_fdb_op;
}