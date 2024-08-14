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
struct efi {int dummy; } ;

/* Variables and functions */
 struct efi efi ; 

__attribute__((used)) static struct efi *get_efi(void)
{
#ifdef CONFIG_EFI
	return &efi;
#else
	return NULL;
#endif
}