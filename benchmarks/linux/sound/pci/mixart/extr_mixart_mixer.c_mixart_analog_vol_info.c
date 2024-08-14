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
struct snd_kcontrol {scalar_t__ private_value; } ;
struct TYPE_4__ {int /*<<< orphan*/  max; int /*<<< orphan*/  min; } ;
struct TYPE_3__ {TYPE_2__ integer; } ;
struct snd_ctl_elem_info {int count; TYPE_1__ value; int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int /*<<< orphan*/  MIXART_ANALOG_CAPTURE_LEVEL_MAX ; 
 int /*<<< orphan*/  MIXART_ANALOG_CAPTURE_LEVEL_MIN ; 
 int /*<<< orphan*/  MIXART_ANALOG_PLAYBACK_LEVEL_MAX ; 
 int /*<<< orphan*/  MIXART_ANALOG_PLAYBACK_LEVEL_MIN ; 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_TYPE_INTEGER ; 

__attribute__((used)) static int mixart_analog_vol_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 2;
	if(kcontrol->private_value == 0) {	/* playback */
		uinfo->value.integer.min = MIXART_ANALOG_PLAYBACK_LEVEL_MIN;  /* -96 dB */
		uinfo->value.integer.max = MIXART_ANALOG_PLAYBACK_LEVEL_MAX;  /* 0 dB */
	} else {				/* capture */
		uinfo->value.integer.min = MIXART_ANALOG_CAPTURE_LEVEL_MIN;   /* -96 dB */
		uinfo->value.integer.max = MIXART_ANALOG_CAPTURE_LEVEL_MAX;   /* 31.5 dB */
	}
	return 0;
}