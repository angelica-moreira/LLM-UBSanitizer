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
struct snd_rme9652 {scalar_t__ playback_pid; scalar_t__ capture_pid; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static inline int snd_rme9652_use_is_exclusive(struct snd_rme9652 *rme9652)
{
	unsigned long flags;
	int ret = 1;

	spin_lock_irqsave(&rme9652->lock, flags);
	if ((rme9652->playback_pid != rme9652->capture_pid) &&
	    (rme9652->playback_pid >= 0) && (rme9652->capture_pid >= 0)) {
		ret = 0;
	}
	spin_unlock_irqrestore(&rme9652->lock, flags);
	return ret;
}