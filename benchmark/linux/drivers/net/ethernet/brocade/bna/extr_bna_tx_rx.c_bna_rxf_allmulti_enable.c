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
struct bna_rxf {int rxmode_active; int /*<<< orphan*/  rxmode_pending_bitmask; int /*<<< orphan*/  rxmode_pending; } ;

/* Variables and functions */
 int BNA_RXMODE_ALLMULTI ; 
 int /*<<< orphan*/  allmulti_enable (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  allmulti_inactive (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ is_allmulti_disable (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ is_allmulti_enable (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
bna_rxf_allmulti_enable(struct bna_rxf *rxf)
{
	int ret = 0;

	if (is_allmulti_enable(rxf->rxmode_pending,
			rxf->rxmode_pending_bitmask) ||
			(rxf->rxmode_active & BNA_RXMODE_ALLMULTI)) {
		/* Do nothing if pending enable or already enabled */
	} else if (is_allmulti_disable(rxf->rxmode_pending,
					rxf->rxmode_pending_bitmask)) {
		/* Turn off pending disable command */
		allmulti_inactive(rxf->rxmode_pending,
			rxf->rxmode_pending_bitmask);
	} else {
		/* Schedule enable */
		allmulti_enable(rxf->rxmode_pending,
				rxf->rxmode_pending_bitmask);
		ret = 1;
	}

	return ret;
}