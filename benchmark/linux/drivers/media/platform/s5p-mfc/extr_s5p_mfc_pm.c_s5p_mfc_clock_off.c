#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  clock_gate; } ;

/* Variables and functions */
 int /*<<< orphan*/  atomic_dec (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clk_disable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_ref ; 
 int /*<<< orphan*/  mfc_debug (int,char*,int /*<<< orphan*/ ) ; 
 TYPE_1__* pm ; 

void s5p_mfc_clock_off(void)
{
	atomic_dec(&clk_ref);
	mfc_debug(3, "- %d\n", atomic_read(&clk_ref));

	clk_disable(pm->clock_gate);
}