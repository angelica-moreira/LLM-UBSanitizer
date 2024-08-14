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
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_2__ {int /*<<< orphan*/  afg; } ;
struct hda_codec {TYPE_1__ core; } ;
typedef  int /*<<< orphan*/  hda_nid_t ;

/* Variables and functions */
 int /*<<< orphan*/  AC_PAR_AMP_IN_CAP ; 
 int /*<<< orphan*/  AC_PAR_AMP_OUT_CAP ; 
 int AC_WCAP_AMP_OVRD ; 
 int HDA_OUTPUT ; 
 int get_wcaps (struct hda_codec*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hda_param_read (struct hda_codec*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

u32 query_amp_caps(struct hda_codec *codec, hda_nid_t nid, int direction)
{
	if (!(get_wcaps(codec, nid) & AC_WCAP_AMP_OVRD))
		nid = codec->core.afg;
	return snd_hda_param_read(codec, nid,
				  direction == HDA_OUTPUT ?
				  AC_PAR_AMP_OUT_CAP : AC_PAR_AMP_IN_CAP);
}