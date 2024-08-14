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
struct hdspm_midi {int ie; int /*<<< orphan*/  id; struct hdspm* hdspm; } ;
struct hdspm {int control_register; int /*<<< orphan*/  lock; } ;
struct TYPE_2__ {struct hdspm_midi* private_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  HDSPM_controlRegister ; 
 int /*<<< orphan*/  hdspm_write (struct hdspm*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  snd_hdspm_flush_midi_input (struct hdspm*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void
snd_hdspm_midi_input_trigger(struct snd_rawmidi_substream *substream, int up)
{
	struct hdspm *hdspm;
	struct hdspm_midi *hmidi;
	unsigned long flags;

	hmidi = substream->rmidi->private_data;
	hdspm = hmidi->hdspm;

	spin_lock_irqsave (&hdspm->lock, flags);
	if (up) {
		if (!(hdspm->control_register & hmidi->ie)) {
			snd_hdspm_flush_midi_input (hdspm, hmidi->id);
			hdspm->control_register |= hmidi->ie;
		}
	} else {
		hdspm->control_register &= ~hmidi->ie;
	}

	hdspm_write(hdspm, HDSPM_controlRegister, hdspm->control_register);
	spin_unlock_irqrestore (&hdspm->lock, flags);
}