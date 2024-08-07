#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct snd_rawmidi_substream {TYPE_1__* rmidi; } ;
struct TYPE_4__ {int uart_cmd; } ;
struct snd_gus_card {int /*<<< orphan*/  uart_cmd_lock; TYPE_2__ gf1; } ;
struct TYPE_3__ {struct snd_gus_card* private_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  snd_gf1_uart_cmd (struct snd_gus_card*,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void snd_gf1_uart_input_trigger(struct snd_rawmidi_substream *substream, int up)
{
	struct snd_gus_card *gus;
	unsigned long flags;

	gus = substream->rmidi->private_data;

	spin_lock_irqsave(&gus->uart_cmd_lock, flags);
	if (up) {
		if ((gus->gf1.uart_cmd & 0x80) == 0)
			snd_gf1_uart_cmd(gus, gus->gf1.uart_cmd | 0x80); /* enable Rx interrupts */
	} else {
		if (gus->gf1.uart_cmd & 0x80)
			snd_gf1_uart_cmd(gus, gus->gf1.uart_cmd & ~0x80); /* disable Rx interrupts */
	}
	spin_unlock_irqrestore(&gus->uart_cmd_lock, flags);
}