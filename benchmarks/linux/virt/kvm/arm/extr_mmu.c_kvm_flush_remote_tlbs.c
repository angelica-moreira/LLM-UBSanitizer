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
struct kvm {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __kvm_tlb_flush_vmid ; 
 int /*<<< orphan*/  kvm_call_hyp (int /*<<< orphan*/ ,struct kvm*) ; 

void kvm_flush_remote_tlbs(struct kvm *kvm)
{
	kvm_call_hyp(__kvm_tlb_flush_vmid, kvm);
}