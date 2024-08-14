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
struct bfa_ioc_mbox_mod_s {TYPE_1__* mbhdlr; } ;
struct bfa_ioc_s {struct bfa_ioc_mbox_mod_s mbox_mod; } ;
typedef  int /*<<< orphan*/  bfa_ioc_mbox_mcfunc_t ;
struct TYPE_2__ {int /*<<< orphan*/  cbfn; } ;

/* Variables and functions */
 int BFI_MC_MAX ; 

void
bfa_ioc_mbox_register(struct bfa_ioc_s *ioc, bfa_ioc_mbox_mcfunc_t *mcfuncs)
{
	struct bfa_ioc_mbox_mod_s	*mod = &ioc->mbox_mod;
	int				mc;

	for (mc = 0; mc < BFI_MC_MAX; mc++)
		mod->mbhdlr[mc].cbfn = mcfuncs[mc];
}