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
 int APL_NUM_CHANNELS ; 
 int BIT (int) ; 
 int EINVAL ; 
 int chan_mask ; 
 scalar_t__ check_channel (int) ; 

__attribute__((used)) static int apl_check_ecc_active(void)
{
	int	i, ret = 0;

	/* Check dramtype and ECC mode for each present DIMM */
	for (i = 0; i < APL_NUM_CHANNELS; i++)
		if (chan_mask & BIT(i))
			ret += check_channel(i);
	return ret ? -EINVAL : 0;
}