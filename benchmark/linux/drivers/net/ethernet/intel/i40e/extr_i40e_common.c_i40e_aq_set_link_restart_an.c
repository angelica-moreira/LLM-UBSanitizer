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
struct i40e_hw {int dummy; } ;
struct i40e_asq_cmd_details {int dummy; } ;
struct i40e_aqc_set_link_restart_an {int /*<<< orphan*/  command; } ;
struct TYPE_2__ {int /*<<< orphan*/  raw; } ;
struct i40e_aq_desc {TYPE_1__ params; } ;
typedef  int /*<<< orphan*/  i40e_status ;

/* Variables and functions */
 int /*<<< orphan*/  I40E_AQ_PHY_LINK_ENABLE ; 
 int /*<<< orphan*/  I40E_AQ_PHY_RESTART_AN ; 
 int /*<<< orphan*/  i40e_aqc_opc_set_link_restart_an ; 
 int /*<<< orphan*/  i40e_asq_send_command (struct i40e_hw*,struct i40e_aq_desc*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct i40e_asq_cmd_details*) ; 
 int /*<<< orphan*/  i40e_fill_default_direct_cmd_desc (struct i40e_aq_desc*,int /*<<< orphan*/ ) ; 

i40e_status i40e_aq_set_link_restart_an(struct i40e_hw *hw,
					bool enable_link,
					struct i40e_asq_cmd_details *cmd_details)
{
	struct i40e_aq_desc desc;
	struct i40e_aqc_set_link_restart_an *cmd =
		(struct i40e_aqc_set_link_restart_an *)&desc.params.raw;
	i40e_status status;

	i40e_fill_default_direct_cmd_desc(&desc,
					  i40e_aqc_opc_set_link_restart_an);

	cmd->command = I40E_AQ_PHY_RESTART_AN;
	if (enable_link)
		cmd->command |= I40E_AQ_PHY_LINK_ENABLE;
	else
		cmd->command &= ~I40E_AQ_PHY_LINK_ENABLE;

	status = i40e_asq_send_command(hw, &desc, NULL, 0, cmd_details);

	return status;
}