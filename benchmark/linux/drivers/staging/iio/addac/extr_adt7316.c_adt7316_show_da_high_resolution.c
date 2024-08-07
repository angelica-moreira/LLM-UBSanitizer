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
struct iio_dev {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct adt7316_chip_info {int config3; scalar_t__ id; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int ADT7316_DA_HIGH_RESOLUTION ; 
 scalar_t__ ID_ADT7318 ; 
 scalar_t__ ID_ADT7519 ; 
 struct iio_dev* dev_to_iio_dev (struct device*) ; 
 struct adt7316_chip_info* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  sprintf (char*,char*) ; 

__attribute__((used)) static ssize_t adt7316_show_da_high_resolution(struct device *dev,
					       struct device_attribute *attr,
					       char *buf)
{
	struct iio_dev *dev_info = dev_to_iio_dev(dev);
	struct adt7316_chip_info *chip = iio_priv(dev_info);

	if (chip->config3 & ADT7316_DA_HIGH_RESOLUTION) {
		if (chip->id != ID_ADT7318 && chip->id != ID_ADT7519)
			return sprintf(buf, "1 (10 bits)\n");
	}

	return sprintf(buf, "0 (8 bits)\n");
}