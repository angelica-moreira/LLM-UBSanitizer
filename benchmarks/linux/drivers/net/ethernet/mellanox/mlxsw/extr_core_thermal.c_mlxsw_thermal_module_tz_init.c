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
typedef  int /*<<< orphan*/  tz_name ;
struct mlxsw_thermal_module {int module; int /*<<< orphan*/  mode; int /*<<< orphan*/  tzdev; } ;

/* Variables and functions */
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MLXSW_THERMAL_NUM_TRIPS ; 
 int /*<<< orphan*/  MLXSW_THERMAL_TRIP_MASK ; 
 int MLXSW_THERMAL_ZONE_MAX_NAME ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  THERMAL_DEVICE_ENABLED ; 
 int /*<<< orphan*/  mlxsw_thermal_module_ops ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 
 int /*<<< orphan*/  thermal_zone_device_register (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct mlxsw_thermal_module*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
mlxsw_thermal_module_tz_init(struct mlxsw_thermal_module *module_tz)
{
	char tz_name[MLXSW_THERMAL_ZONE_MAX_NAME];
	int err;

	snprintf(tz_name, sizeof(tz_name), "mlxsw-module%d",
		 module_tz->module + 1);
	module_tz->tzdev = thermal_zone_device_register(tz_name,
							MLXSW_THERMAL_NUM_TRIPS,
							MLXSW_THERMAL_TRIP_MASK,
							module_tz,
							&mlxsw_thermal_module_ops,
							NULL, 0, 0);
	if (IS_ERR(module_tz->tzdev)) {
		err = PTR_ERR(module_tz->tzdev);
		return err;
	}

	module_tz->mode = THERMAL_DEVICE_ENABLED;
	return 0;
}