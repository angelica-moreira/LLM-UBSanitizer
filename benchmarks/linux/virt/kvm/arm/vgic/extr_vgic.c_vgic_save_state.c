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
struct TYPE_2__ {int /*<<< orphan*/  gicv3_cpuif; } ;

/* Variables and functions */
 int /*<<< orphan*/  __vgic_v3_save_state (struct kvm_vcpu*) ; 
 TYPE_1__ kvm_vgic_global_state ; 
 int /*<<< orphan*/  static_branch_unlikely (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vgic_v2_save_state (struct kvm_vcpu*) ; 

__attribute__((used)) static inline void vgic_save_state(struct kvm_vcpu *vcpu)
{
	if (!static_branch_unlikely(&kvm_vgic_global_state.gicv3_cpuif))
		vgic_v2_save_state(vcpu);
	else
		__vgic_v3_save_state(vcpu);
}