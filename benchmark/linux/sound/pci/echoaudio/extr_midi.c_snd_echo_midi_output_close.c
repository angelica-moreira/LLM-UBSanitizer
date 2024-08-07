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
struct snd_rawmidi_substream {TYPE_1__* rmidi; } ;
struct echoaudio {int /*<<< orphan*/ * midi_out; } ;
struct TYPE_2__ {struct echoaudio* private_data; } ;

/* Variables and functions */

__attribute__((used)) static int snd_echo_midi_output_close(struct snd_rawmidi_substream *substream)
{
	struct echoaudio *chip = substream->rmidi->private_data;

	chip->midi_out = NULL;
	return 0;
}