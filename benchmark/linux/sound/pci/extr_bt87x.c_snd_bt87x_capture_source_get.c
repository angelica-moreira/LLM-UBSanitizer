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
struct TYPE_3__ {int* item; } ;
struct TYPE_4__ {TYPE_1__ enumerated; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct snd_bt87x {int reg_control; } ;

/* Variables and functions */
 int CTL_A_SEL_MASK ; 
 int CTL_A_SEL_SHIFT ; 
 struct snd_bt87x* snd_kcontrol_chip (struct snd_kcontrol*) ; 

__attribute__((used)) static int snd_bt87x_capture_source_get(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_value *value)
{
	struct snd_bt87x *chip = snd_kcontrol_chip(kcontrol);

	value->value.enumerated.item[0] = (chip->reg_control & CTL_A_SEL_MASK) >> CTL_A_SEL_SHIFT;
	return 0;
}