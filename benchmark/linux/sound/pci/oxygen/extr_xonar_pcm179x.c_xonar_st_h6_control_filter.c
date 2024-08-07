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
struct snd_kcontrol_new {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  strncmp (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static int xonar_st_h6_control_filter(struct snd_kcontrol_new *template)
{
	if (!strncmp(template->name, "Master Playback ", 16))
		/* no volume/mute, as I²C to the third DAC does not work */
		return 1;
	return 0;
}