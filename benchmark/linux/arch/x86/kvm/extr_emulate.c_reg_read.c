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
typedef  int /*<<< orphan*/  ulong ;
struct x86_emulate_ctxt {int regs_valid; int /*<<< orphan*/ * _regs; TYPE_1__* ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* read_gpr ) (struct x86_emulate_ctxt*,unsigned int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct x86_emulate_ctxt*,unsigned int) ; 

__attribute__((used)) static ulong reg_read(struct x86_emulate_ctxt *ctxt, unsigned nr)
{
	if (!(ctxt->regs_valid & (1 << nr))) {
		ctxt->regs_valid |= 1 << nr;
		ctxt->_regs[nr] = ctxt->ops->read_gpr(ctxt, nr);
	}
	return ctxt->_regs[nr];
}