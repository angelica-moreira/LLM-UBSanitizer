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
struct snd_kcontrol {int dummy; } ;
struct snd_ctl_elem_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENUMERATED_CTL_INFO (struct snd_ctl_elem_info*,char const* const*) ; 

__attribute__((used)) static int snd_hdspm_info_tco_video_input_format(struct snd_kcontrol *kcontrol,
				       struct snd_ctl_elem_info *uinfo)
{
	static const char *const texts[] = {"No video", "NTSC", "PAL"};
	ENUMERATED_CTL_INFO(uinfo, texts);
	return 0;
}