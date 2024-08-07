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
struct TYPE_2__ {int /*<<< orphan*/ * rmap; } ;
struct kvm_memory_slot {TYPE_1__ arch; } ;

/* Variables and functions */
 int /*<<< orphan*/  vfree (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void kvmppc_core_free_memslot_hv(struct kvm_memory_slot *free,
					struct kvm_memory_slot *dont)
{
	if (!dont || free->arch.rmap != dont->arch.rmap) {
		vfree(free->arch.rmap);
		free->arch.rmap = NULL;
	}
}