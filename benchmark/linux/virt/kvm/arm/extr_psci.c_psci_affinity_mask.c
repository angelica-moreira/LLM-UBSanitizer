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
 unsigned long AFFINITY_MASK (unsigned long) ; 
 unsigned long MPIDR_HWID_BITMASK ; 

__attribute__((used)) static unsigned long psci_affinity_mask(unsigned long affinity_level)
{
	if (affinity_level <= 3)
		return MPIDR_HWID_BITMASK & AFFINITY_MASK(affinity_level);

	return 0;
}