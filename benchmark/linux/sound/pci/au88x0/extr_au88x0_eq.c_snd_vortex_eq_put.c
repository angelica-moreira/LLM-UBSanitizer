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
typedef  int /*<<< orphan*/  vortex_t ;
typedef  scalar_t__ u16 ;
struct snd_kcontrol {int private_value; } ;
struct TYPE_3__ {scalar_t__* value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;

/* Variables and functions */
 int /*<<< orphan*/ * snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  vortex_Eqlzr_GetLeftGain (int /*<<< orphan*/ *,int,scalar_t__*) ; 
 int /*<<< orphan*/  vortex_Eqlzr_GetRightGain (int /*<<< orphan*/ *,int,scalar_t__*) ; 
 int /*<<< orphan*/  vortex_Eqlzr_SetLeftGain (int /*<<< orphan*/ *,int,scalar_t__) ; 
 int /*<<< orphan*/  vortex_Eqlzr_SetRightGain (int /*<<< orphan*/ *,int,scalar_t__) ; 

__attribute__((used)) static int
snd_vortex_eq_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	vortex_t *vortex = snd_kcontrol_chip(kcontrol);
	int changed = 0, i = kcontrol->private_value;
	u16 gainL = 0, gainR = 0;

	vortex_Eqlzr_GetLeftGain(vortex, i, &gainL);
	vortex_Eqlzr_GetRightGain(vortex, i, &gainR);

	if (gainL != ucontrol->value.integer.value[0]) {
		vortex_Eqlzr_SetLeftGain(vortex, i,
					 ucontrol->value.integer.value[0]);
		changed = 1;
	}
	if (gainR != ucontrol->value.integer.value[1]) {
		vortex_Eqlzr_SetRightGain(vortex, i,
					  ucontrol->value.integer.value[1]);
		changed = 1;
	}
	return changed;
}