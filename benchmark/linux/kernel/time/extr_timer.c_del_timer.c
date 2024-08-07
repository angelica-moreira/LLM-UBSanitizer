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
struct timer_list {int dummy; } ;
struct timer_base {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  debug_assert_init (struct timer_list*) ; 
 int detach_if_pending (struct timer_list*,struct timer_base*,int) ; 
 struct timer_base* lock_timer_base (struct timer_list*,unsigned long*) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ timer_pending (struct timer_list*) ; 

int del_timer(struct timer_list *timer)
{
	struct timer_base *base;
	unsigned long flags;
	int ret = 0;

	debug_assert_init(timer);

	if (timer_pending(timer)) {
		base = lock_timer_base(timer, &flags);
		ret = detach_if_pending(timer, base, true);
		raw_spin_unlock_irqrestore(&base->lock, flags);
	}

	return ret;
}