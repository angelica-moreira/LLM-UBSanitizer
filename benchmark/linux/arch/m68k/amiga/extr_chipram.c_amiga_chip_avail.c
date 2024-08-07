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
 unsigned long atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  chipavail ; 
 int /*<<< orphan*/  pr_debug (char*,unsigned long) ; 

unsigned long amiga_chip_avail(void)
{
	unsigned long n = atomic_read(&chipavail);

	pr_debug("amiga_chip_avail : %lu bytes\n", n);
	return n;
}