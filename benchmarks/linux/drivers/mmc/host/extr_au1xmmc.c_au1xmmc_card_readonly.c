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
struct mmc_host {int dummy; } ;
struct au1xmmc_host {TYPE_1__* platdata; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* card_readonly ) (struct mmc_host*) ;} ;

/* Variables and functions */
 int ENOSYS ; 
 struct au1xmmc_host* mmc_priv (struct mmc_host*) ; 
 int /*<<< orphan*/  stub1 (struct mmc_host*) ; 

__attribute__((used)) static int au1xmmc_card_readonly(struct mmc_host *mmc)
{
	struct au1xmmc_host *host = mmc_priv(mmc);

	if (host->platdata && host->platdata->card_readonly)
		return !!host->platdata->card_readonly(mmc);

	return -ENOSYS;
}