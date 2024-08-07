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
struct snd_kcontrol {int private_value; } ;
struct snd_ctl_elem_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  channelName ; 
 int /*<<< orphan*/  kAudioChannels ; 
 int snd_ctl_enum_info (struct snd_ctl_elem_info*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int snd_korg1212_control_route_info(struct snd_kcontrol *kcontrol,
					   struct snd_ctl_elem_info *uinfo)
{
	return snd_ctl_enum_info(uinfo,
				 (kcontrol->private_value >= 8) ? 2 : 1,
				 kAudioChannels, channelName);
}