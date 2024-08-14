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
struct user_regset_view {int dummy; } ;
struct task_struct {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  TIF_32BIT_ADDR ; 
 int /*<<< orphan*/  TIF_32BIT_REGS ; 
 scalar_t__ test_tsk_thread_flag (struct task_struct*,int /*<<< orphan*/ ) ; 
 struct user_regset_view const user_mips64_view ; 
 struct user_regset_view const user_mips_view ; 
 struct user_regset_view const user_mipsn32_view ; 

const struct user_regset_view *task_user_regset_view(struct task_struct *task)
{
#ifdef CONFIG_32BIT
	return &user_mips_view;
#else
#ifdef CONFIG_MIPS32_O32
	if (test_tsk_thread_flag(task, TIF_32BIT_REGS))
		return &user_mips_view;
#endif
#ifdef CONFIG_MIPS32_N32
	if (test_tsk_thread_flag(task, TIF_32BIT_ADDR))
		return &user_mipsn32_view;
#endif
	return &user_mips64_view;
#endif
}