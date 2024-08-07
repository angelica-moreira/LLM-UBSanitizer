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
typedef  scalar_t__ u64 ;

/* Variables and functions */
 scalar_t__ high_bits (scalar_t__,scalar_t__) ; 
 scalar_t__ low_bits (scalar_t__,scalar_t__) ; 

__attribute__((used)) static void accumulate_val(u64 *accum, u64 val, u64 mask)
{
#define low_bits(x, mask)		((x) & (mask))
#define high_bits(x, mask)		((x) & ~(mask))
	bool wrapped = val < low_bits(*accum, mask);

	*accum = high_bits(*accum, mask) + val;
	if (wrapped)
		*accum += (mask + 1);
}