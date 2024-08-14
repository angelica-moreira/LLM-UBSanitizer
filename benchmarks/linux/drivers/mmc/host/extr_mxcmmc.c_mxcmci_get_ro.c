#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct mxcmci_host {TYPE_1__* pdata; } ;
struct mmc_host {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* get_ro ) (int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  mmc_dev (struct mmc_host*) ; 
 int mmc_gpio_get_ro (struct mmc_host*) ; 
 struct mxcmci_host* mmc_priv (struct mmc_host*) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mxcmci_get_ro(struct mmc_host *mmc)
{
	struct mxcmci_host *host = mmc_priv(mmc);

	if (host->pdata && host->pdata->get_ro)
		return !!host->pdata->get_ro(mmc_dev(mmc));
	/*
	 * If board doesn't support read only detection (no mmc_gpio
	 * context or gpio is invalid), then let the mmc core decide
	 * what to do.
	 */
	return mmc_gpio_get_ro(mmc);
}