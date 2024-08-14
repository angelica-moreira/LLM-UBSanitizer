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
struct cpuinfo_x86 {int x86; scalar_t__* x86_vendor_id; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* c_identify ) (struct cpuinfo_x86*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  X86_EFLAGS_AC ; 
 int X86_VENDOR_NUM ; 
 TYPE_1__** cpu_devs ; 
 scalar_t__ flag_is_changeable_p (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_cpu_vendor (struct cpuinfo_x86*) ; 
 int /*<<< orphan*/  stub1 (struct cpuinfo_x86*) ; 

__attribute__((used)) static void identify_cpu_without_cpuid(struct cpuinfo_x86 *c)
{
#ifdef CONFIG_X86_32
	int i;

	/*
	 * First of all, decide if this is a 486 or higher
	 * It's a 486 if we can modify the AC flag
	 */
	if (flag_is_changeable_p(X86_EFLAGS_AC))
		c->x86 = 4;
	else
		c->x86 = 3;

	for (i = 0; i < X86_VENDOR_NUM; i++)
		if (cpu_devs[i] && cpu_devs[i]->c_identify) {
			c->x86_vendor_id[0] = 0;
			cpu_devs[i]->c_identify(c);
			if (c->x86_vendor_id[0]) {
				get_cpu_vendor(c);
				break;
			}
		}
#endif
}