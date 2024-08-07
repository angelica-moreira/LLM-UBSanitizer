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
struct snd_ice1712 {int num_total_dacs; struct phase28_spec* spec; } ;
struct TYPE_3__ {unsigned int* value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct phase28_spec {unsigned int* master; int /*<<< orphan*/ * vol; } ;

/* Variables and functions */
 scalar_t__ WM_DAC_ATTEN ; 
 unsigned int WM_VOL_MAX ; 
 unsigned int WM_VOL_MUTE ; 
 int /*<<< orphan*/  snd_ice1712_restore_gpio_status (struct snd_ice1712*) ; 
 int /*<<< orphan*/  snd_ice1712_save_gpio_status (struct snd_ice1712*) ; 
 struct snd_ice1712* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  wm_set_vol (struct snd_ice1712*,scalar_t__,int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static int wm_master_vol_put(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	struct phase28_spec *spec = ice->spec;
	int ch, change = 0;

	snd_ice1712_save_gpio_status(ice);
	for (ch = 0; ch < 2; ch++) {
		unsigned int vol = ucontrol->value.integer.value[ch];
		if (vol > WM_VOL_MAX)
			continue;
		vol |= spec->master[ch] & WM_VOL_MUTE;
		if (vol != spec->master[ch]) {
			int dac;
			spec->master[ch] = vol;
			for (dac = 0; dac < ice->num_total_dacs; dac += 2)
				wm_set_vol(ice, WM_DAC_ATTEN + dac + ch,
					   spec->vol[dac + ch],
					   spec->master[ch]);
			change = 1;
		}
	}
	snd_ice1712_restore_gpio_status(ice);
	return change;
}