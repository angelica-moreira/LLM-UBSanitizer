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
 int /*<<< orphan*/  op_axp_cpu_start (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  smp_call_function (int /*<<< orphan*/  (*) (int /*<<< orphan*/ *),int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int
op_axp_start(void)
{
	smp_call_function(op_axp_cpu_start, NULL, 1);
	op_axp_cpu_start(NULL);
	return 0;
}