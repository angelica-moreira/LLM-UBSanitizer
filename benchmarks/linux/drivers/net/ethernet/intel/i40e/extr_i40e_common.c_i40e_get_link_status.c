#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int link_info; } ;
struct TYPE_4__ {TYPE_1__ link_info; scalar_t__ get_link_info; } ;
struct i40e_hw {TYPE_2__ phy; } ;
typedef  scalar_t__ i40e_status ;

/* Variables and functions */
 int I40E_AQ_LINK_UP ; 
 int /*<<< orphan*/  I40E_DEBUG_LINK ; 
 int /*<<< orphan*/  i40e_debug (struct i40e_hw*,int /*<<< orphan*/ ,char*,scalar_t__) ; 
 scalar_t__ i40e_update_link_info (struct i40e_hw*) ; 

i40e_status i40e_get_link_status(struct i40e_hw *hw, bool *link_up)
{
	i40e_status status = 0;

	if (hw->phy.get_link_info) {
		status = i40e_update_link_info(hw);

		if (status)
			i40e_debug(hw, I40E_DEBUG_LINK, "get link failed: status %d\n",
				   status);
	}

	*link_up = hw->phy.link_info.link_info & I40E_AQ_LINK_UP;

	return status;
}