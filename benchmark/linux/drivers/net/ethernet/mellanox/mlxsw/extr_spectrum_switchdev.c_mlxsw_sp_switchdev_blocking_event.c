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
struct notifier_block {int dummy; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 int NOTIFY_DONE ; 
#define  SWITCHDEV_PORT_ATTR_SET 130 
#define  SWITCHDEV_PORT_OBJ_ADD 129 
#define  SWITCHDEV_PORT_OBJ_DEL 128 
 int /*<<< orphan*/  mlxsw_sp_port_attr_set ; 
 int /*<<< orphan*/  mlxsw_sp_port_dev_check ; 
 int /*<<< orphan*/  mlxsw_sp_port_obj_add ; 
 int /*<<< orphan*/  mlxsw_sp_port_obj_del ; 
 int mlxsw_sp_switchdev_handle_vxlan_obj_add (struct net_device*,void*) ; 
 int /*<<< orphan*/  mlxsw_sp_switchdev_handle_vxlan_obj_del (struct net_device*,void*) ; 
 int /*<<< orphan*/  netif_is_vxlan (struct net_device*) ; 
 int notifier_from_errno (int) ; 
 int switchdev_handle_port_attr_set (struct net_device*,void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int switchdev_handle_port_obj_add (struct net_device*,void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int switchdev_handle_port_obj_del (struct net_device*,void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct net_device* switchdev_notifier_info_to_dev (void*) ; 

__attribute__((used)) static int mlxsw_sp_switchdev_blocking_event(struct notifier_block *unused,
					     unsigned long event, void *ptr)
{
	struct net_device *dev = switchdev_notifier_info_to_dev(ptr);
	int err = 0;

	switch (event) {
	case SWITCHDEV_PORT_OBJ_ADD:
		if (netif_is_vxlan(dev))
			err = mlxsw_sp_switchdev_handle_vxlan_obj_add(dev, ptr);
		else
			err = switchdev_handle_port_obj_add(dev, ptr,
							mlxsw_sp_port_dev_check,
							mlxsw_sp_port_obj_add);
		return notifier_from_errno(err);
	case SWITCHDEV_PORT_OBJ_DEL:
		if (netif_is_vxlan(dev))
			mlxsw_sp_switchdev_handle_vxlan_obj_del(dev, ptr);
		else
			err = switchdev_handle_port_obj_del(dev, ptr,
							mlxsw_sp_port_dev_check,
							mlxsw_sp_port_obj_del);
		return notifier_from_errno(err);
	case SWITCHDEV_PORT_ATTR_SET:
		err = switchdev_handle_port_attr_set(dev, ptr,
						     mlxsw_sp_port_dev_check,
						     mlxsw_sp_port_attr_set);
		return notifier_from_errno(err);
	}

	return NOTIFY_DONE;
}