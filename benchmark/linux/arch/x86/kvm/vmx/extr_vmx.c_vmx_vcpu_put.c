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
 int /*<<< orphan*/  to_vmx (struct kvm_vcpu*) ; 
 int /*<<< orphan*/  vmx_prepare_switch_to_host (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vmx_vcpu_pi_put (struct kvm_vcpu*) ; 

__attribute__((used)) static void vmx_vcpu_put(struct kvm_vcpu *vcpu)
{
	vmx_vcpu_pi_put(vcpu);

	vmx_prepare_switch_to_host(to_vmx(vcpu));
}