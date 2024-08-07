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
struct TYPE_2__ {int /*<<< orphan*/  pgtable; } ;
struct kvm {TYPE_1__ arch; int /*<<< orphan*/  mm; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  pgd_alloc (int /*<<< orphan*/ ) ; 

int kvmppc_init_vm_radix(struct kvm *kvm)
{
	kvm->arch.pgtable = pgd_alloc(kvm->mm);
	if (!kvm->arch.pgtable)
		return -ENOMEM;
	return 0;
}