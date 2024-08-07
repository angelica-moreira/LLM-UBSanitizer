#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct sdhci_host {TYPE_2__* mmc; } ;
struct TYPE_3__ {int /*<<< orphan*/  vmmc; } ;
struct TYPE_4__ {TYPE_1__ supply; } ;

/* Variables and functions */
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sdhci_set_power_noreg (struct sdhci_host*,unsigned char,unsigned short) ; 
 int /*<<< orphan*/  sdhci_set_power_reg (struct sdhci_host*,unsigned char,unsigned short) ; 

void sdhci_set_power(struct sdhci_host *host, unsigned char mode,
		     unsigned short vdd)
{
	if (IS_ERR(host->mmc->supply.vmmc))
		sdhci_set_power_noreg(host, mode, vdd);
	else
		sdhci_set_power_reg(host, mode, vdd);
}