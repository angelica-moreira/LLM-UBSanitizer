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
struct sfire_chip {scalar_t__ card; scalar_t__ control; scalar_t__ comm; scalar_t__ midi; scalar_t__ pcm; } ;

/* Variables and functions */
 int /*<<< orphan*/  snd_card_free (scalar_t__) ; 
 int /*<<< orphan*/  usb6fire_comm_destroy (struct sfire_chip*) ; 
 int /*<<< orphan*/  usb6fire_control_destroy (struct sfire_chip*) ; 
 int /*<<< orphan*/  usb6fire_midi_destroy (struct sfire_chip*) ; 
 int /*<<< orphan*/  usb6fire_pcm_destroy (struct sfire_chip*) ; 

__attribute__((used)) static void usb6fire_chip_destroy(struct sfire_chip *chip)
{
	if (chip) {
		if (chip->pcm)
			usb6fire_pcm_destroy(chip);
		if (chip->midi)
			usb6fire_midi_destroy(chip);
		if (chip->comm)
			usb6fire_comm_destroy(chip);
		if (chip->control)
			usb6fire_control_destroy(chip);
		if (chip->card)
			snd_card_free(chip->card);
	}
}