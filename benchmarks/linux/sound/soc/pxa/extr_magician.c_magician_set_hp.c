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
struct snd_soc_card {int /*<<< orphan*/  dapm; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_3__ {scalar_t__* value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;

/* Variables and functions */
 int /*<<< orphan*/  magician_ext_control (int /*<<< orphan*/ *) ; 
 scalar_t__ magician_hp_switch ; 
 struct snd_soc_card* snd_kcontrol_chip (struct snd_kcontrol*) ; 

__attribute__((used)) static int magician_set_hp(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);

	if (magician_hp_switch == ucontrol->value.integer.value[0])
		return 0;

	magician_hp_switch = ucontrol->value.integer.value[0];
	magician_ext_control(&card->dapm);
	return 1;
}