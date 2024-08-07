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
struct efi_variable {int DataSize; int /*<<< orphan*/  Data; int /*<<< orphan*/  Attributes; } ;
struct efivar_entry {struct efi_variable var; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 scalar_t__ efivar_entry_get (struct efivar_entry*,int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (char*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static ssize_t
efivar_data_read(struct efivar_entry *entry, char *buf)
{
	struct efi_variable *var = &entry->var;

	if (!entry || !buf)
		return -EINVAL;

	var->DataSize = 1024;
	if (efivar_entry_get(entry, &var->Attributes, &var->DataSize, var->Data))
		return -EIO;

	memcpy(buf, var->Data, var->DataSize);
	return var->DataSize;
}