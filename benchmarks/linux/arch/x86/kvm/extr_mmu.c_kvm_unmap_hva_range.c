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
 int kvm_handle_hva_range (struct kvm*,unsigned long,unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kvm_unmap_rmapp ; 

int kvm_unmap_hva_range(struct kvm *kvm, unsigned long start, unsigned long end)
{
	return kvm_handle_hva_range(kvm, start, end, 0, kvm_unmap_rmapp);
}