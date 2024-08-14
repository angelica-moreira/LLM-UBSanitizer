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
 int /*<<< orphan*/  local_irq_enable () ; 

__attribute__((used)) static void pmc_leon_idle(void)
{
	/* Interrupts need to be enabled to not hang the CPU */
	local_irq_enable();

	/* For systems without power-down, this will be no-op */
	__asm__ __volatile__ ("wr	%g0, %asr19\n\t");
}