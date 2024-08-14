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
struct snd_soc_dapm_widget {int /*<<< orphan*/  dapm; } ;
struct snd_soc_component {int dummy; } ;
struct snd_kcontrol {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  RT5668_DEPOP_1 ; 
 int /*<<< orphan*/  RT5668_HP_CTRL_2 ; 
 int /*<<< orphan*/  RT5668_HP_LOGIC_CTRL_2 ; 
 int RT5668_NG2_EN ; 
 int RT5668_NG2_EN_MASK ; 
 int /*<<< orphan*/  RT5668_STO_NG2_CTRL_1 ; 
#define  SND_SOC_DAPM_POST_PMD 129 
#define  SND_SOC_DAPM_PRE_PMU 128 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int /*<<< orphan*/ ,int) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rt5668_hp_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component =
		snd_soc_dapm_to_component(w->dapm);

	switch (event) {
	case SND_SOC_DAPM_PRE_PMU:
		snd_soc_component_write(component,
			RT5668_HP_LOGIC_CTRL_2, 0x0012);
		snd_soc_component_write(component,
			RT5668_HP_CTRL_2, 0x6000);
		snd_soc_component_update_bits(component, RT5668_STO_NG2_CTRL_1,
			RT5668_NG2_EN_MASK, RT5668_NG2_EN);
		snd_soc_component_update_bits(component,
			RT5668_DEPOP_1, 0x60, 0x60);
		break;

	case SND_SOC_DAPM_POST_PMD:
		snd_soc_component_update_bits(component,
			RT5668_DEPOP_1, 0x60, 0x0);
		snd_soc_component_write(component,
			RT5668_HP_CTRL_2, 0x0000);
		break;

	default:
		return 0;
	}

	return 0;

}