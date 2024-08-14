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
typedef  int uint64_t ;

/* Variables and functions */
 int PM_SWAP ; 
 unsigned long PM_SWAP_OFFSET (int) ; 

__attribute__((used)) static unsigned long pagemap_swap_offset(uint64_t val)
{
	return val & PM_SWAP ? PM_SWAP_OFFSET(val) : 0;
}