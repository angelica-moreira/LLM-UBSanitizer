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
struct mii_if_info {int /*<<< orphan*/  dev; scalar_t__ force_media; } ;

/* Variables and functions */
 int /*<<< orphan*/  korina_check_media (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  netif_carrier_ok (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  netif_carrier_on (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void korina_set_carrier(struct mii_if_info *mii)
{
	if (mii->force_media) {
		/* autoneg is off: Link is always assumed to be up */
		if (!netif_carrier_ok(mii->dev))
			netif_carrier_on(mii->dev);
	} else  /* Let MMI library update carrier status */
		korina_check_media(mii->dev, 0);
}