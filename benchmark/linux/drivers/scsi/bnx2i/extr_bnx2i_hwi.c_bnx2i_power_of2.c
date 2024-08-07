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

/* Variables and functions */

__attribute__((used)) static int bnx2i_power_of2(u32 val)
{
	u32 power = 0;
	if (val & (val - 1))
		return power;
	val--;
	while (val) {
		val = val >> 1;
		power++;
	}
	return power;
}