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
struct TYPE_2__ {int /*<<< orphan*/  vrsave; } ;
struct kvm_vcpu {TYPE_1__ arch; } ;

/* Variables and functions */
 int /*<<< orphan*/  SPRN_VRSAVE ; 
 int /*<<< orphan*/  kvmppc_core_vcpu_put (struct kvm_vcpu*) ; 
 int /*<<< orphan*/  mfspr (int /*<<< orphan*/ ) ; 

void kvm_arch_vcpu_put(struct kvm_vcpu *vcpu)
{
	kvmppc_core_vcpu_put(vcpu);
#ifdef CONFIG_BOOKE
	vcpu->arch.vrsave = mfspr(SPRN_VRSAVE);
#endif
}