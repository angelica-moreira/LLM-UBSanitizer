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
struct task_struct {int dummy; } ;
struct kernel_siginfo {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PIDTYPE_TGID ; 
 int send_signal (int,struct kernel_siginfo*,struct task_struct*,int /*<<< orphan*/ ) ; 

int
__group_send_sig_info(int sig, struct kernel_siginfo *info, struct task_struct *p)
{
	return send_signal(sig, info, p, PIDTYPE_TGID);
}