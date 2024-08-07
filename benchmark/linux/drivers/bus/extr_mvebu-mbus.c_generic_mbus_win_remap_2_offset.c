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

/* Variables and functions */
 unsigned int MVEBU_MBUS_NO_REMAP ; 
 unsigned int generic_mbus_win_cfg_offset (int) ; 

__attribute__((used)) static unsigned int generic_mbus_win_remap_2_offset(int win)
{
	if (win < 2)
		return generic_mbus_win_cfg_offset(win);
	else
		return MVEBU_MBUS_NO_REMAP;
}