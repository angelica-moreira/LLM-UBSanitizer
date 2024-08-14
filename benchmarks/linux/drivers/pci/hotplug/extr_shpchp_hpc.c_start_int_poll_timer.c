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
struct TYPE_2__ {scalar_t__ expires; } ;
struct controller {TYPE_1__ poll_timer; } ;

/* Variables and functions */
 int HZ ; 
 int /*<<< orphan*/  add_timer (TYPE_1__*) ; 
 scalar_t__ jiffies ; 

__attribute__((used)) static void start_int_poll_timer(struct controller *ctrl, int sec)
{
	/* Clamp to sane value */
	if ((sec <= 0) || (sec > 60))
		sec = 2;

	ctrl->poll_timer.expires = jiffies + sec * HZ;
	add_timer(&ctrl->poll_timer);
}