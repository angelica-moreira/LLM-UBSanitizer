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
struct e1000_hw {int dummy; } ;
typedef  scalar_t__ s32 ;

/* Variables and functions */
 int /*<<< orphan*/  I82579_EMI_ADDR ; 
 int /*<<< orphan*/  I82579_EMI_DATA ; 
 scalar_t__ e1e_rphy_locked (struct e1000_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ e1e_wphy_locked (struct e1000_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static s32 __e1000_access_emi_reg_locked(struct e1000_hw *hw, u16 address,
					 u16 *data, bool read)
{
	s32 ret_val;

	ret_val = e1e_wphy_locked(hw, I82579_EMI_ADDR, address);
	if (ret_val)
		return ret_val;

	if (read)
		ret_val = e1e_rphy_locked(hw, I82579_EMI_DATA, data);
	else
		ret_val = e1e_wphy_locked(hw, I82579_EMI_DATA, *data);

	return ret_val;
}