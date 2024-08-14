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
struct mmc_host {int /*<<< orphan*/ * card; } ;

/* Variables and functions */
 int /*<<< orphan*/  mmc_remove_card (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void mmc_remove(struct mmc_host *host)
{
	mmc_remove_card(host->card);
	host->card = NULL;
}