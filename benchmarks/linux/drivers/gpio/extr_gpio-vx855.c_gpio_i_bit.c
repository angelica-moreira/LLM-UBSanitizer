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
typedef  int u_int32_t ;

/* Variables and functions */

__attribute__((used)) static inline u_int32_t gpio_i_bit(int i)
{
	if (i < 14)
		return 1 << (i + 10);
	else
		return 1 << (i + 14);
}