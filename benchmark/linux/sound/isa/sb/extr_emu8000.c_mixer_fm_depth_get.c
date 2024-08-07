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
struct snd_kcontrol {scalar_t__ private_value; } ;
struct snd_emu8000 {int /*<<< orphan*/  fm_reverb_depth; int /*<<< orphan*/  fm_chorus_depth; } ;
struct TYPE_3__ {int /*<<< orphan*/ * value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;

/* Variables and functions */
 struct snd_emu8000* snd_kcontrol_chip (struct snd_kcontrol*) ; 

__attribute__((used)) static int mixer_fm_depth_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	struct snd_emu8000 *emu = snd_kcontrol_chip(kcontrol);
	
	ucontrol->value.integer.value[0] = kcontrol->private_value ? emu->fm_chorus_depth : emu->fm_reverb_depth;
	return 0;
}