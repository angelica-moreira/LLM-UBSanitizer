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
typedef  scalar_t__ u8 ;
struct mlxsw_sp {int /*<<< orphan*/  core; } ;

/* Variables and functions */
 scalar_t__ mlxsw_core_max_ports (int /*<<< orphan*/ ) ; 

u8 mlxsw_sp_router_port(const struct mlxsw_sp *mlxsw_sp)
{
	return mlxsw_core_max_ports(mlxsw_sp->core) + 1;
}