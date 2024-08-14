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
typedef  scalar_t__ u32 ;
struct mlxsw_sp {int dummy; } ;
struct TYPE_2__ {scalar_t__ speed; scalar_t__ mask; } ;

/* Variables and functions */
 int MLXSW_SP1_PORT_LINK_MODE_LEN ; 
 TYPE_1__* mlxsw_sp1_port_link_mode ; 

__attribute__((used)) static u32
mlxsw_sp1_to_ptys_upper_speed(struct mlxsw_sp *mlxsw_sp, u32 upper_speed)
{
	u32 ptys_proto = 0;
	int i;

	for (i = 0; i < MLXSW_SP1_PORT_LINK_MODE_LEN; i++) {
		if (mlxsw_sp1_port_link_mode[i].speed <= upper_speed)
			ptys_proto |= mlxsw_sp1_port_link_mode[i].mask;
	}
	return ptys_proto;
}