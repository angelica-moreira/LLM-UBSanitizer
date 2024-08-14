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
struct acpi_battery {int alarm_capacity; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  acpi_battery_get_alarm (struct acpi_battery*) ; 
 int acpi_battery_scale (struct acpi_battery*) ; 
 int /*<<< orphan*/  dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 struct acpi_battery* to_acpi_battery (int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t acpi_battery_alarm_show(struct device *dev,
					struct device_attribute *attr,
					char *buf)
{
	struct acpi_battery *battery = to_acpi_battery(dev_get_drvdata(dev));
	acpi_battery_get_alarm(battery);
	return sprintf(buf, "%d\n", battery->alarm_capacity *
				acpi_battery_scale(battery) * 1000);
}