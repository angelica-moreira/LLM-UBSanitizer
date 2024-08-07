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
 unsigned long CLK_DIVIDER_ROUND_CLOSEST ; 
 scalar_t__ abs (unsigned long) ; 

__attribute__((used)) static bool _is_best_div(unsigned long rate, unsigned long now,
			 unsigned long best, unsigned long flags)
{
	if (flags & CLK_DIVIDER_ROUND_CLOSEST)
		return abs(rate - now) < abs(rate - best);

	return now <= rate && now > best;
}