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
 int O_CLOEXEC ; 
 int O_DIRECTORY ; 
 int /*<<< orphan*/  SIGUSR1 ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  ksft_exit_fail_msg (char*,char const*) ; 
 int /*<<< orphan*/  ksft_test_result_pass (char*,char const*) ; 
 int open (char*,int) ; 
 int /*<<< orphan*/  set_signal_received_on_sigusr1 ; 
 int /*<<< orphan*/  signal (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int signal_received ; 
 int sys_pidfd_send_signal (int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int test_pidfd_send_signal_simple_success(void)
{
	int pidfd, ret;
	const char *test_name = "pidfd_send_signal send SIGUSR1";

	pidfd = open("/proc/self", O_DIRECTORY | O_CLOEXEC);
	if (pidfd < 0)
		ksft_exit_fail_msg(
			"%s test: Failed to open process file descriptor\n",
			test_name);

	signal(SIGUSR1, set_signal_received_on_sigusr1);

	ret = sys_pidfd_send_signal(pidfd, SIGUSR1, NULL, 0);
	close(pidfd);
	if (ret < 0)
		ksft_exit_fail_msg("%s test: Failed to send signal\n",
				   test_name);

	if (signal_received != 1)
		ksft_exit_fail_msg("%s test: Failed to receive signal\n",
				   test_name);

	signal_received = 0;
	ksft_test_result_pass("%s test: Sent signal\n", test_name);
	return 0;
}