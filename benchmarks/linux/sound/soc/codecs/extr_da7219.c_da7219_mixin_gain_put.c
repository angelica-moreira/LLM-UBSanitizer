#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct snd_soc_component {int dummy; } ;
struct snd_kcontrol {int dummy; } ;
struct snd_ctl_elem_value {int dummy; } ;
struct da7219_priv {scalar_t__ alc_en; } ;

/* Variables and functions */
 int /*<<< orphan*/  da7219_alc_calib (struct snd_soc_component*) ; 
 struct da7219_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 struct snd_soc_component* snd_soc_kcontrol_component (struct snd_kcontrol*) ; 
 int snd_soc_put_volsw (struct snd_kcontrol*,struct snd_ctl_elem_value*) ; 

__attribute__((used)) static int da7219_mixin_gain_put(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);
	int ret;

	ret = snd_soc_put_volsw(kcontrol, ucontrol);

	/*
	 * If ALC in operation and value of control has been updated,
	 * make sure calibrated offsets are updated.
	 */
	if ((ret == 1) && (da7219->alc_en))
		da7219_alc_calib(component);

	return ret;
}