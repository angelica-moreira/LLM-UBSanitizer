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
 int __TEST_MTX_LAST ; 
 int __test_mutex (int) ; 

__attribute__((used)) static int test_mutex(void)
{
	int ret;
	int i;

	for (i = 0; i < __TEST_MTX_LAST; i++) {
		ret = __test_mutex(i);
		if (ret)
			return ret;
	}

	return 0;
}