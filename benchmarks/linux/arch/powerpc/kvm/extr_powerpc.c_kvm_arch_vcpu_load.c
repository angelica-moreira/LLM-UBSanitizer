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
 int /*<<< orphan*/  kvmppc_core_vcpu_load (struct kvm_vcpu*,int) ; 
 int /*<<< orphan*/  mtspr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void kvm_arch_vcpu_load(struct kvm_vcpu *vcpu, int cpu)
{
#ifdef CONFIG_BOOKE
	/*
	 * vrsave (formerly usprg0) isn't used by Linux, but may
	 * be used by the guest.
	 *
	 * On non-booke this is associated with Altivec and
	 * is handled by code in book3s.c.
	 */
	mtspr(SPRN_VRSAVE, vcpu->arch.vrsave);
#endif
	kvmppc_core_vcpu_load(vcpu, cpu);
}