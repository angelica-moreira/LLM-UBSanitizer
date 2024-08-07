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
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct adt7470_data {int auto_update_interval; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 struct adt7470_data* adt7470_update_device (struct device*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

__attribute__((used)) static ssize_t auto_update_interval_show(struct device *dev,
					 struct device_attribute *devattr,
					 char *buf)
{
	struct adt7470_data *data = adt7470_update_device(dev);
	return sprintf(buf, "%d\n", data->auto_update_interval);
}