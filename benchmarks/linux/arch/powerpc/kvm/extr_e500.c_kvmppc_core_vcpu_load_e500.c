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
struct kvm_vcpu {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kvmppc_booke_vcpu_load (struct kvm_vcpu*,int) ; 
 int /*<<< orphan*/  kvmppc_e500_recalc_shadow_pid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  to_e500 (struct kvm_vcpu*) ; 

__attribute__((used)) static void kvmppc_core_vcpu_load_e500(struct kvm_vcpu *vcpu, int cpu)
{
	kvmppc_booke_vcpu_load(vcpu, cpu);

	/* Shadow PID may be expired on local core */
	kvmppc_e500_recalc_shadow_pid(to_e500(vcpu));
}