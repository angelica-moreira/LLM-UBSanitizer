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
struct TYPE_3__ {unsigned int* item; } ;
struct TYPE_4__ {TYPE_1__ enumerated; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct snd_ca0106 {unsigned int capture_source; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  ca0106_set_capture_source (struct snd_ca0106*) ; 
 struct snd_ca0106* snd_kcontrol_chip (struct snd_kcontrol*) ; 

__attribute__((used)) static int snd_ca0106_capture_source_put(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ca0106 *emu = snd_kcontrol_chip(kcontrol);
	unsigned int val;
	int change = 0;

	val = ucontrol->value.enumerated.item[0] ;
	if (val >= 6)
		return -EINVAL;
	change = (emu->capture_source != val);
	if (change) {
		emu->capture_source = val;
		ca0106_set_capture_source(emu);
	}
        return change;
}