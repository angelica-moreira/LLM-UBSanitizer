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
typedef  int /*<<< orphan*/  int32_t ;

/* Variables and functions */
 scalar_t__ fls (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int top_bit(unsigned int bits)
{
	if (bits == 0)
		return -1;
	else
		return (int)fls((int32_t) bits) - 1;
}