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
 int kvm_s390_vcpu_has_irq (struct kvm_vcpu*,int /*<<< orphan*/ ) ; 

int kvm_arch_vcpu_runnable(struct kvm_vcpu *vcpu)
{
	return kvm_s390_vcpu_has_irq(vcpu, 0);
}