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
struct ef4_nic {int phy_mode; scalar_t__ state; int /*<<< orphan*/  net_dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
typedef  enum ef4_phy_mode { ____Placeholder_ef4_phy_mode } ef4_phy_mode ;

/* Variables and functions */
 int EBUSY ; 
 int PHY_MODE_SPECIAL ; 
 scalar_t__ STATE_READY ; 
 struct ef4_nic* dev_get_drvdata (struct device*) ; 
 int ef4_reconfigure_port (struct ef4_nic*) ; 
 int /*<<< orphan*/  falcon_start_nic_stats (struct ef4_nic*) ; 
 int /*<<< orphan*/  falcon_stop_nic_stats (struct ef4_nic*) ; 
 scalar_t__ netif_running (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtnl_lock () ; 
 int /*<<< orphan*/  rtnl_unlock () ; 
 int sfe4001_poweron (struct ef4_nic*) ; 

__attribute__((used)) static ssize_t set_phy_flash_cfg(struct device *dev,
				 struct device_attribute *attr,
				 const char *buf, size_t count)
{
	struct ef4_nic *efx = dev_get_drvdata(dev);
	enum ef4_phy_mode old_mode, new_mode;
	int err;

	rtnl_lock();
	old_mode = efx->phy_mode;
	if (count == 0 || *buf == '0')
		new_mode = old_mode & ~PHY_MODE_SPECIAL;
	else
		new_mode = PHY_MODE_SPECIAL;
	if (!((old_mode ^ new_mode) & PHY_MODE_SPECIAL)) {
		err = 0;
	} else if (efx->state != STATE_READY || netif_running(efx->net_dev)) {
		err = -EBUSY;
	} else {
		/* Reset the PHY, reconfigure the MAC and enable/disable
		 * MAC stats accordingly. */
		efx->phy_mode = new_mode;
		if (new_mode & PHY_MODE_SPECIAL)
			falcon_stop_nic_stats(efx);
		err = sfe4001_poweron(efx);
		if (!err)
			err = ef4_reconfigure_port(efx);
		if (!(new_mode & PHY_MODE_SPECIAL))
			falcon_start_nic_stats(efx);
	}
	rtnl_unlock();

	return err ? err : count;
}