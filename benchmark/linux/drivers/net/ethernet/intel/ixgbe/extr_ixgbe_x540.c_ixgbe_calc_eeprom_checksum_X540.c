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
typedef  scalar_t__ u16 ;
struct TYPE_2__ {scalar_t__ word_size; } ;
struct ixgbe_hw {TYPE_1__ eeprom; } ;
typedef  int /*<<< orphan*/  s32 ;

/* Variables and functions */
 scalar_t__ IXGBE_EEPROM_CHECKSUM ; 
 scalar_t__ IXGBE_EEPROM_SUM ; 
 int /*<<< orphan*/  IXGBE_ERR_EEPROM ; 
 scalar_t__ IXGBE_FW_PTR ; 
 scalar_t__ IXGBE_OPTION_ROM_PTR ; 
 scalar_t__ IXGBE_PCIE_ANALOG_PTR ; 
 scalar_t__ IXGBE_PHY_PTR ; 
 int /*<<< orphan*/  hw_dbg (struct ixgbe_hw*,char*) ; 
 scalar_t__ ixgbe_read_eerd_generic (struct ixgbe_hw*,scalar_t__,scalar_t__*) ; 

__attribute__((used)) static s32 ixgbe_calc_eeprom_checksum_X540(struct ixgbe_hw *hw)
{
	u16 i;
	u16 j;
	u16 checksum = 0;
	u16 length = 0;
	u16 pointer = 0;
	u16 word = 0;
	u16 checksum_last_word = IXGBE_EEPROM_CHECKSUM;
	u16 ptr_start = IXGBE_PCIE_ANALOG_PTR;

	/*
	 * Do not use hw->eeprom.ops.read because we do not want to take
	 * the synchronization semaphores here. Instead use
	 * ixgbe_read_eerd_generic
	 */

	/* Include 0x0-0x3F in the checksum */
	for (i = 0; i < checksum_last_word; i++) {
		if (ixgbe_read_eerd_generic(hw, i, &word)) {
			hw_dbg(hw, "EEPROM read failed\n");
			return IXGBE_ERR_EEPROM;
		}
		checksum += word;
	}

	/*
	 * Include all data from pointers 0x3, 0x6-0xE.  This excludes the
	 * FW, PHY module, and PCIe Expansion/Option ROM pointers.
	 */
	for (i = ptr_start; i < IXGBE_FW_PTR; i++) {
		if (i == IXGBE_PHY_PTR || i == IXGBE_OPTION_ROM_PTR)
			continue;

		if (ixgbe_read_eerd_generic(hw, i, &pointer)) {
			hw_dbg(hw, "EEPROM read failed\n");
			break;
		}

		/* Skip pointer section if the pointer is invalid. */
		if (pointer == 0xFFFF || pointer == 0 ||
		    pointer >= hw->eeprom.word_size)
			continue;

		if (ixgbe_read_eerd_generic(hw, pointer, &length)) {
			hw_dbg(hw, "EEPROM read failed\n");
			return IXGBE_ERR_EEPROM;
			break;
		}

		/* Skip pointer section if length is invalid. */
		if (length == 0xFFFF || length == 0 ||
		    (pointer + length) >= hw->eeprom.word_size)
			continue;

		for (j = pointer + 1; j <= pointer + length; j++) {
			if (ixgbe_read_eerd_generic(hw, j, &word)) {
				hw_dbg(hw, "EEPROM read failed\n");
				return IXGBE_ERR_EEPROM;
			}
			checksum += word;
		}
	}

	checksum = (u16)IXGBE_EEPROM_SUM - checksum;

	return (s32)checksum;
}