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
struct TYPE_2__ {scalar_t__ nx_lpage_recovery_thread; } ;
struct kvm {TYPE_1__ arch; } ;

/* Variables and functions */
 int /*<<< orphan*/  kthread_stop (scalar_t__) ; 

void kvm_mmu_pre_destroy_vm(struct kvm *kvm)
{
	if (kvm->arch.nx_lpage_recovery_thread)
		kthread_stop(kvm->arch.nx_lpage_recovery_thread);
}