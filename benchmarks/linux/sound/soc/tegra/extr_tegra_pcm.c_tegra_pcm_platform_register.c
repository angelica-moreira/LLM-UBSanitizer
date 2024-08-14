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
struct device {int dummy; } ;

/* Variables and functions */
 int snd_dmaengine_pcm_register (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tegra_dmaengine_pcm_config ; 

int tegra_pcm_platform_register(struct device *dev)
{
	return snd_dmaengine_pcm_register(dev, &tegra_dmaengine_pcm_config, 0);
}