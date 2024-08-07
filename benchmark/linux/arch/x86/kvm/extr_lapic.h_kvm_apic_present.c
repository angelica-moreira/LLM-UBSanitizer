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
struct TYPE_2__ {int /*<<< orphan*/  apic; } ;
struct kvm_vcpu {TYPE_1__ arch; } ;

/* Variables and functions */
 scalar_t__ kvm_apic_hw_enabled (int /*<<< orphan*/ ) ; 
 scalar_t__ lapic_in_kernel (struct kvm_vcpu*) ; 

__attribute__((used)) static inline bool kvm_apic_present(struct kvm_vcpu *vcpu)
{
	return lapic_in_kernel(vcpu) && kvm_apic_hw_enabled(vcpu->arch.apic);
}