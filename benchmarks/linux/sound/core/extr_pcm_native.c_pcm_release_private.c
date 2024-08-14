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

/* Variables and functions */
 scalar_t__ snd_pcm_stream_linked (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  snd_pcm_unlink (struct snd_pcm_substream*) ; 

__attribute__((used)) static void pcm_release_private(struct snd_pcm_substream *substream)
{
	if (snd_pcm_stream_linked(substream))
		snd_pcm_unlink(substream);
}