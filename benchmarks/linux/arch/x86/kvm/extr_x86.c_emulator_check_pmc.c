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
typedef  int /*<<< orphan*/  u32 ;
struct x86_emulate_ctxt {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  emul_to_vcpu (struct x86_emulate_ctxt*) ; 
 int kvm_pmu_is_valid_msr_idx (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int emulator_check_pmc(struct x86_emulate_ctxt *ctxt,
			      u32 pmc)
{
	return kvm_pmu_is_valid_msr_idx(emul_to_vcpu(ctxt), pmc);
}