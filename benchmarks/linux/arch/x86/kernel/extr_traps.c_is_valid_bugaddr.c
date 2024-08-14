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
 unsigned short INSN_UD0 ; 
 unsigned short INSN_UD2 ; 
 unsigned long TASK_SIZE_MAX ; 
 scalar_t__ probe_kernel_address (unsigned short*,unsigned short) ; 

int is_valid_bugaddr(unsigned long addr)
{
	unsigned short ud;

	if (addr < TASK_SIZE_MAX)
		return 0;

	if (probe_kernel_address((unsigned short *)addr, ud))
		return 0;

	return ud == INSN_UD0 || ud == INSN_UD2;
}