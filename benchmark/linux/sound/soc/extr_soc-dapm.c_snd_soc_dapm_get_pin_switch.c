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
struct snd_soc_card {int /*<<< orphan*/  dapm_mutex; int /*<<< orphan*/  dapm; } ;
struct snd_kcontrol {scalar_t__ private_value; } ;
struct TYPE_3__ {int /*<<< orphan*/ * value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;

/* Variables and functions */
 int /*<<< orphan*/  SND_SOC_DAPM_CLASS_RUNTIME ; 
 int /*<<< orphan*/  mutex_lock_nested (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct snd_soc_card* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  snd_soc_dapm_get_pin_status (int /*<<< orphan*/ *,char const*) ; 

int snd_soc_dapm_get_pin_switch(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
	const char *pin = (const char *)kcontrol->private_value;

	mutex_lock_nested(&card->dapm_mutex, SND_SOC_DAPM_CLASS_RUNTIME);

	ucontrol->value.integer.value[0] =
		snd_soc_dapm_get_pin_status(&card->dapm, pin);

	mutex_unlock(&card->dapm_mutex);

	return 0;
}