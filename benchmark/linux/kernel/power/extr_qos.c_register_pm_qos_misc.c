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
struct TYPE_2__ {int /*<<< orphan*/ * fops; int /*<<< orphan*/  name; int /*<<< orphan*/  minor; } ;
struct pm_qos_object {TYPE_1__ pm_qos_power_miscdev; int /*<<< orphan*/  name; } ;
struct dentry {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MISC_DYNAMIC_MINOR ; 
 int /*<<< orphan*/  S_IRUGO ; 
 int /*<<< orphan*/  debugfs_create_file (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct dentry*,void*,int /*<<< orphan*/ *) ; 
 int misc_register (TYPE_1__*) ; 
 int /*<<< orphan*/  pm_qos_debug_fops ; 
 int /*<<< orphan*/  pm_qos_power_fops ; 

__attribute__((used)) static int register_pm_qos_misc(struct pm_qos_object *qos, struct dentry *d)
{
	qos->pm_qos_power_miscdev.minor = MISC_DYNAMIC_MINOR;
	qos->pm_qos_power_miscdev.name = qos->name;
	qos->pm_qos_power_miscdev.fops = &pm_qos_power_fops;

	debugfs_create_file(qos->name, S_IRUGO, d, (void *)qos,
			    &pm_qos_debug_fops);

	return misc_register(&qos->pm_qos_power_miscdev);
}