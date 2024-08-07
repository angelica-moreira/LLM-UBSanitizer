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
struct fown_struct {int dummy; } ;

/* Variables and functions */
 int call_int_hook (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct task_struct*,struct fown_struct*,int) ; 
 int /*<<< orphan*/  file_send_sigiotask ; 

int security_file_send_sigiotask(struct task_struct *tsk,
				  struct fown_struct *fown, int sig)
{
	return call_int_hook(file_send_sigiotask, 0, tsk, fown, sig);
}