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
struct mmc_host {int retune_now; scalar_t__ hold_retune; } ;

/* Variables and functions */

void mmc_retune_hold(struct mmc_host *host)
{
	if (!host->hold_retune)
		host->retune_now = 1;
	host->hold_retune += 1;
}