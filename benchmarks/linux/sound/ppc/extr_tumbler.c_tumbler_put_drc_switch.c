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
struct snd_pmac {scalar_t__ model; struct pmac_tumbler* mixer_data; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_3__ {int* value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct pmac_tumbler {int drc_enable; } ;

/* Variables and functions */
 int ENODEV ; 
 scalar_t__ PMAC_TUMBLER ; 
 int /*<<< orphan*/  snapper_set_drc (struct pmac_tumbler*) ; 
 struct snd_pmac* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  tumbler_set_drc (struct pmac_tumbler*) ; 

__attribute__((used)) static int tumbler_put_drc_switch(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value *ucontrol)
{
	struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
	struct pmac_tumbler *mix;
	int change;

	if (! (mix = chip->mixer_data))
		return -ENODEV;
	change = mix->drc_enable != ucontrol->value.integer.value[0];
	if (change) {
		mix->drc_enable = !!ucontrol->value.integer.value[0];
		if (chip->model == PMAC_TUMBLER)
			tumbler_set_drc(mix);
		else
			snapper_set_drc(mix);
	}
	return change;
}