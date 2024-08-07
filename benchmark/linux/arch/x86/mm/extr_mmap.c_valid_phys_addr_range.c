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
typedef  size_t phys_addr_t ;

/* Variables and functions */
 size_t __pa (scalar_t__) ; 
 scalar_t__ high_memory ; 

int valid_phys_addr_range(phys_addr_t addr, size_t count)
{
	return addr + count - 1 <= __pa(high_memory - 1);
}