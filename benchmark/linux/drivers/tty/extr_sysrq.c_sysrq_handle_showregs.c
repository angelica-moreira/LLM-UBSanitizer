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
struct pt_regs {int dummy; } ;

/* Variables and functions */
 struct pt_regs* get_irq_regs () ; 
 scalar_t__ in_irq () ; 
 int /*<<< orphan*/  perf_event_print_debug () ; 
 int /*<<< orphan*/  show_regs (struct pt_regs*) ; 

__attribute__((used)) static void sysrq_handle_showregs(int key)
{
	struct pt_regs *regs = NULL;

	if (in_irq())
		regs = get_irq_regs();
	if (regs)
		show_regs(regs);
	perf_event_print_debug();
}