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
typedef  scalar_t__ u8 ;
struct controller {int dummy; } ;

/* Variables and functions */
 int ENODEV ; 
 scalar_t__ MRL_SENS (struct controller*) ; 
 scalar_t__ POWER_CTRL (struct controller*) ; 
 int board_added (struct controller*) ; 
 int /*<<< orphan*/  ctrl_info (struct controller*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pciehp_get_latch_status (struct controller*,scalar_t__*) ; 
 int /*<<< orphan*/  pciehp_get_power_status (struct controller*,scalar_t__*) ; 
 int /*<<< orphan*/  slot_name (struct controller*) ; 

__attribute__((used)) static int __pciehp_enable_slot(struct controller *ctrl)
{
	u8 getstatus = 0;

	if (MRL_SENS(ctrl)) {
		pciehp_get_latch_status(ctrl, &getstatus);
		if (getstatus) {
			ctrl_info(ctrl, "Slot(%s): Latch open\n",
				  slot_name(ctrl));
			return -ENODEV;
		}
	}

	if (POWER_CTRL(ctrl)) {
		pciehp_get_power_status(ctrl, &getstatus);
		if (getstatus) {
			ctrl_info(ctrl, "Slot(%s): Already enabled\n",
				  slot_name(ctrl));
			return 0;
		}
	}

	return board_added(ctrl);
}