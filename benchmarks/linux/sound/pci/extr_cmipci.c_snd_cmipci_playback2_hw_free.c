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
struct cmipci {int /*<<< orphan*/ * channel; } ;

/* Variables and functions */
 int snd_cmipci_hw_free (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  snd_cmipci_silence_hack (struct cmipci*,int /*<<< orphan*/ *) ; 
 struct cmipci* snd_pcm_substream_chip (struct snd_pcm_substream*) ; 

__attribute__((used)) static int snd_cmipci_playback2_hw_free(struct snd_pcm_substream *substream)
{
	struct cmipci *cm = snd_pcm_substream_chip(substream);
	snd_cmipci_silence_hack(cm, &cm->channel[1]);
	return snd_cmipci_hw_free(substream);
}