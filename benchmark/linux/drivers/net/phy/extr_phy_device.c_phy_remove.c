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
struct phy_device {TYPE_1__* drv; int /*<<< orphan*/  lock; int /*<<< orphan*/  state; int /*<<< orphan*/  state_queue; } ;
struct device {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* remove ) (struct phy_device*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  PHY_DOWN ; 
 int /*<<< orphan*/  cancel_delayed_work_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  phy_device_reset (struct phy_device*,int) ; 
 int /*<<< orphan*/  stub1 (struct phy_device*) ; 
 struct phy_device* to_phy_device (struct device*) ; 

__attribute__((used)) static int phy_remove(struct device *dev)
{
	struct phy_device *phydev = to_phy_device(dev);

	cancel_delayed_work_sync(&phydev->state_queue);

	mutex_lock(&phydev->lock);
	phydev->state = PHY_DOWN;
	mutex_unlock(&phydev->lock);

	if (phydev->drv && phydev->drv->remove) {
		phydev->drv->remove(phydev);

		/* Assert the reset signal */
		phy_device_reset(phydev, 1);
	}
	phydev->drv = NULL;

	return 0;
}