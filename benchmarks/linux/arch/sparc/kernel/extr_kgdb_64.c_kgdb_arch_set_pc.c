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
struct pt_regs {unsigned long tpc; int tnpc; } ;

/* Variables and functions */

void kgdb_arch_set_pc(struct pt_regs *regs, unsigned long ip)
{
	regs->tpc = ip;
	regs->tnpc = regs->tpc + 4;
}