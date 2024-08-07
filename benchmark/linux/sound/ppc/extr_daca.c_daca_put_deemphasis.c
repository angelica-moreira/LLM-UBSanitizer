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
struct snd_pmac {struct pmac_daca* mixer_data; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_3__ {scalar_t__* value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct pmac_daca {scalar_t__ deemphasis; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  daca_set_volume (struct pmac_daca*) ; 
 struct snd_pmac* snd_kcontrol_chip (struct snd_kcontrol*) ; 

__attribute__((used)) static int daca_put_deemphasis(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value *ucontrol)
{
	struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
	struct pmac_daca *mix;
	int change;

	if (! (mix = chip->mixer_data))
		return -ENODEV;
	change = mix->deemphasis != ucontrol->value.integer.value[0];
	if (change) {
		mix->deemphasis = !!ucontrol->value.integer.value[0];
		daca_set_volume(mix);
	}
	return change;
}