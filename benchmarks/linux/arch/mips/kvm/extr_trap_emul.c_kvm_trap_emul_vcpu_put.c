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
struct kvm_vcpu {int dummy; } ;
struct TYPE_2__ {int flags; int /*<<< orphan*/  mm; } ;

/* Variables and functions */
 int PF_VCPU ; 
 int /*<<< orphan*/  check_switch_mmu_context (int /*<<< orphan*/ ) ; 
 TYPE_1__* current ; 
 int /*<<< orphan*/  ehb () ; 
 int /*<<< orphan*/  kvm_lose_fpu (struct kvm_vcpu*) ; 
 int /*<<< orphan*/  kvm_mips_resume_mm (int) ; 

__attribute__((used)) static int kvm_trap_emul_vcpu_put(struct kvm_vcpu *vcpu, int cpu)
{
	kvm_lose_fpu(vcpu);

	if (current->flags & PF_VCPU) {
		/* Restore normal Linux process memory map */
		check_switch_mmu_context(current->mm);
		kvm_mips_resume_mm(cpu);
		ehb();
	}

	return 0;
}