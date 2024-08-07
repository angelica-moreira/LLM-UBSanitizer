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
 int /*<<< orphan*/  wmb () ; 

__attribute__((used)) static inline void qib_flush_wc(void)
{
#if defined(CONFIG_X86_64)
	asm volatile("sfence" : : : "memory");
#else
	wmb(); /* no reorder around wc flush */
#endif
}