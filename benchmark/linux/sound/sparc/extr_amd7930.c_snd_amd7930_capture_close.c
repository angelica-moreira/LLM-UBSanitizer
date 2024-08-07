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
struct snd_amd7930 {int /*<<< orphan*/ * capture_substream; } ;

/* Variables and functions */
 struct snd_amd7930* snd_pcm_substream_chip (struct snd_pcm_substream*) ; 

__attribute__((used)) static int snd_amd7930_capture_close(struct snd_pcm_substream *substream)
{
	struct snd_amd7930 *amd = snd_pcm_substream_chip(substream);

	amd->capture_substream = NULL;
	return 0;
}