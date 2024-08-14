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
 scalar_t__ TUL_NVRAM ; 
 int /*<<< orphan*/  initio_se2_instr (unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outb (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  udelay (int) ; 

void initio_se2_ew_ds(unsigned long base)
{
	initio_se2_instr(base, 0);	/* EWDS */
	outb(0, base + TUL_NVRAM);	/* -CS  */
	udelay(30);
}