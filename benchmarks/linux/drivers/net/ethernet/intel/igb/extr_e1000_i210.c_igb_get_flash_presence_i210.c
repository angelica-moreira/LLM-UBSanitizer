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
struct e1000_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  E1000_EECD ; 
 int E1000_EECD_FLASH_DETECTED_I210 ; 
 int rd32 (int /*<<< orphan*/ ) ; 

bool igb_get_flash_presence_i210(struct e1000_hw *hw)
{
	u32 eec = 0;
	bool ret_val = false;

	eec = rd32(E1000_EECD);
	if (eec & E1000_EECD_FLASH_DETECTED_I210)
		ret_val = true;

	return ret_val;
}