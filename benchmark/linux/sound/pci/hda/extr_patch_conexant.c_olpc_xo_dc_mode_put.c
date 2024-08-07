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
struct hda_codec {struct conexant_spec* spec; } ;
struct conexant_spec {int dc_enable; } ;

/* Variables and functions */
 int /*<<< orphan*/  olpc_xo_update_mic_boost (struct hda_codec*) ; 
 int /*<<< orphan*/  olpc_xo_update_mic_pins (struct hda_codec*) ; 
 struct hda_codec* snd_kcontrol_chip (struct snd_kcontrol*) ; 

__attribute__((used)) static int olpc_xo_dc_mode_put(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value *ucontrol)
{
	struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
	struct conexant_spec *spec = codec->spec;
	int dc_enable = !!ucontrol->value.integer.value[0];

	if (dc_enable == spec->dc_enable)
		return 0;

	spec->dc_enable = dc_enable;
	olpc_xo_update_mic_pins(codec);
	olpc_xo_update_mic_boost(codec);
	return 1;
}