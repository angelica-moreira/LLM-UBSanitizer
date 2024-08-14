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
struct rt5668_priv {struct snd_soc_component* component; } ;

/* Variables and functions */
 struct rt5668_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 

__attribute__((used)) static int rt5668_probe(struct snd_soc_component *component)
{
	struct rt5668_priv *rt5668 = snd_soc_component_get_drvdata(component);

	rt5668->component = component;

	return 0;
}