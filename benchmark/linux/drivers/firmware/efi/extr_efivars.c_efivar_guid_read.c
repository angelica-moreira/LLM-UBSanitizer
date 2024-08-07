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
struct efi_variable {int /*<<< orphan*/  VendorGuid; } ;
struct efivar_entry {struct efi_variable var; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  efi_guid_to_str (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  sprintf (char*,char*) ; 
 int /*<<< orphan*/  strlen (char*) ; 

__attribute__((used)) static ssize_t
efivar_guid_read(struct efivar_entry *entry, char *buf)
{
	struct efi_variable *var = &entry->var;
	char *str = buf;

	if (!entry || !buf)
		return 0;

	efi_guid_to_str(&var->VendorGuid, str);
	str += strlen(str);
	str += sprintf(str, "\n");

	return str - buf;
}