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
struct nvmem_device {size_t type; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 char** nvmem_type_str ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*) ; 
 struct nvmem_device* to_nvmem_device (struct device*) ; 

__attribute__((used)) static ssize_t type_show(struct device *dev,
			 struct device_attribute *attr, char *buf)
{
	struct nvmem_device *nvmem = to_nvmem_device(dev);

	return sprintf(buf, "%s\n", nvmem_type_str[nvmem->type]);
}