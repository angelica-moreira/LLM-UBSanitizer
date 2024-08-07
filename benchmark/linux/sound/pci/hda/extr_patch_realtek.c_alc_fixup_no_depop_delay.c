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
struct hda_fixup {int dummy; } ;
struct hda_codec {scalar_t__ depop_delay; struct alc_spec* spec; } ;
struct alc_spec {int no_depop_delay; } ;

/* Variables and functions */
 int HDA_FIXUP_ACT_PROBE ; 

__attribute__((used)) static void alc_fixup_no_depop_delay(struct hda_codec *codec,
				    const struct hda_fixup *fix, int action)
{
	struct alc_spec *spec = codec->spec;

	if (action == HDA_FIXUP_ACT_PROBE) {
		spec->no_depop_delay = 1;
		codec->depop_delay = 0;
	}
}