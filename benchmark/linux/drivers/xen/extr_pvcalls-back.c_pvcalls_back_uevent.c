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
struct xenbus_device {int dummy; } ;
struct kobj_uevent_env {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int pvcalls_back_uevent(struct xenbus_device *xdev,
			       struct kobj_uevent_env *env)
{
	return 0;
}