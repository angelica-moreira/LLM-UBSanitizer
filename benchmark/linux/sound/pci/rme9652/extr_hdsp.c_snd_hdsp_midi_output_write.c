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
struct hdsp_midi {int /*<<< orphan*/  lock; int /*<<< orphan*/  id; int /*<<< orphan*/  hdsp; scalar_t__ output; } ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 int snd_hdsp_midi_output_possible (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hdsp_midi_write_byte (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned char) ; 
 int snd_rawmidi_transmit (scalar_t__,unsigned char*,int) ; 
 int /*<<< orphan*/  snd_rawmidi_transmit_empty (scalar_t__) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static int snd_hdsp_midi_output_write (struct hdsp_midi *hmidi)
{
	unsigned long flags;
	int n_pending;
	int to_write;
	int i;
	unsigned char buf[128];

	/* Output is not interrupt driven */

	spin_lock_irqsave (&hmidi->lock, flags);
	if (hmidi->output) {
		if (!snd_rawmidi_transmit_empty (hmidi->output)) {
			if ((n_pending = snd_hdsp_midi_output_possible (hmidi->hdsp, hmidi->id)) > 0) {
				if (n_pending > (int)sizeof (buf))
					n_pending = sizeof (buf);

				if ((to_write = snd_rawmidi_transmit (hmidi->output, buf, n_pending)) > 0) {
					for (i = 0; i < to_write; ++i)
						snd_hdsp_midi_write_byte (hmidi->hdsp, hmidi->id, buf[i]);
				}
			}
		}
	}
	spin_unlock_irqrestore (&hmidi->lock, flags);
	return 0;
}