#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct kobject {int dummy; } ;
struct kobj_attribute {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_2__ {scalar_t__ state; } ;

/* Variables and functions */
 int /*<<< orphan*/  sprintf (char*,char*,...) ; 
 TYPE_1__ ts78xx_fpga ; 

__attribute__((used)) static ssize_t ts78xx_fpga_show(struct kobject *kobj,
			struct kobj_attribute *attr, char *buf)
{
	if (ts78xx_fpga.state < 0)
		return sprintf(buf, "borked\n");

	return sprintf(buf, "%s\n", (ts78xx_fpga.state) ? "online" : "offline");
}