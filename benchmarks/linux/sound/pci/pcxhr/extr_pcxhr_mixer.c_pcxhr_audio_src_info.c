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
struct snd_pcxhr {TYPE_1__* mgr; } ;
struct snd_kcontrol {int dummy; } ;
struct snd_ctl_elem_info {int dummy; } ;
struct TYPE_2__ {scalar_t__ board_has_mic; scalar_t__ board_has_aes1; } ;

/* Variables and functions */
 int snd_ctl_enum_info (struct snd_ctl_elem_info*,int,int,char const**) ; 
 struct snd_pcxhr* snd_kcontrol_chip (struct snd_kcontrol*) ; 

__attribute__((used)) static int pcxhr_audio_src_info(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_info *uinfo)
{
	static const char *texts[5] = {
		"Line", "Digital", "Digi+SRC", "Mic", "Line+Mic"
	};
	int i;
	struct snd_pcxhr *chip = snd_kcontrol_chip(kcontrol);

	i = 2;			/* no SRC, no Mic available */
	if (chip->mgr->board_has_aes1) {
		i = 3;		/* SRC available */
		if (chip->mgr->board_has_mic)
			i = 5;	/* Mic and MicroMix available */
	}
	return snd_ctl_enum_info(uinfo, 1, i, texts);
}