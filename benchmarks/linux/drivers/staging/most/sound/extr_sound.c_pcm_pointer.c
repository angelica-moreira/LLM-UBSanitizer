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
struct snd_pcm_substream {struct channel* private_data; } ;
struct channel {int /*<<< orphan*/  buffer_pos; } ;
typedef  int /*<<< orphan*/  snd_pcm_uframes_t ;

/* Variables and functions */

__attribute__((used)) static snd_pcm_uframes_t pcm_pointer(struct snd_pcm_substream *substream)
{
	struct channel *channel = substream->private_data;

	return channel->buffer_pos;
}