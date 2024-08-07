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
struct snd_soc_dai {size_t id; struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct rt5645_priv {int codec_type; int* master; } ;

/* Variables and functions */
#define  CODEC_TYPE_RT5650 138 
 int EINVAL ; 
#define  RT5645_AIF1 137 
#define  RT5645_AIF2 136 
 int /*<<< orphan*/  RT5645_I2S1_SDP ; 
 int /*<<< orphan*/  RT5645_I2S2_SDP ; 
 unsigned int RT5645_I2S_DF_LEFT ; 
 int RT5645_I2S_DF_MASK ; 
 unsigned int RT5645_I2S_DF_PCM_A ; 
 unsigned int RT5645_I2S_DF_PCM_B ; 
 int RT5645_I2S_MS_MASK ; 
 unsigned int RT5645_I2S_MS_S ; 
#define  SND_SOC_DAIFMT_CBM_CFM 135 
#define  SND_SOC_DAIFMT_CBS_CFS 134 
#define  SND_SOC_DAIFMT_DSP_A 133 
#define  SND_SOC_DAIFMT_DSP_B 132 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 131 
#define  SND_SOC_DAIFMT_IB_NF 130 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 129 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_NF 128 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 struct rt5645_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,unsigned int) ; 

__attribute__((used)) static int rt5645_set_dai_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
	struct snd_soc_component *component = dai->component;
	struct rt5645_priv *rt5645 = snd_soc_component_get_drvdata(component);
	unsigned int reg_val = 0, pol_sft;

	switch (rt5645->codec_type) {
	case CODEC_TYPE_RT5650:
		pol_sft = 8;
		break;
	default:
		pol_sft = 7;
		break;
	}

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		rt5645->master[dai->id] = 1;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		reg_val |= RT5645_I2S_MS_S;
		rt5645->master[dai->id] = 0;
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
		break;
	case SND_SOC_DAIFMT_IB_NF:
		reg_val |= (1 << pol_sft);
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		reg_val |= RT5645_I2S_DF_LEFT;
		break;
	case SND_SOC_DAIFMT_DSP_A:
		reg_val |= RT5645_I2S_DF_PCM_A;
		break;
	case SND_SOC_DAIFMT_DSP_B:
		reg_val |= RT5645_I2S_DF_PCM_B;
		break;
	default:
		return -EINVAL;
	}
	switch (dai->id) {
	case RT5645_AIF1:
		snd_soc_component_update_bits(component, RT5645_I2S1_SDP,
			RT5645_I2S_MS_MASK | (1 << pol_sft) |
			RT5645_I2S_DF_MASK, reg_val);
		break;
	case RT5645_AIF2:
		snd_soc_component_update_bits(component, RT5645_I2S2_SDP,
			RT5645_I2S_MS_MASK | (1 << pol_sft) |
			RT5645_I2S_DF_MASK, reg_val);
		break;
	default:
		dev_err(component->dev, "Invalid dai->id: %d\n", dai->id);
		return -EINVAL;
	}
	return 0;
}