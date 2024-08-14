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
 int /*<<< orphan*/  cpu_relax () ; 
 scalar_t__ imcr_get (unsigned int) ; 

__attribute__((used)) static void cache_block_operation_wait(unsigned int wc_reg)
{
	/* Wait for completion */
	while (imcr_get(wc_reg))
		cpu_relax();
}