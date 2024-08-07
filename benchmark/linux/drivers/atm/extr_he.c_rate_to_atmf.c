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
 unsigned int NONZERO ; 

__attribute__((used)) static unsigned
rate_to_atmf(unsigned rate)		/* cps to atm forum format */
{
#define NONZERO (1 << 14)

	unsigned exp = 0;

	if (rate == 0)
		return 0;

	rate <<= 9;
	while (rate > 0x3ff) {
		++exp;
		rate >>= 1;
	}

	return (NONZERO | (exp << 9) | (rate & 0x1ff));
}