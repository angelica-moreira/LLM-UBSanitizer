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
typedef  int /*<<< orphan*/  uint32_t ;

/* Variables and functions */
 int test_bit (int /*<<< orphan*/ ,unsigned long*) ; 

__attribute__((used)) static int is_dirty_callback(uint32_t index, bool *value, void *context)
{
	unsigned long *bits = context;
	*value = test_bit(index, bits);
	return 0;
}