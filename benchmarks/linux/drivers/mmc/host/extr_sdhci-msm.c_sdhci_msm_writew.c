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
typedef  scalar_t__ u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct sdhci_host {scalar_t__ ioaddr; } ;

/* Variables and functions */
 scalar_t__ __sdhci_msm_check_write (struct sdhci_host*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sdhci_msm_check_power_status (struct sdhci_host*,scalar_t__) ; 
 int /*<<< orphan*/  writew_relaxed (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void sdhci_msm_writew(struct sdhci_host *host, u16 val, int reg)
{
	u32 req_type = 0;

	req_type = __sdhci_msm_check_write(host, val, reg);
	writew_relaxed(val, host->ioaddr + reg);

	if (req_type)
		sdhci_msm_check_power_status(host, req_type);
}