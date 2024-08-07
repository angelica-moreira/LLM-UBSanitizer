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
struct intel8x0 {scalar_t__ device_type; int /*<<< orphan*/ * ichd; } ;

/* Variables and functions */
 scalar_t__ DEVICE_NFORCE ; 
 int ICHD_SPBAR ; 
 int NVD_SPBAR ; 
 int snd_intel8x0_pcm_open (struct snd_pcm_substream*,int /*<<< orphan*/ *) ; 
 struct intel8x0* snd_pcm_substream_chip (struct snd_pcm_substream*) ; 

__attribute__((used)) static int snd_intel8x0_spdif_open(struct snd_pcm_substream *substream)
{
	struct intel8x0 *chip = snd_pcm_substream_chip(substream);
	int idx = chip->device_type == DEVICE_NFORCE ? NVD_SPBAR : ICHD_SPBAR;

	return snd_intel8x0_pcm_open(substream, &chip->ichd[idx]);
}