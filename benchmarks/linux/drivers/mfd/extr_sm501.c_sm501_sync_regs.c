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
struct sm501_devdata {int /*<<< orphan*/  regs; } ;

/* Variables and functions */
 int /*<<< orphan*/  smc501_readl (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void sm501_sync_regs(struct sm501_devdata *sm)
{
	smc501_readl(sm->regs);
}