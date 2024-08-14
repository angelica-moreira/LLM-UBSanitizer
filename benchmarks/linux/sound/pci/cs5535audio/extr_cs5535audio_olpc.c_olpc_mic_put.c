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
struct cs5535audio {int /*<<< orphan*/  ac97; } ;

/* Variables and functions */
 int /*<<< orphan*/  olpc_mic_bias (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct cs5535audio* snd_kcontrol_chip (struct snd_kcontrol*) ; 

__attribute__((used)) static int olpc_mic_put(struct snd_kcontrol *kctl, struct snd_ctl_elem_value *v)
{
	struct cs5535audio *cs5535au = snd_kcontrol_chip(kctl);

	olpc_mic_bias(cs5535au->ac97, v->value.integer.value[0]);
	return 1;
}