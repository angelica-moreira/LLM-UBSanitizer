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
struct tty_port {int dummy; } ;
struct tty_driver {int dummy; } ;
struct device {int dummy; } ;
struct attribute_group {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENODEV ; 
 int /*<<< orphan*/  PTR_ERR (struct device*) ; 
 struct device* serdev_tty_port_register (struct tty_port*,struct device*,struct tty_driver*,unsigned int) ; 
 int /*<<< orphan*/  tty_port_link_device (struct tty_port*,struct tty_driver*,unsigned int) ; 
 struct device* tty_register_device_attr (struct tty_driver*,unsigned int,struct device*,void*,struct attribute_group const**) ; 

struct device *tty_port_register_device_attr_serdev(struct tty_port *port,
		struct tty_driver *driver, unsigned index,
		struct device *device, void *drvdata,
		const struct attribute_group **attr_grp)
{
	struct device *dev;

	tty_port_link_device(port, driver, index);

	dev = serdev_tty_port_register(port, device, driver, index);
	if (PTR_ERR(dev) != -ENODEV) {
		/* Skip creating cdev if we registered a serdev device */
		return dev;
	}

	return tty_register_device_attr(driver, index, device, drvdata,
			attr_grp);
}