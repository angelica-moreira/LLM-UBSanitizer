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
struct clock_event_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  openrisc_timer_set_next (unsigned long) ; 

__attribute__((used)) static int openrisc_timer_set_next_event(unsigned long delta,
					 struct clock_event_device *dev)
{
	openrisc_timer_set_next(delta);
	return 0;
}