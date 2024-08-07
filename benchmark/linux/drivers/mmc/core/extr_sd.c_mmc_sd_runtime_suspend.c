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
struct mmc_host {int caps; } ;

/* Variables and functions */
 int MMC_CAP_AGGRESSIVE_PM ; 
 int _mmc_sd_suspend (struct mmc_host*) ; 
 int /*<<< orphan*/  mmc_hostname (struct mmc_host*) ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int mmc_sd_runtime_suspend(struct mmc_host *host)
{
	int err;

	if (!(host->caps & MMC_CAP_AGGRESSIVE_PM))
		return 0;

	err = _mmc_sd_suspend(host);
	if (err)
		pr_err("%s: error %d doing aggressive suspend\n",
			mmc_hostname(host), err);

	return err;
}