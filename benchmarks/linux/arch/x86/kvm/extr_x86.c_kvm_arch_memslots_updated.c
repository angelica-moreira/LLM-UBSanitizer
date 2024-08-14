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
typedef  int /*<<< orphan*/  u64 ;
struct kvm {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kvm_mmu_invalidate_mmio_sptes (struct kvm*,int /*<<< orphan*/ ) ; 

void kvm_arch_memslots_updated(struct kvm *kvm, u64 gen)
{
	/*
	 * memslots->generation has been incremented.
	 * mmio generation may have reached its maximum value.
	 */
	kvm_mmu_invalidate_mmio_sptes(kvm, gen);
}