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
struct alarm_base {int /*<<< orphan*/  lock; } ;
struct TYPE_2__ {int /*<<< orphan*/  expires; } ;
struct alarm {size_t type; int /*<<< orphan*/  timer; TYPE_1__ node; } ;

/* Variables and functions */
 struct alarm_base* alarm_bases ; 
 int /*<<< orphan*/  alarmtimer_enqueue (struct alarm_base*,struct alarm*) ; 
 int /*<<< orphan*/  hrtimer_restart (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hrtimer_set_expires (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

void alarm_restart(struct alarm *alarm)
{
	struct alarm_base *base = &alarm_bases[alarm->type];
	unsigned long flags;

	spin_lock_irqsave(&base->lock, flags);
	hrtimer_set_expires(&alarm->timer, alarm->node.expires);
	hrtimer_restart(&alarm->timer);
	alarmtimer_enqueue(base, alarm);
	spin_unlock_irqrestore(&base->lock, flags);
}