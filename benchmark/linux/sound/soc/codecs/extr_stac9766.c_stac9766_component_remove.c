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
struct snd_soc_component {int dummy; } ;
struct snd_ac97 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  snd_soc_component_exit_regmap (struct snd_soc_component*) ; 
 struct snd_ac97* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 int /*<<< orphan*/  snd_soc_free_ac97_component (struct snd_ac97*) ; 

__attribute__((used)) static void stac9766_component_remove(struct snd_soc_component *component)
{
	struct snd_ac97 *ac97 = snd_soc_component_get_drvdata(component);

	snd_soc_component_exit_regmap(component);
	snd_soc_free_ac97_component(ac97);
}