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
 int /*<<< orphan*/  _RET_IP_ ; 
 int /*<<< orphan*/  check_memory_region (unsigned long,unsigned long,int,int /*<<< orphan*/ ) ; 

void __hwasan_storeN_noabort(unsigned long addr, unsigned long size)
{
	check_memory_region(addr, size, true, _RET_IP_);
}