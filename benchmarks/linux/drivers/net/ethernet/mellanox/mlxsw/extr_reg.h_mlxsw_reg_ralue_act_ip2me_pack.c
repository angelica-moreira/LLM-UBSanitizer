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

/* Variables and functions */
 int /*<<< orphan*/  MLXSW_REG_RALUE_ACTION_TYPE_IP2ME ; 
 int /*<<< orphan*/  mlxsw_reg_ralue_action_type_set (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void
mlxsw_reg_ralue_act_ip2me_pack(char *payload)
{
	mlxsw_reg_ralue_action_type_set(payload,
					MLXSW_REG_RALUE_ACTION_TYPE_IP2ME);
}