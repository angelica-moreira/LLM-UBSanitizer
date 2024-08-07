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
struct TYPE_2__ {int /*<<< orphan*/  vpid; } ;

/* Variables and functions */
 int /*<<< orphan*/  __vmx_flush_tlb (struct kvm_vcpu*,int /*<<< orphan*/ ,int) ; 
 TYPE_1__* to_vmx (struct kvm_vcpu*) ; 

__attribute__((used)) static inline void vmx_flush_tlb(struct kvm_vcpu *vcpu, bool invalidate_gpa)
{
	__vmx_flush_tlb(vcpu, to_vmx(vcpu)->vpid, invalidate_gpa);
}