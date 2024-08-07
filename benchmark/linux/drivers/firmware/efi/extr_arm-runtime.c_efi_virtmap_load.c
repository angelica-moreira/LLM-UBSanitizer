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

/* Variables and functions */
 int /*<<< orphan*/  efi_mm ; 
 int /*<<< orphan*/  efi_set_pgd (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  preempt_disable () ; 

void efi_virtmap_load(void)
{
	preempt_disable();
	efi_set_pgd(&efi_mm);
}