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
 int test_harness (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  test_harness_set_timeout (int) ; 
 int /*<<< orphan*/  testcases ; 

int main(void)
{
	test_harness_set_timeout(300);
	return test_harness(testcases, "memcmp");
}