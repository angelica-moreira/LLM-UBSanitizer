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
struct il_priv {int /*<<< orphan*/  active; int /*<<< orphan*/  staging; } ;

/* Variables and functions */
 int /*<<< orphan*/  il3945_commit_rxon (struct il_priv*) ; 
 scalar_t__ memcmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 

void
il3945_post_scan(struct il_priv *il)
{
	/*
	 * Since setting the RXON may have been deferred while
	 * performing the scan, fire one off if needed
	 */
	if (memcmp(&il->staging, &il->active, sizeof(il->staging)))
		il3945_commit_rxon(il);
}