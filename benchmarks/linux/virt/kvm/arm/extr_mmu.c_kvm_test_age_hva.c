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
struct TYPE_2__ {int /*<<< orphan*/  pgd; } ;
struct kvm {TYPE_1__ arch; } ;

/* Variables and functions */
 int handle_hva_to_gpa (struct kvm*,unsigned long,unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kvm_test_age_hva_handler ; 
 int /*<<< orphan*/  trace_kvm_test_age_hva (unsigned long) ; 

int kvm_test_age_hva(struct kvm *kvm, unsigned long hva)
{
	if (!kvm->arch.pgd)
		return 0;
	trace_kvm_test_age_hva(hva);
	return handle_hva_to_gpa(kvm, hva, hva, kvm_test_age_hva_handler, NULL);
}