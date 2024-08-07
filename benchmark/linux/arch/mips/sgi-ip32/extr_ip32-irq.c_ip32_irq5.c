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
 scalar_t__ MIPS_CPU_IRQ_BASE ; 
 int /*<<< orphan*/  do_IRQ (scalar_t__) ; 

__attribute__((used)) static void ip32_irq5(void)
{
	do_IRQ(MIPS_CPU_IRQ_BASE + 7);
}