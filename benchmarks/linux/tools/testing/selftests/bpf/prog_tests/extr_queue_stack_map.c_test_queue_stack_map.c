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
 int /*<<< orphan*/  QUEUE ; 
 int /*<<< orphan*/  STACK ; 
 int /*<<< orphan*/  test_queue_stack_map_by_type (int /*<<< orphan*/ ) ; 

void test_queue_stack_map(void)
{
	test_queue_stack_map_by_type(QUEUE);
	test_queue_stack_map_by_type(STACK);
}