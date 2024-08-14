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
typedef  int /*<<< orphan*/  u64 ;

/* Variables and functions */
 int /*<<< orphan*/  cpumask_of (int) ; 
 int /*<<< orphan*/  xcall_call_function_single ; 
 int /*<<< orphan*/  xcall_deliver (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void arch_send_call_function_single_ipi(int cpu)
{
	xcall_deliver((u64) &xcall_call_function_single, 0, 0,
		      cpumask_of(cpu));
}