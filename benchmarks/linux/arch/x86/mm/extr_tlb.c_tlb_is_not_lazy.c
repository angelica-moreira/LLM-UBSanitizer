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
struct TYPE_2__ {int /*<<< orphan*/  is_lazy; } ;

/* Variables and functions */
 TYPE_1__ cpu_tlbstate ; 
 int /*<<< orphan*/  per_cpu (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static bool tlb_is_not_lazy(int cpu, void *data)
{
	return !per_cpu(cpu_tlbstate.is_lazy, cpu);
}