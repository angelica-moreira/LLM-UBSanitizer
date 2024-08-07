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
struct TYPE_2__ {int timeout; int timer_val; int minutes_mode; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int DIV_ROUND_UP (int,int) ; 
 int EINVAL ; 
 int max_timeout ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 TYPE_1__ watchdog ; 

__attribute__((used)) static int watchdog_set_timeout(int timeout)
{
	if (timeout <= 0
	 || timeout >  max_timeout) {
		pr_err("watchdog timeout out of range\n");
		return -EINVAL;
	}

	mutex_lock(&watchdog.lock);

	watchdog.timeout = timeout;
	if (timeout > 0xff) {
		watchdog.timer_val = DIV_ROUND_UP(timeout, 60);
		watchdog.minutes_mode = true;
	} else {
		watchdog.timer_val = timeout;
		watchdog.minutes_mode = false;
	}

	mutex_unlock(&watchdog.lock);

	return 0;
}