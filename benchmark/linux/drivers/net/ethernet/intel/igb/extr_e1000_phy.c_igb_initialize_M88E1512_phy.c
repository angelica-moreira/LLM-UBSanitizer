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
struct TYPE_2__ {scalar_t__ (* write_reg ) (struct e1000_hw*,int /*<<< orphan*/ ,int) ;} ;
struct e1000_phy_info {TYPE_1__ ops; } ;
struct e1000_hw {struct e1000_phy_info phy; } ;
typedef  scalar_t__ s32 ;

/* Variables and functions */
 int /*<<< orphan*/  E1000_M88E1512_CFG_REG_1 ; 
 int /*<<< orphan*/  E1000_M88E1512_CFG_REG_2 ; 
 int /*<<< orphan*/  E1000_M88E1512_CFG_REG_3 ; 
 int /*<<< orphan*/  E1000_M88E1512_MODE ; 
 int /*<<< orphan*/  E1000_M88E1543_PAGE_ADDR ; 
 int /*<<< orphan*/  hw_dbg (char*) ; 
 scalar_t__ igb_phy_sw_reset (struct e1000_hw*) ; 
 scalar_t__ stub1 (struct e1000_hw*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ stub10 (struct e1000_hw*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ stub11 (struct e1000_hw*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ stub12 (struct e1000_hw*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ stub13 (struct e1000_hw*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ stub14 (struct e1000_hw*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ stub2 (struct e1000_hw*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ stub3 (struct e1000_hw*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ stub4 (struct e1000_hw*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ stub5 (struct e1000_hw*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ stub6 (struct e1000_hw*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ stub7 (struct e1000_hw*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ stub8 (struct e1000_hw*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ stub9 (struct e1000_hw*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

s32 igb_initialize_M88E1512_phy(struct e1000_hw *hw)
{
	struct e1000_phy_info *phy = &hw->phy;
	s32 ret_val = 0;

	/* Switch to PHY page 0xFF. */
	ret_val = phy->ops.write_reg(hw, E1000_M88E1543_PAGE_ADDR, 0x00FF);
	if (ret_val)
		goto out;

	ret_val = phy->ops.write_reg(hw, E1000_M88E1512_CFG_REG_2, 0x214B);
	if (ret_val)
		goto out;

	ret_val = phy->ops.write_reg(hw, E1000_M88E1512_CFG_REG_1, 0x2144);
	if (ret_val)
		goto out;

	ret_val = phy->ops.write_reg(hw, E1000_M88E1512_CFG_REG_2, 0x0C28);
	if (ret_val)
		goto out;

	ret_val = phy->ops.write_reg(hw, E1000_M88E1512_CFG_REG_1, 0x2146);
	if (ret_val)
		goto out;

	ret_val = phy->ops.write_reg(hw, E1000_M88E1512_CFG_REG_2, 0xB233);
	if (ret_val)
		goto out;

	ret_val = phy->ops.write_reg(hw, E1000_M88E1512_CFG_REG_1, 0x214D);
	if (ret_val)
		goto out;

	ret_val = phy->ops.write_reg(hw, E1000_M88E1512_CFG_REG_2, 0xCC0C);
	if (ret_val)
		goto out;

	ret_val = phy->ops.write_reg(hw, E1000_M88E1512_CFG_REG_1, 0x2159);
	if (ret_val)
		goto out;

	/* Switch to PHY page 0xFB. */
	ret_val = phy->ops.write_reg(hw, E1000_M88E1543_PAGE_ADDR, 0x00FB);
	if (ret_val)
		goto out;

	ret_val = phy->ops.write_reg(hw, E1000_M88E1512_CFG_REG_3, 0x000D);
	if (ret_val)
		goto out;

	/* Switch to PHY page 0x12. */
	ret_val = phy->ops.write_reg(hw, E1000_M88E1543_PAGE_ADDR, 0x12);
	if (ret_val)
		goto out;

	/* Change mode to SGMII-to-Copper */
	ret_val = phy->ops.write_reg(hw, E1000_M88E1512_MODE, 0x8001);
	if (ret_val)
		goto out;

	/* Return the PHY to page 0. */
	ret_val = phy->ops.write_reg(hw, E1000_M88E1543_PAGE_ADDR, 0);
	if (ret_val)
		goto out;

	ret_val = igb_phy_sw_reset(hw);
	if (ret_val) {
		hw_dbg("Error committing the PHY changes\n");
		return ret_val;
	}

	/* msec_delay(1000); */
	usleep_range(1000, 2000);
out:
	return ret_val;
}