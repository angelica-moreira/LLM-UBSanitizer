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
struct ps3_system_bus_device {int /*<<< orphan*/  match_sub_id; int /*<<< orphan*/  match_id; } ;
struct kobj_uevent_env {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 scalar_t__ add_uevent_var (struct kobj_uevent_env*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct ps3_system_bus_device* ps3_dev_to_system_bus_dev (struct device*) ; 

__attribute__((used)) static int ps3_system_bus_uevent(struct device *_dev, struct kobj_uevent_env *env)
{
	struct ps3_system_bus_device *dev = ps3_dev_to_system_bus_dev(_dev);

	if (add_uevent_var(env, "MODALIAS=ps3:%d:%d", dev->match_id,
			   dev->match_sub_id))
		return -ENOMEM;
	return 0;
}