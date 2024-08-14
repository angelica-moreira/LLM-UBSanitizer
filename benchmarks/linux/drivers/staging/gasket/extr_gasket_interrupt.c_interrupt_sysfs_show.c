#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ attr_type; } ;
struct gasket_sysfs_attribute {TYPE_1__ data; } ;
struct gasket_interrupt_data {int num_interrupts; int /*<<< orphan*/ * interrupt_counts; } ;
struct gasket_dev {int /*<<< orphan*/  dev; struct gasket_interrupt_data* interrupt_data; } ;
struct TYPE_4__ {int /*<<< orphan*/  name; } ;
struct device_attribute {TYPE_2__ attr; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
typedef  enum interrupt_sysfs_attribute_type { ____Placeholder_interrupt_sysfs_attribute_type } interrupt_sysfs_attribute_type ;

/* Variables and functions */
#define  ATTR_INTERRUPT_COUNTS 128 
 int PAGE_SIZE ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 struct gasket_sysfs_attribute* gasket_sysfs_get_attr (struct device*,struct device_attribute*) ; 
 struct gasket_dev* gasket_sysfs_get_device_data (struct device*) ; 
 int /*<<< orphan*/  gasket_sysfs_put_attr (struct device*,struct gasket_sysfs_attribute*) ; 
 int /*<<< orphan*/  gasket_sysfs_put_device_data (struct device*,struct gasket_dev*) ; 
 int scnprintf (char*,int,char*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t interrupt_sysfs_show(struct device *device,
				    struct device_attribute *attr, char *buf)
{
	int i, ret;
	ssize_t written = 0, total_written = 0;
	struct gasket_interrupt_data *interrupt_data;
	struct gasket_dev *gasket_dev;
	struct gasket_sysfs_attribute *gasket_attr;
	enum interrupt_sysfs_attribute_type sysfs_type;

	gasket_dev = gasket_sysfs_get_device_data(device);
	if (!gasket_dev) {
		dev_dbg(device, "No sysfs mapping found for device\n");
		return 0;
	}

	gasket_attr = gasket_sysfs_get_attr(device, attr);
	if (!gasket_attr) {
		dev_dbg(device, "No sysfs attr data found for device\n");
		gasket_sysfs_put_device_data(device, gasket_dev);
		return 0;
	}

	sysfs_type = (enum interrupt_sysfs_attribute_type)
		gasket_attr->data.attr_type;
	interrupt_data = gasket_dev->interrupt_data;
	switch (sysfs_type) {
	case ATTR_INTERRUPT_COUNTS:
		for (i = 0; i < interrupt_data->num_interrupts; ++i) {
			written =
				scnprintf(buf, PAGE_SIZE - total_written,
					  "0x%02x: %ld\n", i,
					  interrupt_data->interrupt_counts[i]);
			total_written += written;
			buf += written;
		}
		ret = total_written;
		break;
	default:
		dev_dbg(gasket_dev->dev, "Unknown attribute: %s\n",
			attr->attr.name);
		ret = 0;
		break;
	}

	gasket_sysfs_put_attr(device, gasket_attr);
	gasket_sysfs_put_device_data(device, gasket_dev);
	return ret;
}