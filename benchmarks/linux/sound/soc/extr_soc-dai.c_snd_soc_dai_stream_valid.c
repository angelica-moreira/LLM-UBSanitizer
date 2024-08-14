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
struct snd_soc_pcm_stream {int channels_min; } ;
struct snd_soc_dai {TYPE_1__* driver; } ;
struct TYPE_2__ {struct snd_soc_pcm_stream capture; struct snd_soc_pcm_stream playback; } ;

/* Variables and functions */
 int SNDRV_PCM_STREAM_PLAYBACK ; 

bool snd_soc_dai_stream_valid(struct snd_soc_dai *dai, int dir)
{
	struct snd_soc_pcm_stream *stream;

	if (dir == SNDRV_PCM_STREAM_PLAYBACK)
		stream = &dai->driver->playback;
	else
		stream = &dai->driver->capture;

	/* If the codec specifies any channels at all, it supports the stream */
	return stream->channels_min;
}