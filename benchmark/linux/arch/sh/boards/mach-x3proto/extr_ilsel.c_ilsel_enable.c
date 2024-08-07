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
typedef  scalar_t__ ilsel_source_t ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ ILSEL_KEY ; 
 int /*<<< orphan*/  ILSEL_LEVELS ; 
 int /*<<< orphan*/  __ilsel_enable (scalar_t__,unsigned int) ; 
 unsigned int find_first_zero_bit (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ilsel_level_map ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 scalar_t__ test_and_set_bit (unsigned int,int /*<<< orphan*/ *) ; 
 scalar_t__ unlikely (int) ; 

int ilsel_enable(ilsel_source_t set)
{
	unsigned int bit;

	if (unlikely(set > ILSEL_KEY)) {
		pr_err("Aliased sources must use ilsel_enable_fixed()\n");
		return -EINVAL;
	}

	do {
		bit = find_first_zero_bit(&ilsel_level_map, ILSEL_LEVELS);
	} while (test_and_set_bit(bit, &ilsel_level_map));

	__ilsel_enable(set, bit);

	return bit;
}