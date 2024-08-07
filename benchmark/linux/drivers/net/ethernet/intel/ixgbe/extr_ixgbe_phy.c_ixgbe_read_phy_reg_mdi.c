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
typedef  scalar_t__ u32 ;
typedef  scalar_t__ u16 ;
struct TYPE_3__ {scalar_t__ prtad; } ;
struct TYPE_4__ {TYPE_1__ mdio; } ;
struct ixgbe_hw {TYPE_2__ phy; } ;
typedef  int /*<<< orphan*/  s32 ;

/* Variables and functions */
 int /*<<< orphan*/  IXGBE_ERR_PHY ; 
 scalar_t__ IXGBE_MDIO_COMMAND_TIMEOUT ; 
 int /*<<< orphan*/  IXGBE_MSCA ; 
 scalar_t__ IXGBE_MSCA_ADDR_CYCLE ; 
 scalar_t__ IXGBE_MSCA_DEV_TYPE_SHIFT ; 
 scalar_t__ IXGBE_MSCA_MDI_COMMAND ; 
 scalar_t__ IXGBE_MSCA_NP_ADDR_SHIFT ; 
 scalar_t__ IXGBE_MSCA_PHY_ADDR_SHIFT ; 
 scalar_t__ IXGBE_MSCA_READ ; 
 int /*<<< orphan*/  IXGBE_MSRWD ; 
 scalar_t__ IXGBE_MSRWD_READ_DATA_SHIFT ; 
 scalar_t__ IXGBE_READ_REG (struct ixgbe_hw*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IXGBE_WRITE_REG (struct ixgbe_hw*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  hw_dbg (struct ixgbe_hw*,char*) ; 
 int /*<<< orphan*/  udelay (int) ; 

s32 ixgbe_read_phy_reg_mdi(struct ixgbe_hw *hw, u32 reg_addr, u32 device_type,
		       u16 *phy_data)
{
	u32 i, data, command;

	/* Setup and write the address cycle command */
	command = ((reg_addr << IXGBE_MSCA_NP_ADDR_SHIFT)  |
		   (device_type << IXGBE_MSCA_DEV_TYPE_SHIFT) |
		   (hw->phy.mdio.prtad << IXGBE_MSCA_PHY_ADDR_SHIFT) |
		   (IXGBE_MSCA_ADDR_CYCLE | IXGBE_MSCA_MDI_COMMAND));

	IXGBE_WRITE_REG(hw, IXGBE_MSCA, command);

	/* Check every 10 usec to see if the address cycle completed.
	 * The MDI Command bit will clear when the operation is
	 * complete
	 */
	for (i = 0; i < IXGBE_MDIO_COMMAND_TIMEOUT; i++) {
		udelay(10);

		command = IXGBE_READ_REG(hw, IXGBE_MSCA);
		if ((command & IXGBE_MSCA_MDI_COMMAND) == 0)
				break;
	}


	if ((command & IXGBE_MSCA_MDI_COMMAND) != 0) {
		hw_dbg(hw, "PHY address command did not complete.\n");
		return IXGBE_ERR_PHY;
	}

	/* Address cycle complete, setup and write the read
	 * command
	 */
	command = ((reg_addr << IXGBE_MSCA_NP_ADDR_SHIFT)  |
		   (device_type << IXGBE_MSCA_DEV_TYPE_SHIFT) |
		   (hw->phy.mdio.prtad << IXGBE_MSCA_PHY_ADDR_SHIFT) |
		   (IXGBE_MSCA_READ | IXGBE_MSCA_MDI_COMMAND));

	IXGBE_WRITE_REG(hw, IXGBE_MSCA, command);

	/* Check every 10 usec to see if the address cycle
	 * completed. The MDI Command bit will clear when the
	 * operation is complete
	 */
	for (i = 0; i < IXGBE_MDIO_COMMAND_TIMEOUT; i++) {
		udelay(10);

		command = IXGBE_READ_REG(hw, IXGBE_MSCA);
		if ((command & IXGBE_MSCA_MDI_COMMAND) == 0)
			break;
	}

	if ((command & IXGBE_MSCA_MDI_COMMAND) != 0) {
		hw_dbg(hw, "PHY read command didn't complete\n");
		return IXGBE_ERR_PHY;
	}

	/* Read operation is complete.  Get the data
	 * from MSRWD
	 */
	data = IXGBE_READ_REG(hw, IXGBE_MSRWD);
	data >>= IXGBE_MSRWD_READ_DATA_SHIFT;
	*phy_data = (u16)(data);

	return 0;
}