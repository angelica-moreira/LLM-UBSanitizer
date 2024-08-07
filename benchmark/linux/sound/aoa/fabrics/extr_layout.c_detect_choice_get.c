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
struct TYPE_3__ {int /*<<< orphan*/ * value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct layout_dev {int /*<<< orphan*/  switch_on_lineout; int /*<<< orphan*/  switch_on_headphone; } ;

/* Variables and functions */
 int ENODEV ; 
 struct layout_dev* snd_kcontrol_chip (struct snd_kcontrol*) ; 

__attribute__((used)) static int detect_choice_get(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_value *ucontrol)
{
	struct layout_dev *ldev = snd_kcontrol_chip(kcontrol);

	switch (kcontrol->private_value) {
	case 0:
		ucontrol->value.integer.value[0] = ldev->switch_on_headphone;
		break;
	case 1:
		ucontrol->value.integer.value[0] = ldev->switch_on_lineout;
		break;
	default:
		return -ENODEV;
	}
	return 0;
}