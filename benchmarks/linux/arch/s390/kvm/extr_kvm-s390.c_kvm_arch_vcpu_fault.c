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
typedef  int /*<<< orphan*/  vm_fault_t ;
struct vm_fault {scalar_t__ pgoff; int /*<<< orphan*/  page; } ;
struct TYPE_2__ {int /*<<< orphan*/  sie_block; } ;
struct kvm_vcpu {TYPE_1__ arch; int /*<<< orphan*/  kvm; } ;

/* Variables and functions */
 scalar_t__ KVM_S390_SIE_PAGE_OFFSET ; 
 int /*<<< orphan*/  VM_FAULT_SIGBUS ; 
 int /*<<< orphan*/  get_page (int /*<<< orphan*/ ) ; 
 scalar_t__ kvm_is_ucontrol (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  virt_to_page (int /*<<< orphan*/ ) ; 

vm_fault_t kvm_arch_vcpu_fault(struct kvm_vcpu *vcpu, struct vm_fault *vmf)
{
#ifdef CONFIG_KVM_S390_UCONTROL
	if ((vmf->pgoff == KVM_S390_SIE_PAGE_OFFSET)
		 && (kvm_is_ucontrol(vcpu->kvm))) {
		vmf->page = virt_to_page(vcpu->arch.sie_block);
		get_page(vmf->page);
		return 0;
	}
#endif
	return VM_FAULT_SIGBUS;
}