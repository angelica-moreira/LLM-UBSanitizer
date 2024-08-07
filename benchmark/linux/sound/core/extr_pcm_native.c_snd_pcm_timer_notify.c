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
struct snd_pcm_substream {TYPE_1__* runtime; scalar_t__ timer; } ;
struct TYPE_2__ {int /*<<< orphan*/  trigger_tstamp; } ;

/* Variables and functions */
 int /*<<< orphan*/  snd_timer_notify (scalar_t__,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void snd_pcm_timer_notify(struct snd_pcm_substream *substream,
					int event)
{
#ifdef CONFIG_SND_PCM_TIMER
	if (substream->timer)
		snd_timer_notify(substream->timer, event,
					&substream->runtime->trigger_tstamp);
#endif
}