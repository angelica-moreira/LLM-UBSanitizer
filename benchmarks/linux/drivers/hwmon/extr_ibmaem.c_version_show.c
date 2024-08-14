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
struct aem_data {int ver_major; int ver_minor; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 struct aem_data* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int,int) ; 

__attribute__((used)) static ssize_t version_show(struct device *dev,
			    struct device_attribute *devattr, char *buf)
{
	struct aem_data *data = dev_get_drvdata(dev);

	return sprintf(buf, "%d.%d\n", data->ver_major, data->ver_minor);
}