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
struct TYPE_3__ {int /*<<< orphan*/ * status; } ;
struct TYPE_4__ {TYPE_1__ iec958; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct ak4114 {int dummy; } ;

/* Variables and functions */
 scalar_t__ AK4114_REG_TXCSB0 ; 
 unsigned int AK4114_REG_TXCSB_SIZE ; 
 int /*<<< orphan*/  reg_write (struct ak4114*,scalar_t__,int /*<<< orphan*/ ) ; 
 struct ak4114* snd_kcontrol_chip (struct snd_kcontrol*) ; 

__attribute__((used)) static int snd_ak4114_spdif_playback_put(struct snd_kcontrol *kcontrol,
					 struct snd_ctl_elem_value *ucontrol)
{
	struct ak4114 *chip = snd_kcontrol_chip(kcontrol);
	unsigned i;

	for (i = 0; i < AK4114_REG_TXCSB_SIZE; i++)
		reg_write(chip, AK4114_REG_TXCSB0 + i, ucontrol->value.iec958.status[i]);
	return 0;
}