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
struct typec_cable {scalar_t__ active; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  sprintf (char*,char*,char*) ; 
 struct typec_cable* to_typec_cable (struct device*) ; 

__attribute__((used)) static ssize_t
type_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct typec_cable *cable = to_typec_cable(dev);

	return sprintf(buf, "%s\n", cable->active ? "active" : "passive");
}