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
typedef  int u32 ;
typedef  int u16 ;
struct atl2_hw {int dummy; } ;
typedef  int /*<<< orphan*/  s32 ;

/* Variables and functions */
 int ATL2_READ_REG (struct atl2_hw*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ATL2_WRITE_REG (struct atl2_hw*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ATLX_ERR_PHY ; 
 int MDIO_BUSY ; 
 int MDIO_CLK_25_4 ; 
 int MDIO_CLK_SEL_SHIFT ; 
 int MDIO_DATA_MASK ; 
 int MDIO_DATA_SHIFT ; 
 int MDIO_REG_ADDR_MASK ; 
 int MDIO_REG_ADDR_SHIFT ; 
 int MDIO_START ; 
 int MDIO_SUP_PREAMBLE ; 
 int MDIO_WAIT_TIMES ; 
 int /*<<< orphan*/  REG_MDIO_CTRL ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  wmb () ; 

__attribute__((used)) static s32 atl2_write_phy_reg(struct atl2_hw *hw, u32 reg_addr, u16 phy_data)
{
	int i;
	u32 val;

	val = ((u32)(phy_data & MDIO_DATA_MASK)) << MDIO_DATA_SHIFT |
		(reg_addr & MDIO_REG_ADDR_MASK) << MDIO_REG_ADDR_SHIFT |
		MDIO_SUP_PREAMBLE |
		MDIO_START |
		MDIO_CLK_25_4 << MDIO_CLK_SEL_SHIFT;
	ATL2_WRITE_REG(hw, REG_MDIO_CTRL, val);

	wmb();

	for (i = 0; i < MDIO_WAIT_TIMES; i++) {
		udelay(2);
		val = ATL2_READ_REG(hw, REG_MDIO_CTRL);
		if (!(val & (MDIO_START | MDIO_BUSY)))
			break;

		wmb();
	}

	if (!(val & (MDIO_START | MDIO_BUSY)))
		return 0;

	return ATLX_ERR_PHY;
}