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
struct uml_pt_regs {int dummy; } ;
struct siginfo {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  WINCH_IRQ ; 
 int /*<<< orphan*/  do_IRQ (int /*<<< orphan*/ ,struct uml_pt_regs*) ; 

void winch(int sig, struct siginfo *unused_si, struct uml_pt_regs *regs)
{
	do_IRQ(WINCH_IRQ, regs);
}