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
typedef  union devlink_param_value {int dummy; } devlink_param_value ;
typedef  int /*<<< orphan*/  u32 ;
struct devlink_port {int /*<<< orphan*/  param_list; struct devlink* devlink; } ;
struct devlink {int dummy; } ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 int __devlink_param_driverinit_value_get (int /*<<< orphan*/ *,int /*<<< orphan*/ ,union devlink_param_value*) ; 
 int /*<<< orphan*/  devlink_reload_supported (struct devlink*) ; 

int devlink_port_param_driverinit_value_get(struct devlink_port *devlink_port,
					    u32 param_id,
					    union devlink_param_value *init_val)
{
	struct devlink *devlink = devlink_port->devlink;

	if (!devlink_reload_supported(devlink))
		return -EOPNOTSUPP;

	return __devlink_param_driverinit_value_get(&devlink_port->param_list,
						    param_id, init_val);
}