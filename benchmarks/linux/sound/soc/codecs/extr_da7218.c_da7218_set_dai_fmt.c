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
typedef  int u8 ;
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int dummy; } ;
struct da7218_priv {int master; } ;

/* Variables and functions */
 int DA7218_DAI_BCLKS_PER_WCLK_64 ; 
 int /*<<< orphan*/  DA7218_DAI_CLK_MODE ; 
 int DA7218_DAI_CLK_POL_INV ; 
 int /*<<< orphan*/  DA7218_DAI_CTRL ; 
 int DA7218_DAI_FORMAT_DSP ; 
 int DA7218_DAI_FORMAT_I2S ; 
 int DA7218_DAI_FORMAT_LEFT_J ; 
 int /*<<< orphan*/  DA7218_DAI_FORMAT_MASK ; 
 int DA7218_DAI_FORMAT_RIGHT_J ; 
 int DA7218_DAI_WCLK_POL_INV ; 
 int EINVAL ; 
#define  SND_SOC_DAIFMT_CBM_CFM 137 
#define  SND_SOC_DAIFMT_CBS_CFS 136 
#define  SND_SOC_DAIFMT_DSP_B 135 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 134 
#define  SND_SOC_DAIFMT_IB_IF 133 
#define  SND_SOC_DAIFMT_IB_NF 132 
 unsigned int SND_SOC_DAIFMT_INV_MASK ; 
#define  SND_SOC_DAIFMT_LEFT_J 131 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_NB_IF 130 
#define  SND_SOC_DAIFMT_NB_NF 129 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 struct da7218_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  snd_soc_component_write (struct snd_soc_component*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int da7218_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
	struct snd_soc_component *component = codec_dai->component;
	struct da7218_priv *da7218 = snd_soc_component_get_drvdata(component);
	u8 dai_clk_mode = 0, dai_ctrl = 0;

	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		da7218->master = true;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		da7218->master = false;
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
	case SND_SOC_DAIFMT_LEFT_J:
	case SND_SOC_DAIFMT_RIGHT_J:
		switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
		case SND_SOC_DAIFMT_NB_NF:
			break;
		case SND_SOC_DAIFMT_NB_IF:
			dai_clk_mode |= DA7218_DAI_WCLK_POL_INV;
			break;
		case SND_SOC_DAIFMT_IB_NF:
			dai_clk_mode |= DA7218_DAI_CLK_POL_INV;
			break;
		case SND_SOC_DAIFMT_IB_IF:
			dai_clk_mode |= DA7218_DAI_WCLK_POL_INV |
					DA7218_DAI_CLK_POL_INV;
			break;
		default:
			return -EINVAL;
		}
		break;
	case SND_SOC_DAIFMT_DSP_B:
		switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
		case SND_SOC_DAIFMT_NB_NF:
			dai_clk_mode |= DA7218_DAI_CLK_POL_INV;
			break;
		case SND_SOC_DAIFMT_NB_IF:
			dai_clk_mode |= DA7218_DAI_WCLK_POL_INV |
					DA7218_DAI_CLK_POL_INV;
			break;
		case SND_SOC_DAIFMT_IB_NF:
			break;
		case SND_SOC_DAIFMT_IB_IF:
			dai_clk_mode |= DA7218_DAI_WCLK_POL_INV;
			break;
		default:
			return -EINVAL;
		}
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		dai_ctrl |= DA7218_DAI_FORMAT_I2S;
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		dai_ctrl |= DA7218_DAI_FORMAT_LEFT_J;
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		dai_ctrl |= DA7218_DAI_FORMAT_RIGHT_J;
		break;
	case SND_SOC_DAIFMT_DSP_B:
		dai_ctrl |= DA7218_DAI_FORMAT_DSP;
		break;
	default:
		return -EINVAL;
	}

	/* By default 64 BCLKs per WCLK is supported */
	dai_clk_mode |= DA7218_DAI_BCLKS_PER_WCLK_64;

	snd_soc_component_write(component, DA7218_DAI_CLK_MODE, dai_clk_mode);
	snd_soc_component_update_bits(component, DA7218_DAI_CTRL, DA7218_DAI_FORMAT_MASK,
			    dai_ctrl);

	return 0;
}