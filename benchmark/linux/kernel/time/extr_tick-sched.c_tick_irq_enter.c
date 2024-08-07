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
 int /*<<< orphan*/  tick_check_oneshot_broadcast_this_cpu () ; 
 int /*<<< orphan*/  tick_nohz_irq_enter () ; 

void tick_irq_enter(void)
{
	tick_check_oneshot_broadcast_this_cpu();
	tick_nohz_irq_enter();
}