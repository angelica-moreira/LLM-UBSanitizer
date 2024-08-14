#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  sets; } ;
struct TYPE_4__ {TYPE_1__ dcache; } ;

/* Variables and functions */
 TYPE_2__* cpu_data ; 
 int /*<<< orphan*/  sh64_dcache_purge_sets (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void sh64_dcache_purge_all(void)
{

	sh64_dcache_purge_sets(0, cpu_data->dcache.sets);
}