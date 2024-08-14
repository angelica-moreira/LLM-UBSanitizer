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
struct snd_pcm_substream {int dummy; } ;
struct pcm_substream {int active; int /*<<< orphan*/  lock; } ;
struct pcm_runtime {scalar_t__ panic; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int EPIPE ; 
#define  SNDRV_PCM_TRIGGER_PAUSE_PUSH 131 
#define  SNDRV_PCM_TRIGGER_PAUSE_RELEASE 130 
#define  SNDRV_PCM_TRIGGER_START 129 
#define  SNDRV_PCM_TRIGGER_STOP 128 
 struct pcm_substream* hiface_pcm_get_substream (struct snd_pcm_substream*) ; 
 struct pcm_runtime* snd_pcm_substream_chip (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int hiface_pcm_trigger(struct snd_pcm_substream *alsa_sub, int cmd)
{
	struct pcm_substream *sub = hiface_pcm_get_substream(alsa_sub);
	struct pcm_runtime *rt = snd_pcm_substream_chip(alsa_sub);

	if (rt->panic)
		return -EPIPE;
	if (!sub)
		return -ENODEV;

	switch (cmd) {
	case SNDRV_PCM_TRIGGER_START:
	case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
		spin_lock_irq(&sub->lock);
		sub->active = true;
		spin_unlock_irq(&sub->lock);
		return 0;

	case SNDRV_PCM_TRIGGER_STOP:
	case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
		spin_lock_irq(&sub->lock);
		sub->active = false;
		spin_unlock_irq(&sub->lock);
		return 0;

	default:
		return -EINVAL;
	}
}