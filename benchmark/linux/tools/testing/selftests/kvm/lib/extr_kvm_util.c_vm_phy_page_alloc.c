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
typedef  int /*<<< orphan*/  vm_paddr_t ;
typedef  int /*<<< orphan*/  uint32_t ;
struct kvm_vm {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  vm_phy_pages_alloc (struct kvm_vm*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

vm_paddr_t vm_phy_page_alloc(struct kvm_vm *vm, vm_paddr_t paddr_min,
			     uint32_t memslot)
{
	return vm_phy_pages_alloc(vm, 1, paddr_min, memslot);
}