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
struct mlxsw_core_port {int /*<<< orphan*/ * port_driver_priv; } ;

/* Variables and functions */

__attribute__((used)) static bool mlxsw_core_port_check(struct mlxsw_core_port *mlxsw_core_port)
{
	return mlxsw_core_port->port_driver_priv != NULL;
}