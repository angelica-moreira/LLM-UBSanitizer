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
 int MMCR1_PMCSEL_SH (unsigned int) ; 

__attribute__((used)) static void p6_disable_pmc(unsigned int pmc, unsigned long mmcr[])
{
	/* Set PMCxSEL to 0 to disable PMCx */
	if (pmc <= 3)
		mmcr[1] &= ~(0xffUL << MMCR1_PMCSEL_SH(pmc));
}