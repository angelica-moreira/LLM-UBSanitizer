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
struct desc_ptr {int /*<<< orphan*/  address; int /*<<< orphan*/  size; } ;

/* Variables and functions */
 int /*<<< orphan*/  GUEST_IDTR_BASE ; 
 int /*<<< orphan*/  GUEST_IDTR_LIMIT ; 
 int /*<<< orphan*/  vmcs_read32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vmcs_readl (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void vmx_get_idt(struct kvm_vcpu *vcpu, struct desc_ptr *dt)
{
	dt->size = vmcs_read32(GUEST_IDTR_LIMIT);
	dt->address = vmcs_readl(GUEST_IDTR_BASE);
}