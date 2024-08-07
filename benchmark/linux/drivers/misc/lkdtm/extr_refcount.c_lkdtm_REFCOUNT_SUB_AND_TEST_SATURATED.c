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
typedef  int /*<<< orphan*/  refcount_t ;

/* Variables and functions */
 int /*<<< orphan*/  REFCOUNT_INIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REFCOUNT_SATURATED ; 
 int /*<<< orphan*/  check_saturated (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 
 scalar_t__ refcount_sub_and_test (int,int /*<<< orphan*/ *) ; 

void lkdtm_REFCOUNT_SUB_AND_TEST_SATURATED(void)
{
	refcount_t sat = REFCOUNT_INIT(REFCOUNT_SATURATED);

	pr_info("attempting bad refcount_sub_and_test() from saturated\n");
	if (refcount_sub_and_test(8, &sat))
		pr_warn("Weird: refcount_sub_and_test() reported zero\n");

	check_saturated(&sat);
}