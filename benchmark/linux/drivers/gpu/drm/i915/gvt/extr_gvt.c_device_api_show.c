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
struct kobject {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 char* VFIO_DEVICE_API_PCI_STRING ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*) ; 

__attribute__((used)) static ssize_t device_api_show(struct kobject *kobj, struct device *dev,
		char *buf)
{
	return sprintf(buf, "%s\n", VFIO_DEVICE_API_PCI_STRING);
}