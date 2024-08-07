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
struct TYPE_2__ {int (* vcpu_setup ) (struct kvm_vcpu*) ;} ;

/* Variables and functions */
 TYPE_1__* kvm_mips_callbacks ; 
 int stub1 (struct kvm_vcpu*) ; 

int kvm_arch_vcpu_setup(struct kvm_vcpu *vcpu)
{
	return kvm_mips_callbacks->vcpu_setup(vcpu);
}