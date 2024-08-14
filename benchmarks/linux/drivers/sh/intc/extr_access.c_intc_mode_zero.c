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

__attribute__((used)) static unsigned long intc_mode_zero(unsigned long addr,
				    unsigned long handle,
				    unsigned long (*fn)(unsigned long,
					       unsigned long,
					       unsigned long),
				    unsigned int irq)
{
	return fn(addr, handle, 0);
}