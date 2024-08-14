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
struct kvm_memory_slot {int dummy; } ;
struct TYPE_4__ {TYPE_1__* kvm_ops; } ;
struct kvm {TYPE_2__ arch; } ;
struct TYPE_3__ {int (* create_memslot ) (struct kvm_memory_slot*,unsigned long) ;} ;

/* Variables and functions */
 int stub1 (struct kvm_memory_slot*,unsigned long) ; 

int kvmppc_core_create_memslot(struct kvm *kvm, struct kvm_memory_slot *slot,
			       unsigned long npages)
{
	return kvm->arch.kvm_ops->create_memslot(slot, npages);
}