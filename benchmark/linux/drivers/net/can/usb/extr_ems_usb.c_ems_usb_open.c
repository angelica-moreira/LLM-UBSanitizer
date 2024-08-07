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
struct net_device {int dummy; } ;
struct ems_usb {int /*<<< orphan*/  netdev; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  SJA1000_MOD_RM ; 
 int /*<<< orphan*/  close_candev (struct net_device*) ; 
 int ems_usb_start (struct ems_usb*) ; 
 int ems_usb_write_mode (struct ems_usb*,int /*<<< orphan*/ ) ; 
 struct ems_usb* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netdev_warn (struct net_device*,char*,int) ; 
 int /*<<< orphan*/  netif_device_detach (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  netif_start_queue (struct net_device*) ; 
 int open_candev (struct net_device*) ; 

__attribute__((used)) static int ems_usb_open(struct net_device *netdev)
{
	struct ems_usb *dev = netdev_priv(netdev);
	int err;

	err = ems_usb_write_mode(dev, SJA1000_MOD_RM);
	if (err)
		return err;

	/* common open */
	err = open_candev(netdev);
	if (err)
		return err;

	/* finally start device */
	err = ems_usb_start(dev);
	if (err) {
		if (err == -ENODEV)
			netif_device_detach(dev->netdev);

		netdev_warn(netdev, "couldn't start device: %d\n", err);

		close_candev(netdev);

		return err;
	}


	netif_start_queue(netdev);

	return 0;
}