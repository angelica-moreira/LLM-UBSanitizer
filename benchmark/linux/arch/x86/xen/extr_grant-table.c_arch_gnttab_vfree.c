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
struct gnttab_vm_area {int /*<<< orphan*/  ptes; int /*<<< orphan*/  area; } ;

/* Variables and functions */
 int /*<<< orphan*/  free_vm_area (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void arch_gnttab_vfree(struct gnttab_vm_area *area)
{
	free_vm_area(area->area);
	kfree(area->ptes);
}