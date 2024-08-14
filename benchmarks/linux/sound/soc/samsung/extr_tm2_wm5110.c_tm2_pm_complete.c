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
struct snd_soc_card {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 struct snd_soc_card* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  tm2_start_sysclk (struct snd_soc_card*) ; 

__attribute__((used)) static void tm2_pm_complete(struct device *dev)
{
	struct snd_soc_card *card = dev_get_drvdata(dev);

	tm2_start_sysclk(card);
}