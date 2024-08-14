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
struct snd_pcm_substream {struct snd_pcm_runtime* runtime; } ;
struct snd_pcm_runtime {struct snd_card_asihpi_pcm* private_data; } ;
struct snd_card_asihpi_pcm {int respawn_timer; int /*<<< orphan*/  timer; } ;

/* Variables and functions */
 int HZ ; 
 scalar_t__ jiffies ; 
 int max (int,int) ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 

__attribute__((used)) static void snd_card_asihpi_pcm_timer_start(struct snd_pcm_substream *
					    substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct snd_card_asihpi_pcm *dpcm = runtime->private_data;
	int expiry;

	expiry = HZ / 200;

	expiry = max(expiry, 1); /* don't let it be zero! */
	mod_timer(&dpcm->timer, jiffies + expiry);
	dpcm->respawn_timer = 1;
}