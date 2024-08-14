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
struct TYPE_2__ {struct b43_phy_operations* ops; } ;
struct b43_wldev {TYPE_1__ phy; } ;
struct b43_phy_operations {int /*<<< orphan*/  (* pwork_60sec ) (struct b43_wldev*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  B43_TXPWR_IGNORE_TIME ; 
 int /*<<< orphan*/  b43_phy_txpower_check (struct b43_wldev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct b43_wldev*) ; 

__attribute__((used)) static void b43_periodic_every60sec(struct b43_wldev *dev)
{
	const struct b43_phy_operations *ops = dev->phy.ops;

	if (ops->pwork_60sec)
		ops->pwork_60sec(dev);

	/* Force check the TX power emission now. */
	b43_phy_txpower_check(dev, B43_TXPWR_IGNORE_TIME);
}