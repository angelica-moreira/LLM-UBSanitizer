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
struct snd_ice1712 {int dummy; } ;
struct TYPE_3__ {scalar_t__* value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;

/* Variables and functions */
 int /*<<< orphan*/  WM_MUTE ; 
 int /*<<< orphan*/  snd_ice1712_restore_gpio_status (struct snd_ice1712*) ; 
 int /*<<< orphan*/  snd_ice1712_save_gpio_status (struct snd_ice1712*) ; 
 struct snd_ice1712* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 unsigned short wm_get (struct snd_ice1712*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wm_put (struct snd_ice1712*,int /*<<< orphan*/ ,unsigned short) ; 

__attribute__((used)) static int wm_pcm_mute_put(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	unsigned short nval, oval;
	int change;

	snd_ice1712_save_gpio_status(ice);
	oval = wm_get(ice, WM_MUTE);
	nval = (oval & ~0x10) | (ucontrol->value.integer.value[0] ? 0 : 0x10);
	change = (nval != oval);
	if (change)
		wm_put(ice, WM_MUTE, nval);
	snd_ice1712_restore_gpio_status(ice);

	return change;
}