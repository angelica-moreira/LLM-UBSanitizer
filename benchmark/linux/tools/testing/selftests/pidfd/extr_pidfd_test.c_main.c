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
 int ksft_exit_pass () ; 
 int /*<<< orphan*/  ksft_print_header () ; 
 int /*<<< orphan*/  ksft_set_plan (int) ; 
 int /*<<< orphan*/  test_pidfd_poll_exec (int) ; 
 int /*<<< orphan*/  test_pidfd_poll_leader_exit (int) ; 
 int /*<<< orphan*/  test_pidfd_send_signal_exited_fail () ; 
 int /*<<< orphan*/  test_pidfd_send_signal_recycled_pid_fail () ; 
 int /*<<< orphan*/  test_pidfd_send_signal_simple_success () ; 
 int /*<<< orphan*/  test_pidfd_send_signal_syscall_support () ; 

int main(int argc, char **argv)
{
	ksft_print_header();
	ksft_set_plan(4);

	test_pidfd_poll_exec(0);
	test_pidfd_poll_exec(1);
	test_pidfd_poll_leader_exit(0);
	test_pidfd_poll_leader_exit(1);
	test_pidfd_send_signal_syscall_support();
	test_pidfd_send_signal_simple_success();
	test_pidfd_send_signal_exited_fail();
	test_pidfd_send_signal_recycled_pid_fail();

	return ksft_exit_pass();
}