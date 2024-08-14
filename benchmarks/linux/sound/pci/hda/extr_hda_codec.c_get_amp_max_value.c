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
typedef  unsigned int u32 ;
struct hda_codec {int dummy; } ;
typedef  int /*<<< orphan*/  hda_nid_t ;

/* Variables and functions */
 unsigned int AC_AMPCAP_NUM_STEPS ; 
 unsigned int AC_AMPCAP_NUM_STEPS_SHIFT ; 
 unsigned int query_amp_caps (struct hda_codec*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static u32 get_amp_max_value(struct hda_codec *codec, hda_nid_t nid, int dir,
			     unsigned int ofs)
{
	u32 caps = query_amp_caps(codec, nid, dir);
	/* get num steps */
	caps = (caps & AC_AMPCAP_NUM_STEPS) >> AC_AMPCAP_NUM_STEPS_SHIFT;
	if (ofs < caps)
		caps -= ofs;
	return caps;
}