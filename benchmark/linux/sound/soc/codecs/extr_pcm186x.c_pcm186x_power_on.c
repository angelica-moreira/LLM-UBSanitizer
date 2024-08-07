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
struct pcm186x_priv {int /*<<< orphan*/  supplies; int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PCM186X_POWER_CTRL ; 
 int /*<<< orphan*/  PCM186X_PWR_CTRL_PWRDN ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  regcache_cache_only (int /*<<< orphan*/ ,int) ; 
 int regcache_sync (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regulator_bulk_disable (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int regulator_bulk_enable (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct pcm186x_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int pcm186x_power_on(struct snd_soc_component *component)
{
	struct pcm186x_priv *priv = snd_soc_component_get_drvdata(component);
	int ret = 0;

	ret = regulator_bulk_enable(ARRAY_SIZE(priv->supplies),
				    priv->supplies);
	if (ret)
		return ret;

	regcache_cache_only(priv->regmap, false);
	ret = regcache_sync(priv->regmap);
	if (ret) {
		dev_err(component->dev, "Failed to restore cache\n");
		regcache_cache_only(priv->regmap, true);
		regulator_bulk_disable(ARRAY_SIZE(priv->supplies),
				       priv->supplies);
		return ret;
	}

	snd_soc_component_update_bits(component, PCM186X_POWER_CTRL,
			    PCM186X_PWR_CTRL_PWRDN, 0);

	return 0;
}