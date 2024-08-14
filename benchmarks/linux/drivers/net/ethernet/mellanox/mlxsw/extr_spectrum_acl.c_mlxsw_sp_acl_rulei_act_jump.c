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
typedef  int /*<<< orphan*/  u16 ;
struct mlxsw_sp_acl_rule_info {int /*<<< orphan*/  act_block; } ;

/* Variables and functions */
 int mlxsw_afa_block_jump (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int mlxsw_sp_acl_rulei_act_jump(struct mlxsw_sp_acl_rule_info *rulei,
				u16 group_id)
{
	return mlxsw_afa_block_jump(rulei->act_block, group_id);
}