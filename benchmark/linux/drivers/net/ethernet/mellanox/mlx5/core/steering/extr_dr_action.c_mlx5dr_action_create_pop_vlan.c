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
struct mlx5dr_action {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DR_ACTION_TYP_POP_VLAN ; 
 struct mlx5dr_action* dr_action_create_generic (int /*<<< orphan*/ ) ; 

struct mlx5dr_action *mlx5dr_action_create_pop_vlan(void)
{
	return dr_action_create_generic(DR_ACTION_TYP_POP_VLAN);
}