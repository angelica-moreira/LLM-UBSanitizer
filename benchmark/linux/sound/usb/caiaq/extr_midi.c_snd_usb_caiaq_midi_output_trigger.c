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
struct snd_usb_caiaqdev {struct snd_rawmidi_substream* midi_out_substream; int /*<<< orphan*/  midi_out_active; } ;
struct snd_rawmidi_substream {TYPE_1__* rmidi; } ;
struct TYPE_2__ {struct snd_usb_caiaqdev* private_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  snd_usb_caiaq_midi_send (struct snd_usb_caiaqdev*,struct snd_rawmidi_substream*) ; 

__attribute__((used)) static void snd_usb_caiaq_midi_output_trigger(struct snd_rawmidi_substream *substream, int up)
{
	struct snd_usb_caiaqdev *cdev = substream->rmidi->private_data;

	if (up) {
		cdev->midi_out_substream = substream;
		if (!cdev->midi_out_active)
			snd_usb_caiaq_midi_send(cdev, substream);
	} else {
		cdev->midi_out_substream = NULL;
	}
}