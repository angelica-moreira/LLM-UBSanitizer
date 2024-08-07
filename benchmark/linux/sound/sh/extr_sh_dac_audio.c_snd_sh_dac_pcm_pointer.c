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
struct snd_sh_dac {int buffer_begin; int data_buffer; } ;
struct snd_pcm_substream {int dummy; } ;
typedef  int snd_pcm_uframes_t ;

/* Variables and functions */
 struct snd_sh_dac* snd_pcm_substream_chip (struct snd_pcm_substream*) ; 

__attribute__((used)) static
snd_pcm_uframes_t snd_sh_dac_pcm_pointer(struct snd_pcm_substream *substream)
{
	struct snd_sh_dac *chip = snd_pcm_substream_chip(substream);
	int pointer = chip->buffer_begin - chip->data_buffer;

	return pointer;
}