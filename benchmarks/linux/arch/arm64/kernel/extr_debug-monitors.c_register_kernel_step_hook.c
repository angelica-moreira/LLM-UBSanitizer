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
struct step_hook {int /*<<< orphan*/  node; } ;

/* Variables and functions */
 int /*<<< orphan*/  kernel_step_hook ; 
 int /*<<< orphan*/  register_debug_hook (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

void register_kernel_step_hook(struct step_hook *hook)
{
	register_debug_hook(&hook->node, &kernel_step_hook);
}