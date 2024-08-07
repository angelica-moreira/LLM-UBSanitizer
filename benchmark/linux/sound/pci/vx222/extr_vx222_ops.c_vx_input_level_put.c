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
struct vx_core {int /*<<< orphan*/  mixer_mutex; } ;
struct snd_vx222 {scalar_t__* input_level; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_3__ {scalar_t__* value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ MIC_LEVEL_MAX ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct vx_core* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 struct snd_vx222* to_vx222 (struct vx_core*) ; 
 int /*<<< orphan*/  vx2_set_input_level (struct snd_vx222*) ; 

__attribute__((used)) static int vx_input_level_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	struct vx_core *_chip = snd_kcontrol_chip(kcontrol);
	struct snd_vx222 *chip = to_vx222(_chip);
	if (ucontrol->value.integer.value[0] < 0 ||
	    ucontrol->value.integer.value[0] > MIC_LEVEL_MAX)
		return -EINVAL;
	if (ucontrol->value.integer.value[1] < 0 ||
	    ucontrol->value.integer.value[1] > MIC_LEVEL_MAX)
		return -EINVAL;
	mutex_lock(&_chip->mixer_mutex);
	if (chip->input_level[0] != ucontrol->value.integer.value[0] ||
	    chip->input_level[1] != ucontrol->value.integer.value[1]) {
		chip->input_level[0] = ucontrol->value.integer.value[0];
		chip->input_level[1] = ucontrol->value.integer.value[1];
		vx2_set_input_level(chip);
		mutex_unlock(&_chip->mixer_mutex);
		return 1;
	}
	mutex_unlock(&_chip->mixer_mutex);
	return 0;
}