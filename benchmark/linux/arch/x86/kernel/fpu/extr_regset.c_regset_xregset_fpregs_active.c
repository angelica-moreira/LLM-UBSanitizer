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
struct user_regset {int n; } ;
struct task_struct {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  X86_FEATURE_FXSR ; 
 scalar_t__ boot_cpu_has (int /*<<< orphan*/ ) ; 

int regset_xregset_fpregs_active(struct task_struct *target, const struct user_regset *regset)
{
	if (boot_cpu_has(X86_FEATURE_FXSR))
		return regset->n;
	else
		return 0;
}