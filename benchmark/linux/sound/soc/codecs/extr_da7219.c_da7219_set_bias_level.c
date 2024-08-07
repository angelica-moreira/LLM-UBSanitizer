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
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
struct da7219_priv {int /*<<< orphan*/  wakeup_source; int /*<<< orphan*/  mclk; } ;
typedef  enum snd_soc_bias_level { ____Placeholder_snd_soc_bias_level } snd_soc_bias_level ;

/* Variables and functions */
 int /*<<< orphan*/  DA7219_BIAS_EN_MASK ; 
 int /*<<< orphan*/  DA7219_REFERENCES ; 
#define  SND_SOC_BIAS_OFF 131 
#define  SND_SOC_BIAS_ON 130 
#define  SND_SOC_BIAS_PREPARE 129 
#define  SND_SOC_BIAS_STANDBY 128 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int const snd_soc_component_get_bias_level (struct snd_soc_component*) ; 
 struct da7219_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int da7219_set_bias_level(struct snd_soc_component *component,
				 enum snd_soc_bias_level level)
{
	struct da7219_priv *da7219 = snd_soc_component_get_drvdata(component);
	int ret;

	switch (level) {
	case SND_SOC_BIAS_ON:
		break;
	case SND_SOC_BIAS_PREPARE:
		/* Enable MCLK for transition to ON state */
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_STANDBY) {
			if (da7219->mclk) {
				ret = clk_prepare_enable(da7219->mclk);
				if (ret) {
					dev_err(component->dev,
						"Failed to enable mclk\n");
					return ret;
				}
			}
		}

		break;
	case SND_SOC_BIAS_STANDBY:
		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_OFF)
			/* Master bias */
			snd_soc_component_update_bits(component, DA7219_REFERENCES,
					    DA7219_BIAS_EN_MASK,
					    DA7219_BIAS_EN_MASK);

		if (snd_soc_component_get_bias_level(component) == SND_SOC_BIAS_PREPARE) {
			/* Remove MCLK */
			if (da7219->mclk)
				clk_disable_unprepare(da7219->mclk);
		}
		break;
	case SND_SOC_BIAS_OFF:
		/* Only disable master bias if we're not a wake-up source */
		if (!da7219->wakeup_source)
			snd_soc_component_update_bits(component, DA7219_REFERENCES,
					    DA7219_BIAS_EN_MASK, 0);

		break;
	}

	return 0;
}