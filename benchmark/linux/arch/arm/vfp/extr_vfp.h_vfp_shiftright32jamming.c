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
typedef  unsigned int u32 ;

/* Variables and functions */

__attribute__((used)) static inline u32 vfp_shiftright32jamming(u32 val, unsigned int shift)
{
	if (shift) {
		if (shift < 32)
			val = val >> shift | ((val << (32 - shift)) != 0);
		else
			val = val != 0;
	}
	return val;
}