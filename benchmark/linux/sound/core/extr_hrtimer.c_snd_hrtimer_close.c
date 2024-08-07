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
struct snd_timer {struct snd_hrtimer* private_data; int /*<<< orphan*/  lock; scalar_t__ running; } ;
struct snd_hrtimer {int in_callback; int /*<<< orphan*/  hrt; } ;

/* Variables and functions */
 int /*<<< orphan*/  hrtimer_cancel (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct snd_hrtimer*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int snd_hrtimer_close(struct snd_timer *t)
{
	struct snd_hrtimer *stime = t->private_data;

	if (stime) {
		spin_lock_irq(&t->lock);
		t->running = 0; /* just to be sure */
		stime->in_callback = 1; /* skip start/stop */
		spin_unlock_irq(&t->lock);

		hrtimer_cancel(&stime->hrt);
		kfree(stime);
		t->private_data = NULL;
	}
	return 0;
}