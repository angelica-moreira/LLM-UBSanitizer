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
struct ib_umad_port {TYPE_1__* ib_dev; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENODEV ; 
 struct ib_umad_port* dev_get_drvdata (struct device*) ; 
 char* dev_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*) ; 

__attribute__((used)) static ssize_t ibdev_show(struct device *dev, struct device_attribute *attr,
			  char *buf)
{
	struct ib_umad_port *port = dev_get_drvdata(dev);

	if (!port)
		return -ENODEV;

	return sprintf(buf, "%s\n", dev_name(&port->ib_dev->dev));
}