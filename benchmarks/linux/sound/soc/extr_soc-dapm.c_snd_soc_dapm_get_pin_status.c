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
struct snd_soc_dapm_widget {int connected; } ;
struct snd_soc_dapm_context {int dummy; } ;

/* Variables and functions */
 struct snd_soc_dapm_widget* dapm_find_widget (struct snd_soc_dapm_context*,char const*,int) ; 

int snd_soc_dapm_get_pin_status(struct snd_soc_dapm_context *dapm,
				const char *pin)
{
	struct snd_soc_dapm_widget *w = dapm_find_widget(dapm, pin, true);

	if (w)
		return w->connected;

	return 0;
}