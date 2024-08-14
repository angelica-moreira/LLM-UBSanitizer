#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct vcpu_svm {TYPE_2__* vmcb; int /*<<< orphan*/  vcpu; } ;
struct TYPE_3__ {int /*<<< orphan*/  int_ctl; } ;
struct TYPE_4__ {TYPE_1__ control; } ;

/* Variables and functions */
 int /*<<< orphan*/  VMCB_INTR ; 
 int /*<<< orphan*/  V_IRQ_MASK ; 
 int /*<<< orphan*/  disable_gif (struct vcpu_svm*) ; 
 int kvm_skip_emulated_instruction (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kvm_vcpu_apicv_active (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mark_dirty (TYPE_2__*,int /*<<< orphan*/ ) ; 
 scalar_t__ nested_svm_check_permissions (struct vcpu_svm*) ; 
 int /*<<< orphan*/  svm_clear_vintr (struct vcpu_svm*) ; 

__attribute__((used)) static int clgi_interception(struct vcpu_svm *svm)
{
	int ret;

	if (nested_svm_check_permissions(svm))
		return 1;

	ret = kvm_skip_emulated_instruction(&svm->vcpu);

	disable_gif(svm);

	/* After a CLGI no interrupts should come */
	if (!kvm_vcpu_apicv_active(&svm->vcpu)) {
		svm_clear_vintr(svm);
		svm->vmcb->control.int_ctl &= ~V_IRQ_MASK;
		mark_dirty(svm->vmcb, VMCB_INTR);
	}

	return ret;
}