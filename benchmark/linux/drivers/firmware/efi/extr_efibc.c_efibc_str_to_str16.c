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
typedef  char efi_char16_t ;

/* Variables and functions */
 size_t strlen (char const*) ; 

__attribute__((used)) static void efibc_str_to_str16(const char *str, efi_char16_t *str16)
{
	size_t i;

	for (i = 0; i < strlen(str); i++)
		str16[i] = str[i];

	str16[i] = '\0';
}