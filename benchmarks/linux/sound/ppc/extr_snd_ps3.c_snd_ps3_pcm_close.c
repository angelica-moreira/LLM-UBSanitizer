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
 int /*<<< orphan*/  snd_ps3_mute (int) ; 

__attribute__((used)) static int snd_ps3_pcm_close(struct snd_pcm_substream *substream)
{
	/* mute on */
	snd_ps3_mute(1);
	return 0;
}