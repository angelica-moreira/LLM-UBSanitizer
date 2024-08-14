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
struct TYPE_3__ {int vendor_id; } ;
struct hda_codec {TYPE_1__ core; struct alc_spec* spec; } ;
struct TYPE_4__ {int beep_nid; int /*<<< orphan*/  no_analog; } ;
struct alc_spec {TYPE_2__ gen; } ;

/* Variables and functions */
 int /*<<< orphan*/  HDA_FIXUP_ACT_PRE_PROBE ; 
 int /*<<< orphan*/  HDA_FIXUP_ACT_PROBE ; 
 int /*<<< orphan*/  HDA_INPUT ; 
 int /*<<< orphan*/  alc882_fixup_models ; 
 int /*<<< orphan*/  alc882_fixup_tbl ; 
 int /*<<< orphan*/  alc882_fixups ; 
 int alc882_parse_auto_config (struct hda_codec*) ; 
 int alc_alloc_spec (struct hda_codec*,int) ; 
 int /*<<< orphan*/  alc_auto_parse_customize_define (struct hda_codec*) ; 
 int /*<<< orphan*/  alc_fix_pll_init (struct hda_codec*,int,int,int) ; 
 int /*<<< orphan*/  alc_free (struct hda_codec*) ; 
 int /*<<< orphan*/  alc_pre_init (struct hda_codec*) ; 
 scalar_t__ has_cdefine_beep (struct hda_codec*) ; 
 int set_beep_amp (struct alc_spec*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hda_apply_fixup (struct hda_codec*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hda_pick_fixup (struct hda_codec*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int patch_alc882(struct hda_codec *codec)
{
	struct alc_spec *spec;
	int err;

	err = alc_alloc_spec(codec, 0x0b);
	if (err < 0)
		return err;

	spec = codec->spec;

	switch (codec->core.vendor_id) {
	case 0x10ec0882:
	case 0x10ec0885:
	case 0x10ec0900:
	case 0x10ec1220:
		break;
	default:
		/* ALC883 and variants */
		alc_fix_pll_init(codec, 0x20, 0x0a, 10);
		break;
	}

	alc_pre_init(codec);

	snd_hda_pick_fixup(codec, alc882_fixup_models, alc882_fixup_tbl,
		       alc882_fixups);
	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);

	alc_auto_parse_customize_define(codec);

	if (has_cdefine_beep(codec))
		spec->gen.beep_nid = 0x01;

	/* automatic parse from the BIOS config */
	err = alc882_parse_auto_config(codec);
	if (err < 0)
		goto error;

	if (!spec->gen.no_analog && spec->gen.beep_nid) {
		err = set_beep_amp(spec, 0x0b, 0x05, HDA_INPUT);
		if (err < 0)
			goto error;
	}

	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);

	return 0;

 error:
	alc_free(codec);
	return err;
}