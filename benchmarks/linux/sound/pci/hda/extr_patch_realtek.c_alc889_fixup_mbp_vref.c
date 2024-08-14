#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct hda_fixup {int dummy; } ;
struct hda_codec {struct alc_spec* spec; } ;
struct TYPE_2__ {int keep_vref_in_automute; } ;
struct alc_spec {TYPE_1__ gen; } ;
typedef  int hda_nid_t ;

/* Variables and functions */
 scalar_t__ AC_JACK_HP_OUT ; 
 unsigned int AC_PINCTL_VREF_80 ; 
 int ARRAY_SIZE (int*) ; 
 int HDA_FIXUP_ACT_INIT ; 
 scalar_t__ get_defcfg_device (unsigned int) ; 
 unsigned int snd_hda_codec_get_pin_target (struct hda_codec*,int) ; 
 unsigned int snd_hda_codec_get_pincfg (struct hda_codec*,int) ; 
 int /*<<< orphan*/  snd_hda_set_pin_ctl (struct hda_codec*,int,unsigned int) ; 

__attribute__((used)) static void alc889_fixup_mbp_vref(struct hda_codec *codec,
				  const struct hda_fixup *fix, int action)
{
	struct alc_spec *spec = codec->spec;
	static hda_nid_t nids[3] = { 0x14, 0x15, 0x19 };
	int i;

	if (action != HDA_FIXUP_ACT_INIT)
		return;
	for (i = 0; i < ARRAY_SIZE(nids); i++) {
		unsigned int val = snd_hda_codec_get_pincfg(codec, nids[i]);
		if (get_defcfg_device(val) != AC_JACK_HP_OUT)
			continue;
		val = snd_hda_codec_get_pin_target(codec, nids[i]);
		val |= AC_PINCTL_VREF_80;
		snd_hda_set_pin_ctl(codec, nids[i], val);
		spec->gen.keep_vref_in_automute = 1;
		break;
	}
}