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
struct snd_soc_dai {struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct ak4104_private {int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int AK4104_CONTROL1_DIF0 ; 
 int AK4104_CONTROL1_DIF1 ; 
 int /*<<< orphan*/  AK4104_REG_CONTROL1 ; 
 int EINVAL ; 
 unsigned int SND_SOC_DAIFMT_CBS_CFS ; 
 unsigned int SND_SOC_DAIFMT_FORMAT_MASK ; 
#define  SND_SOC_DAIFMT_I2S 130 
#define  SND_SOC_DAIFMT_LEFT_J 129 
 unsigned int SND_SOC_DAIFMT_MASTER_MASK ; 
#define  SND_SOC_DAIFMT_RIGHT_J 128 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 struct ak4104_private* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 

__attribute__((used)) static int ak4104_set_dai_fmt(struct snd_soc_dai *codec_dai,
			      unsigned int format)
{
	struct snd_soc_component *component = codec_dai->component;
	struct ak4104_private *ak4104 = snd_soc_component_get_drvdata(component);
	int val = 0;
	int ret;

	/* set DAI format */
	switch (format & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_RIGHT_J:
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		val |= AK4104_CONTROL1_DIF0;
		break;
	case SND_SOC_DAIFMT_I2S:
		val |= AK4104_CONTROL1_DIF0 | AK4104_CONTROL1_DIF1;
		break;
	default:
		dev_err(component->dev, "invalid dai format\n");
		return -EINVAL;
	}

	/* This device can only be slave */
	if ((format & SND_SOC_DAIFMT_MASTER_MASK) != SND_SOC_DAIFMT_CBS_CFS)
		return -EINVAL;

	ret = regmap_update_bits(ak4104->regmap, AK4104_REG_CONTROL1,
				 AK4104_CONTROL1_DIF0 | AK4104_CONTROL1_DIF1,
				 val);
	if (ret < 0)
		return ret;

	return 0;
}