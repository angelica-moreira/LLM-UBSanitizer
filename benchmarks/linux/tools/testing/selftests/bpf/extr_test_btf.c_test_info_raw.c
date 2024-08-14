#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {unsigned int info_raw_test_num; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 TYPE_1__ args ; 
 int count_result (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  do_test_info_raw (unsigned int) ; 
 int /*<<< orphan*/  info_raw_tests ; 

__attribute__((used)) static int test_info_raw(void)
{
	unsigned int i;
	int err = 0;

	if (args.info_raw_test_num)
		return count_result(do_test_info_raw(args.info_raw_test_num));

	for (i = 1; i <= ARRAY_SIZE(info_raw_tests); i++)
		err |= count_result(do_test_info_raw(i));

	return err;
}