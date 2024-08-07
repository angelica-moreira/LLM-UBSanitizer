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
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  efi_status_t ;
typedef  int /*<<< orphan*/  efi_guid_t ;
typedef  int /*<<< orphan*/  efi_char16_t ;

/* Variables and functions */
 int /*<<< orphan*/  EFI_NOT_READY ; 
 scalar_t__ down_trylock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  efi_call_virt (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned long,void*) ; 
 int /*<<< orphan*/  efi_runtime_lock ; 
 int /*<<< orphan*/  set_variable ; 
 int /*<<< orphan*/  up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static efi_status_t
virt_efi_set_variable_nonblocking(efi_char16_t *name, efi_guid_t *vendor,
				  u32 attr, unsigned long data_size,
				  void *data)
{
	efi_status_t status;

	if (down_trylock(&efi_runtime_lock))
		return EFI_NOT_READY;

	status = efi_call_virt(set_variable, name, vendor, attr, data_size,
			       data);
	up(&efi_runtime_lock);
	return status;
}