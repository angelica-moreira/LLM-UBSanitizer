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
struct mlxsw_hwmon {int /*<<< orphan*/  hwmon_dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  hwmon_device_unregister (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct mlxsw_hwmon*) ; 

void mlxsw_hwmon_fini(struct mlxsw_hwmon *mlxsw_hwmon)
{
	hwmon_device_unregister(mlxsw_hwmon->hwmon_dev);
	kfree(mlxsw_hwmon);
}