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
typedef  scalar_t__ u32 ;

/* Variables and functions */

__attribute__((used)) static u32 cik_create_bitmask(u32 bit_width)
{
	u32 i, mask = 0;

	for (i = 0; i < bit_width; i++) {
		mask <<= 1;
		mask |= 1;
	}
	return mask;
}