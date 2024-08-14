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
struct kvm_mp_state {int dummy; } ;

/* Variables and functions */
 int KVM_MP_STATE_OPERATING ; 
 int KVM_MP_STATE_STOPPED ; 
 scalar_t__ is_vcpu_stopped (struct kvm_vcpu*) ; 
 int /*<<< orphan*/  vcpu_load (struct kvm_vcpu*) ; 
 int /*<<< orphan*/  vcpu_put (struct kvm_vcpu*) ; 

int kvm_arch_vcpu_ioctl_get_mpstate(struct kvm_vcpu *vcpu,
				    struct kvm_mp_state *mp_state)
{
	int ret;

	vcpu_load(vcpu);

	/* CHECK_STOP and LOAD are not supported yet */
	ret = is_vcpu_stopped(vcpu) ? KVM_MP_STATE_STOPPED :
				      KVM_MP_STATE_OPERATING;

	vcpu_put(vcpu);
	return ret;
}