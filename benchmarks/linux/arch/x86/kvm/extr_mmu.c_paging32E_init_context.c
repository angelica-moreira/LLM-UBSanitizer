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
struct kvm_mmu {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PT32E_ROOT_LEVEL ; 
 int /*<<< orphan*/  paging64_init_context_common (struct kvm_vcpu*,struct kvm_mmu*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void paging32E_init_context(struct kvm_vcpu *vcpu,
				   struct kvm_mmu *context)
{
	paging64_init_context_common(vcpu, context, PT32E_ROOT_LEVEL);
}