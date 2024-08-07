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
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/ * dimm_fail_cmd_flags ; 
 int dimm_name_to_id (struct device*) ; 
 int sprintf (char*,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t fail_cmd_show(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	int dimm = dimm_name_to_id(dev);

	if (dimm < 0)
		return dimm;

	return sprintf(buf, "%#lx\n", dimm_fail_cmd_flags[dimm]);
}