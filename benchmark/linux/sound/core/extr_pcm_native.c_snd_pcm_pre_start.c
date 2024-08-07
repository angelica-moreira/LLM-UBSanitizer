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
struct snd_pcm_substream {scalar_t__ stream; struct snd_pcm_runtime* runtime; } ;
struct snd_pcm_runtime {int trigger_tstamp_latched; struct snd_pcm_substream* trigger_master; TYPE_1__* status; } ;
struct TYPE_2__ {scalar_t__ state; } ;

/* Variables and functions */
 int EBADFD ; 
 int EPIPE ; 
 scalar_t__ SNDRV_PCM_STATE_PREPARED ; 
 scalar_t__ SNDRV_PCM_STREAM_PLAYBACK ; 
 int /*<<< orphan*/  snd_pcm_playback_data (struct snd_pcm_substream*) ; 

__attribute__((used)) static int snd_pcm_pre_start(struct snd_pcm_substream *substream, int state)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	if (runtime->status->state != SNDRV_PCM_STATE_PREPARED)
		return -EBADFD;
	if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK &&
	    !snd_pcm_playback_data(substream))
		return -EPIPE;
	runtime->trigger_tstamp_latched = false;
	runtime->trigger_master = substream;
	return 0;
}