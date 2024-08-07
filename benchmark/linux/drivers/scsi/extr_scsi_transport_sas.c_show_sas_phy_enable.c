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
struct sas_phy {int enabled; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 
 struct sas_phy* transport_class_to_phy (struct device*) ; 

__attribute__((used)) static ssize_t
show_sas_phy_enable(struct device *dev, struct device_attribute *attr,
		    char *buf)
{
	struct sas_phy *phy = transport_class_to_phy(dev);

	return snprintf(buf, 20, "%d", phy->enabled);
}