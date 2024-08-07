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
 int check_memory_region_inline (unsigned long,size_t,int,unsigned long) ; 

bool check_memory_region(unsigned long addr, size_t size, bool write,
				unsigned long ret_ip)
{
	return check_memory_region_inline(addr, size, write, ret_ip);
}