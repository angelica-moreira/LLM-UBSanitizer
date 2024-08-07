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
struct snd_kcontrol {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/ * item; } ;
struct TYPE_4__ {TYPE_1__ enumerated; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct echoaudio {int professional_spdif; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  set_professional_spdif (struct echoaudio*,int) ; 
 struct echoaudio* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int snd_echo_spdif_mode_put(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_value *ucontrol)
{
	struct echoaudio *chip;
	int mode;

	chip = snd_kcontrol_chip(kcontrol);
	mode = !!ucontrol->value.enumerated.item[0];
	if (mode != chip->professional_spdif) {
		spin_lock_irq(&chip->lock);
		set_professional_spdif(chip, mode);
		spin_unlock_irq(&chip->lock);
		return 1;
	}
	return 0;
}