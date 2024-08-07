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
struct TYPE_2__ {int /*<<< orphan*/  flags; } ;
struct kernel_vm86_regs {TYPE_1__ pt; } ;

/* Variables and functions */
 int /*<<< orphan*/  X86_EFLAGS_AC ; 

__attribute__((used)) static inline void clear_AC(struct kernel_vm86_regs *regs)
{
	regs->pt.flags &= ~X86_EFLAGS_AC;
}