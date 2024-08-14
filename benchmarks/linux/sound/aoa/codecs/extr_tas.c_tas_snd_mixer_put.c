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
struct tas {scalar_t__* mixer_l; scalar_t__* mixer_r; int /*<<< orphan*/  mtx; scalar_t__ hw_enabled; } ;
struct snd_kcontrol {int private_value; } ;
struct TYPE_3__ {scalar_t__* value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;

/* Variables and functions */
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct tas* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  tas_set_mixer (struct tas*) ; 

__attribute__((used)) static int tas_snd_mixer_put(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	struct tas *tas = snd_kcontrol_chip(kcontrol);
	int idx = kcontrol->private_value;

	mutex_lock(&tas->mtx);
	if (tas->mixer_l[idx] == ucontrol->value.integer.value[0]
	 && tas->mixer_r[idx] == ucontrol->value.integer.value[1]) {
		mutex_unlock(&tas->mtx);
		return 0;
	}

	tas->mixer_l[idx] = ucontrol->value.integer.value[0];
	tas->mixer_r[idx] = ucontrol->value.integer.value[1];

	if (tas->hw_enabled)
		tas_set_mixer(tas);
	mutex_unlock(&tas->mtx);
	return 1;
}