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
struct snd_tscm {scalar_t__ dev_lock_count; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  snd_tscm_stream_lock_changed (struct snd_tscm*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

void snd_tscm_stream_lock_release(struct snd_tscm *tscm)
{
	spin_lock_irq(&tscm->lock);

	if (WARN_ON(tscm->dev_lock_count <= 0))
		goto end;
	if (--tscm->dev_lock_count == 0)
		snd_tscm_stream_lock_changed(tscm);
end:
	spin_unlock_irq(&tscm->lock);
}