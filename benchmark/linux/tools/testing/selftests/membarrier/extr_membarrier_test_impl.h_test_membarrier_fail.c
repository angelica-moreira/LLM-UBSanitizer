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
 int MEMBARRIER_CMD_PRIVATE_EXPEDITED_SYNC_CORE ; 
 int /*<<< orphan*/  MEMBARRIER_CMD_QUERY ; 
 int /*<<< orphan*/  ksft_test_result_fail (char*) ; 
 int sys_membarrier (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int test_membarrier_cmd_fail () ; 
 int test_membarrier_flags_fail () ; 
 int test_membarrier_private_expedited_fail () ; 
 int test_membarrier_private_expedited_sync_core_fail () ; 

__attribute__((used)) static int test_membarrier_fail(void)
{
	int status;

	status = test_membarrier_cmd_fail();
	if (status)
		return status;
	status = test_membarrier_flags_fail();
	if (status)
		return status;
	status = test_membarrier_private_expedited_fail();
	if (status)
		return status;
	status = sys_membarrier(MEMBARRIER_CMD_QUERY, 0);
	if (status < 0) {
		ksft_test_result_fail("sys_membarrier() failed\n");
		return status;
	}
	if (status & MEMBARRIER_CMD_PRIVATE_EXPEDITED_SYNC_CORE) {
		status = test_membarrier_private_expedited_sync_core_fail();
		if (status)
			return status;
	}
	return 0;
}