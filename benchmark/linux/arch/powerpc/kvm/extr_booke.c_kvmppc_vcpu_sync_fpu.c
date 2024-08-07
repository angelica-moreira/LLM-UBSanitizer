#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int shadow_msr; TYPE_1__* shared; } ;
struct kvm_vcpu {TYPE_2__ arch; } ;
struct TYPE_3__ {int msr; } ;

/* Variables and functions */
 int MSR_FP ; 

__attribute__((used)) static void kvmppc_vcpu_sync_fpu(struct kvm_vcpu *vcpu)
{
#if defined(CONFIG_PPC_FPU) && !defined(CONFIG_KVM_BOOKE_HV)
	/* We always treat the FP bit as enabled from the host
	   perspective, so only need to adjust the shadow MSR */
	vcpu->arch.shadow_msr &= ~MSR_FP;
	vcpu->arch.shadow_msr |= vcpu->arch.shared->msr & MSR_FP;
#endif
}