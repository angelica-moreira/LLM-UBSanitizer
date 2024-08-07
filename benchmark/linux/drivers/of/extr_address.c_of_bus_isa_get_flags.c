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
typedef  int u32 ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 unsigned int IORESOURCE_IO ; 
 unsigned int IORESOURCE_MEM ; 
 int be32_to_cpup (int /*<<< orphan*/  const*) ; 

__attribute__((used)) static unsigned int of_bus_isa_get_flags(const __be32 *addr)
{
	unsigned int flags = 0;
	u32 w = be32_to_cpup(addr);

	if (w & 1)
		flags |= IORESOURCE_IO;
	else
		flags |= IORESOURCE_MEM;
	return flags;
}