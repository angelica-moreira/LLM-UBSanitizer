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
 int HZ ; 
 int LGR_TIMER_INTERVAL_SECS ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  lgr_timer ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 

__attribute__((used)) static void lgr_timer_set(void)
{
	mod_timer(&lgr_timer, jiffies + LGR_TIMER_INTERVAL_SECS * HZ);
}