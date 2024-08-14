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
struct thread_info {int dummy; } ;
struct reg_window {scalar_t__* ins; } ;
struct pt_regs {int tstate; scalar_t__* u_regs; int /*<<< orphan*/  tnpc; int /*<<< orphan*/  tpc; } ;
struct global_reg_snapshot {int tstate; struct thread_info* thread; scalar_t__ rpc; scalar_t__ i7; scalar_t__ o7; int /*<<< orphan*/  tnpc; int /*<<< orphan*/  tpc; } ;
struct TYPE_2__ {struct global_reg_snapshot reg; } ;

/* Variables and functions */
 scalar_t__ STACK_BIAS ; 
 int TSTATE_PRIV ; 
 size_t UREG_FP ; 
 size_t UREG_I7 ; 
 int /*<<< orphan*/  flushw_all () ; 
 TYPE_1__* global_cpu_snapshot ; 
 scalar_t__ kstack_valid (struct thread_info*,unsigned long) ; 

__attribute__((used)) static void __global_reg_self(struct thread_info *tp, struct pt_regs *regs,
			      int this_cpu)
{
	struct global_reg_snapshot *rp;

	flushw_all();

	rp = &global_cpu_snapshot[this_cpu].reg;

	rp->tstate = regs->tstate;
	rp->tpc = regs->tpc;
	rp->tnpc = regs->tnpc;
	rp->o7 = regs->u_regs[UREG_I7];

	if (regs->tstate & TSTATE_PRIV) {
		struct reg_window *rw;

		rw = (struct reg_window *)
			(regs->u_regs[UREG_FP] + STACK_BIAS);
		if (kstack_valid(tp, (unsigned long) rw)) {
			rp->i7 = rw->ins[7];
			rw = (struct reg_window *)
				(rw->ins[6] + STACK_BIAS);
			if (kstack_valid(tp, (unsigned long) rw))
				rp->rpc = rw->ins[7];
		}
	} else {
		rp->i7 = 0;
		rp->rpc = 0;
	}
	rp->thread = tp;
}