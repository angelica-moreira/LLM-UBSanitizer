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
 char const* fdt_get_string (void const*,int,int /*<<< orphan*/ *) ; 

const char *fdt_string(const void *fdt, int stroffset)
{
	return fdt_get_string(fdt, stroffset, NULL);
}