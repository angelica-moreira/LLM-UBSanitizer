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
 int /*<<< orphan*/  csky_mptimer_irq ; 
 int /*<<< orphan*/  disable_percpu_irq (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int csky_mptimer_dying_cpu(unsigned int cpu)
{
	disable_percpu_irq(csky_mptimer_irq);

	return 0;
}