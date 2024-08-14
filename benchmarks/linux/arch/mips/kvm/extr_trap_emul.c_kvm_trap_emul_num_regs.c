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
 unsigned long ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kvm_trap_emul_get_one_regs ; 

__attribute__((used)) static unsigned long kvm_trap_emul_num_regs(struct kvm_vcpu *vcpu)
{
	return ARRAY_SIZE(kvm_trap_emul_get_one_regs);
}