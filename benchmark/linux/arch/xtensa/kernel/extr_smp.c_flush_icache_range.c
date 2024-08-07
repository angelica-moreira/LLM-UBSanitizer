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
struct flush_data {unsigned long addr1; unsigned long addr2; } ;

/* Variables and functions */
 int /*<<< orphan*/  ipi_flush_icache_range ; 
 int /*<<< orphan*/  on_each_cpu (int /*<<< orphan*/ ,struct flush_data*,int) ; 

void flush_icache_range(unsigned long start, unsigned long end)
{
	struct flush_data fd = {
		.addr1 = start,
		.addr2 = end,
	};
	on_each_cpu(ipi_flush_icache_range, &fd, 1);
}