#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct mdev_device {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct TYPE_3__ {unsigned long apm_max; int /*<<< orphan*/  apm; } ;
struct ap_matrix_mdev {TYPE_1__ matrix; scalar_t__ kvm; } ;
typedef  int ssize_t ;
struct TYPE_4__ {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int EBUSY ; 
 int ENODEV ; 
 int /*<<< orphan*/  clear_bit_inv (unsigned long,int /*<<< orphan*/ ) ; 
 int kstrtoul (char const*,int /*<<< orphan*/ ,unsigned long*) ; 
 TYPE_2__* matrix_dev ; 
 struct mdev_device* mdev_from_dev (struct device*) ; 
 struct ap_matrix_mdev* mdev_get_drvdata (struct mdev_device*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static ssize_t unassign_adapter_store(struct device *dev,
				      struct device_attribute *attr,
				      const char *buf, size_t count)
{
	int ret;
	unsigned long apid;
	struct mdev_device *mdev = mdev_from_dev(dev);
	struct ap_matrix_mdev *matrix_mdev = mdev_get_drvdata(mdev);

	/* If the guest is running, disallow un-assignment of adapter */
	if (matrix_mdev->kvm)
		return -EBUSY;

	ret = kstrtoul(buf, 0, &apid);
	if (ret)
		return ret;

	if (apid > matrix_mdev->matrix.apm_max)
		return -ENODEV;

	mutex_lock(&matrix_dev->lock);
	clear_bit_inv((unsigned long)apid, matrix_mdev->matrix.apm);
	mutex_unlock(&matrix_dev->lock);

	return count;
}