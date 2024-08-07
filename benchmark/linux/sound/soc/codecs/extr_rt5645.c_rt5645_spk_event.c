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
 int RT5645_DET_CLK_DIS ; 
 int RT5645_DET_CLK_MASK ; 
 int RT5645_DET_CLK_MODE1 ; 
 int /*<<< orphan*/  RT5645_EQ_CTRL2 ; 
 int /*<<< orphan*/  RT5645_GEN_CTRL3 ; 
 int RT5645_PWR_CLS_D ; 
 int RT5645_PWR_CLS_D_L ; 
 int RT5645_PWR_CLS_D_R ; 
 int /*<<< orphan*/  RT5645_PWR_DIG1 ; 
#define  SND_SOC_DAPM_POST_PMU 129 
#define  SND_SOC_DAPM_PRE_PMD 128 
 int /*<<< orphan*/  rt5645_enable_hweq (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct snd_soc_component* snd_soc_dapm_to_component (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rt5645_spk_event(struct snd_soc_dapm_widget *w,
	struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_component *component = snd_soc_dapm_to_component(w->dapm);

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		rt5645_enable_hweq(component);
		snd_soc_component_update_bits(component, RT5645_PWR_DIG1,
			RT5645_PWR_CLS_D | RT5645_PWR_CLS_D_R |
			RT5645_PWR_CLS_D_L,
			RT5645_PWR_CLS_D | RT5645_PWR_CLS_D_R |
			RT5645_PWR_CLS_D_L);
		snd_soc_component_update_bits(component, RT5645_GEN_CTRL3,
			RT5645_DET_CLK_MASK, RT5645_DET_CLK_MODE1);
		break;

	case SND_SOC_DAPM_PRE_PMD:
		snd_soc_component_update_bits(component, RT5645_GEN_CTRL3,
			RT5645_DET_CLK_MASK, RT5645_DET_CLK_DIS);
		snd_soc_component_write(component, RT5645_EQ_CTRL2, 0);
		snd_soc_component_update_bits(component, RT5645_PWR_DIG1,
			RT5645_PWR_CLS_D | RT5645_PWR_CLS_D_R |
			RT5645_PWR_CLS_D_L, 0);
		break;

	default:
		return 0;
	}

	return 0;
}