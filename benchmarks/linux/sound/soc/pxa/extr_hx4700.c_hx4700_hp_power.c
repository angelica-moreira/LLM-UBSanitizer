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
struct snd_soc_dapm_widget {int dummy; } ;
struct snd_kcontrol {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GPIO92_HX4700_HP_DRIVER ; 
 int /*<<< orphan*/  SND_SOC_DAPM_EVENT_ON (int) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int hx4700_hp_power(struct snd_soc_dapm_widget *w,
			   struct snd_kcontrol *k, int event)
{
	gpio_set_value(GPIO92_HX4700_HP_DRIVER, !!SND_SOC_DAPM_EVENT_ON(event));
	return 0;
}