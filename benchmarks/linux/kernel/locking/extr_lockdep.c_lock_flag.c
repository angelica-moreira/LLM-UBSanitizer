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
typedef  enum lock_usage_bit { ____Placeholder_lock_usage_bit } lock_usage_bit ;

/* Variables and functions */

__attribute__((used)) static inline unsigned long lock_flag(enum lock_usage_bit bit)
{
	return 1UL << bit;
}