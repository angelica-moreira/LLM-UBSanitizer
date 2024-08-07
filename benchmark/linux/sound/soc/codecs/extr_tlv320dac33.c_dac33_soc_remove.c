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
struct tlv320dac33_priv {scalar_t__ irq; int /*<<< orphan*/  work; int /*<<< orphan*/  component; } ;
struct snd_soc_component {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  flush_work (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free_irq (scalar_t__,int /*<<< orphan*/ ) ; 
 struct tlv320dac33_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 

__attribute__((used)) static void dac33_soc_remove(struct snd_soc_component *component)
{
	struct tlv320dac33_priv *dac33 = snd_soc_component_get_drvdata(component);

	if (dac33->irq >= 0) {
		free_irq(dac33->irq, dac33->component);
		flush_work(&dac33->work);
	}
}