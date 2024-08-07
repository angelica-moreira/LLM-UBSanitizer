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
struct TYPE_2__ {int indep_hp; int keep_eapd_on; int power_down_unused; int /*<<< orphan*/  add_stereo_mix_input; int /*<<< orphan*/  pcm_playback_hook; } ;
struct via_spec {scalar_t__ codec_type; TYPE_1__ gen; } ;
struct hda_codec {int power_save_node; int /*<<< orphan*/  patch_ops; struct via_spec* spec; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HDA_HINT_STEREO_MIX_AUTO ; 
 scalar_t__ VT1708BCE ; 
 scalar_t__ VT1708S ; 
 scalar_t__ get_codec_type (struct hda_codec*) ; 
 struct via_spec* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hda_gen_spec_init (TYPE_1__*) ; 
 int /*<<< orphan*/  via_patch_ops ; 
 int /*<<< orphan*/  via_playback_pcm_hook ; 

__attribute__((used)) static struct via_spec *via_new_spec(struct hda_codec *codec)
{
	struct via_spec *spec;

	spec = kzalloc(sizeof(*spec), GFP_KERNEL);
	if (spec == NULL)
		return NULL;

	codec->spec = spec;
	snd_hda_gen_spec_init(&spec->gen);
	spec->codec_type = get_codec_type(codec);
	/* VT1708BCE & VT1708S are almost same */
	if (spec->codec_type == VT1708BCE)
		spec->codec_type = VT1708S;
	spec->gen.indep_hp = 1;
	spec->gen.keep_eapd_on = 1;
	spec->gen.pcm_playback_hook = via_playback_pcm_hook;
	spec->gen.add_stereo_mix_input = HDA_HINT_STEREO_MIX_AUTO;
	codec->power_save_node = 1;
	spec->gen.power_down_unused = 1;
	codec->patch_ops = via_patch_ops;
	return spec;
}