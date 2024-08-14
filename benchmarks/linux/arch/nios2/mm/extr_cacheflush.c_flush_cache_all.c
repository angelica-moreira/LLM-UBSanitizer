#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  icache_size; int /*<<< orphan*/  dcache_size; } ;

/* Variables and functions */
 int /*<<< orphan*/  __flush_dcache (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __flush_icache (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_1__ cpuinfo ; 

void flush_cache_all(void)
{
	__flush_dcache(0, cpuinfo.dcache_size);
	__flush_icache(0, cpuinfo.icache_size);
}