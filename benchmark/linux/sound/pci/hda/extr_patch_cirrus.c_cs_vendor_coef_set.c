#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct hda_codec {struct cs_spec* spec; } ;
struct cs_spec {int /*<<< orphan*/  vendor_nid; } ;

/* Variables and functions */
 int /*<<< orphan*/  AC_VERB_SET_COEF_INDEX ; 
 int /*<<< orphan*/  AC_VERB_SET_PROC_COEF ; 
 int /*<<< orphan*/  snd_hda_codec_write (struct hda_codec*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static inline void cs_vendor_coef_set(struct hda_codec *codec, unsigned int idx,
				      unsigned int coef)
{
	struct cs_spec *spec = codec->spec;
	snd_hda_codec_write(codec, spec->vendor_nid, 0,
			    AC_VERB_SET_COEF_INDEX, idx);
	snd_hda_codec_write(codec, spec->vendor_nid, 0,
			    AC_VERB_SET_PROC_COEF, coef);
}