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
struct apds990x_chip {int /*<<< orphan*/  prox_continuous_mode; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 struct apds990x_chip* dev_get_drvdata (struct device*) ; 
 char** reporting_modes ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*) ; 

__attribute__((used)) static ssize_t apds990x_prox_reporting_mode_show(struct device *dev,
				   struct device_attribute *attr, char *buf)
{
	struct apds990x_chip *chip =  dev_get_drvdata(dev);

	return sprintf(buf, "%s\n",
		reporting_modes[!!chip->prox_continuous_mode]);
}