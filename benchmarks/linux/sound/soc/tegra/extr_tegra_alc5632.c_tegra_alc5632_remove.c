#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct tegra_alc5632 {int /*<<< orphan*/  util_data; } ;
struct snd_soc_card {int dummy; } ;
struct platform_device {int dummy; } ;
struct TYPE_8__ {TYPE_1__* codecs; TYPE_3__* platforms; TYPE_2__* cpus; } ;
struct TYPE_7__ {int /*<<< orphan*/ * of_node; } ;
struct TYPE_6__ {int /*<<< orphan*/ * of_node; } ;
struct TYPE_5__ {int /*<<< orphan*/ * of_node; } ;

/* Variables and functions */
 int /*<<< orphan*/  of_node_put (int /*<<< orphan*/ *) ; 
 struct snd_soc_card* platform_get_drvdata (struct platform_device*) ; 
 struct tegra_alc5632* snd_soc_card_get_drvdata (struct snd_soc_card*) ; 
 int /*<<< orphan*/  snd_soc_unregister_card (struct snd_soc_card*) ; 
 TYPE_4__ tegra_alc5632_dai ; 
 int /*<<< orphan*/  tegra_asoc_utils_fini (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int tegra_alc5632_remove(struct platform_device *pdev)
{
	struct snd_soc_card *card = platform_get_drvdata(pdev);
	struct tegra_alc5632 *machine = snd_soc_card_get_drvdata(card);

	snd_soc_unregister_card(card);

	tegra_asoc_utils_fini(&machine->util_data);

	of_node_put(tegra_alc5632_dai.cpus->of_node);
	tegra_alc5632_dai.cpus->of_node = NULL;
	tegra_alc5632_dai.platforms->of_node = NULL;
	of_node_put(tegra_alc5632_dai.codecs->of_node);
	tegra_alc5632_dai.codecs->of_node = NULL;

	return 0;
}