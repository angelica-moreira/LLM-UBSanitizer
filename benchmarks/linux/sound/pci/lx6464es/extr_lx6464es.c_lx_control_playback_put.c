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
struct TYPE_3__ {int* value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct lx6464es {int playback_mute; } ;

/* Variables and functions */
 int /*<<< orphan*/  lx_level_unmute (struct lx6464es*,int /*<<< orphan*/ ,int) ; 
 struct lx6464es* snd_kcontrol_chip (struct snd_kcontrol*) ; 

__attribute__((used)) static int lx_control_playback_put(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_value *ucontrol)
{
	struct lx6464es *chip = snd_kcontrol_chip(kcontrol);
	int changed = 0;
	int current_value = chip->playback_mute;

	if (current_value != ucontrol->value.integer.value[0]) {
		lx_level_unmute(chip, 0, !current_value);
		chip->playback_mute = !current_value;
		changed = 1;
	}
	return changed;
}