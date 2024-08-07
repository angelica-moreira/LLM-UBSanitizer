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
struct usbnet {int /*<<< orphan*/  data; } ;
struct sr_data {int eeprom_len; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 struct usbnet* netdev_priv (struct net_device*) ; 

__attribute__((used)) static int sr_get_eeprom_len(struct net_device *net)
{
	struct usbnet *dev = netdev_priv(net);
	struct sr_data *data = (struct sr_data *)&dev->data;

	return data->eeprom_len;
}