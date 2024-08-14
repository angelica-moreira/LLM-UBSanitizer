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
struct brcmnand_controller {int nand_version; } ;

/* Variables and functions */

__attribute__((used)) static inline int brcmnand_sector_1k_shift(struct brcmnand_controller *ctrl)
{
	if (ctrl->nand_version >= 0x0702)
		return 9;
	else if (ctrl->nand_version >= 0x0600)
		return 7;
	else if (ctrl->nand_version >= 0x0500)
		return 6;
	else
		return -1;
}