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
typedef  int /*<<< orphan*/  u32 ;
struct device {int dummy; } ;
typedef  enum hwmon_sensor_types { ____Placeholder_hwmon_sensor_types } hwmon_sensor_types ;

/* Variables and functions */
 int EOPNOTSUPP ; 
#define  hwmon_chip 129 
#define  hwmon_temp 128 
 int lm90_chip_read (struct device*,int /*<<< orphan*/ ,int,long*) ; 
 int lm90_temp_read (struct device*,int /*<<< orphan*/ ,int,long*) ; 

__attribute__((used)) static int lm90_read(struct device *dev, enum hwmon_sensor_types type,
		     u32 attr, int channel, long *val)
{
	switch (type) {
	case hwmon_chip:
		return lm90_chip_read(dev, attr, channel, val);
	case hwmon_temp:
		return lm90_temp_read(dev, attr, channel, val);
	default:
		return -EOPNOTSUPP;
	}
}