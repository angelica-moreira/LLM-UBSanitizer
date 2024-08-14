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
struct TYPE_3__ {int /*<<< orphan*/ * value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;

/* Variables and functions */
 int /*<<< orphan*/  S3C2410_GPJ (int) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  gta02_speaker_enabled ; 

__attribute__((used)) static int lm4853_set_spk(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	gta02_speaker_enabled = ucontrol->value.integer.value[0];

	gpio_set_value(S3C2410_GPJ(2), !gta02_speaker_enabled);

	return 0;
}