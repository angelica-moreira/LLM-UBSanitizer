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
 size_t fdt_header_size_ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fdt_version (void const*) ; 

__attribute__((used)) static inline size_t fdt_header_size(const void *fdt)
{
	return fdt_header_size_(fdt_version(fdt));
}