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
struct ftrace_insn {int /*<<< orphan*/  disp; int /*<<< orphan*/  opc; } ;

/* Variables and functions */
 int /*<<< orphan*/  BREAKPOINT_INSTRUCTION ; 
 int /*<<< orphan*/  KPROBE_ON_FTRACE_CALL ; 

__attribute__((used)) static inline void ftrace_generate_kprobe_call_insn(struct ftrace_insn *insn)
{
#ifdef CONFIG_KPROBES
	insn->opc = BREAKPOINT_INSTRUCTION;
	insn->disp = KPROBE_ON_FTRACE_CALL;
#endif
}