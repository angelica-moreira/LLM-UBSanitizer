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
struct TYPE_2__ {int mixer_nid; } ;
struct via_spec {TYPE_1__ gen; } ;
struct hda_codec {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 scalar_t__ VT1708BCE ; 
 scalar_t__ get_codec_type (struct hda_codec*) ; 
 int patch_vt1708S (struct hda_codec*) ; 
 int /*<<< orphan*/  via_free (struct hda_codec*) ; 
 struct via_spec* via_new_spec (struct hda_codec*) ; 
 int via_parse_auto_config (struct hda_codec*) ; 

__attribute__((used)) static int patch_vt1708B(struct hda_codec *codec)
{
	struct via_spec *spec;
	int err;

	if (get_codec_type(codec) == VT1708BCE)
		return patch_vt1708S(codec);

	/* create a codec specific record */
	spec = via_new_spec(codec);
	if (spec == NULL)
		return -ENOMEM;

	spec->gen.mixer_nid = 0x16;

	/* automatic parse from the BIOS config */
	err = via_parse_auto_config(codec);
	if (err < 0)
		goto error;

	return 0;

 error:
	via_free(codec);
	return err;
}