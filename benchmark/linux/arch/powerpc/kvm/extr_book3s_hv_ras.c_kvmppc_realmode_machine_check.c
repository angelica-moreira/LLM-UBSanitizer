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
 int /*<<< orphan*/  kvmppc_realmode_mc_power7 (struct kvm_vcpu*) ; 

void kvmppc_realmode_machine_check(struct kvm_vcpu *vcpu)
{
	kvmppc_realmode_mc_power7(vcpu);
}