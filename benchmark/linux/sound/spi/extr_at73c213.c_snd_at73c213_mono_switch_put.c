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
struct snd_kcontrol {int private_value; } ;
struct TYPE_3__ {scalar_t__* value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct snd_at73c213 {int* reg_image; int /*<<< orphan*/  mixer_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int snd_at73c213_write_reg (struct snd_at73c213*,int,unsigned short) ; 
 struct snd_at73c213* snd_kcontrol_chip (struct snd_kcontrol*) ; 

__attribute__((used)) static int snd_at73c213_mono_switch_put(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *ucontrol)
{
	struct snd_at73c213 *chip = snd_kcontrol_chip(kcontrol);
	int reg = kcontrol->private_value & 0xff;
	int shift = (kcontrol->private_value >> 8) & 0xff;
	int mask = (kcontrol->private_value >> 16) & 0xff;
	int invert = (kcontrol->private_value >> 24) & 0xff;
	int change, retval;
	unsigned short val;

	if (ucontrol->value.integer.value[0])
		val = mask;
	else
		val = 0;

	if (invert)
		val = mask - val;
	val <<= shift;

	mutex_lock(&chip->mixer_lock);

	val |= (chip->reg_image[reg] & ~(mask << shift));
	change = val != chip->reg_image[reg];

	retval = snd_at73c213_write_reg(chip, reg, val);

	mutex_unlock(&chip->mixer_lock);

	if (retval)
		return retval;

	return change;
}