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
struct bt455_regs {scalar_t__ addr_clr; } ;

/* Variables and functions */
 int /*<<< orphan*/  mb () ; 

__attribute__((used)) static inline void bt455_reset_reg(struct bt455_regs *regs)
{
	mb();
	regs->addr_clr = 0;
}