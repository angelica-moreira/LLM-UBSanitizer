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
 int FPU_EFLAGS ; 
 int X86_EFLAGS_ZF ; 
 int /*<<< orphan*/  fcmovCC () ; 

void fcmove(void)
{
	if (FPU_EFLAGS & X86_EFLAGS_ZF)
		fcmovCC();
}