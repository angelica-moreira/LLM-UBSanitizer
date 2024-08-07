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
struct ccwgroup_device {scalar_t__ state; int /*<<< orphan*/  onoff; } ;
typedef  int ssize_t ;

/* Variables and functions */
 scalar_t__ CCWGROUP_OFFLINE ; 
 int EAGAIN ; 
 int EINVAL ; 
 int ENODEV ; 
 scalar_t__ atomic_cmpxchg (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ccwgroup_ungroup (struct ccwgroup_device*) ; 
 scalar_t__ device_remove_file_self (struct device*,struct device_attribute*) ; 
 struct ccwgroup_device* to_ccwgroupdev (struct device*) ; 

__attribute__((used)) static ssize_t ccwgroup_ungroup_store(struct device *dev,
				      struct device_attribute *attr,
				      const char *buf, size_t count)
{
	struct ccwgroup_device *gdev = to_ccwgroupdev(dev);
	int rc = 0;

	/* Prevent concurrent online/offline processing and ungrouping. */
	if (atomic_cmpxchg(&gdev->onoff, 0, 1) != 0)
		return -EAGAIN;
	if (gdev->state != CCWGROUP_OFFLINE) {
		rc = -EINVAL;
		goto out;
	}

	if (device_remove_file_self(dev, attr))
		ccwgroup_ungroup(gdev);
	else
		rc = -ENODEV;
out:
	if (rc) {
		/* Release onoff "lock" when ungrouping failed. */
		atomic_set(&gdev->onoff, 0);
		return rc;
	}
	return count;
}