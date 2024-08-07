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
struct multipath_info {int /*<<< orphan*/ * rdev; } ;
struct mpconf {int /*<<< orphan*/  device_lock; struct multipath_info* multipaths; } ;
struct mddev {int raid_disks; int /*<<< orphan*/  degraded; int /*<<< orphan*/  gendisk; struct mpconf* private; } ;
struct md_rdev {int raid_disk; int data_offset; int /*<<< orphan*/  flags; int /*<<< orphan*/  bdev; } ;

/* Variables and functions */
 int EEXIST ; 
 int /*<<< orphan*/  In_sync ; 
 int /*<<< orphan*/  disk_stack_limits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int md_integrity_add_rdev (struct md_rdev*,struct mddev*) ; 
 int /*<<< orphan*/  print_multipath_conf (struct mpconf*) ; 
 int /*<<< orphan*/  rcu_assign_pointer (int /*<<< orphan*/ *,struct md_rdev*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int multipath_add_disk(struct mddev *mddev, struct md_rdev *rdev)
{
	struct mpconf *conf = mddev->private;
	int err = -EEXIST;
	int path;
	struct multipath_info *p;
	int first = 0;
	int last = mddev->raid_disks - 1;

	if (rdev->raid_disk >= 0)
		first = last = rdev->raid_disk;

	print_multipath_conf(conf);

	for (path = first; path <= last; path++)
		if ((p=conf->multipaths+path)->rdev == NULL) {
			disk_stack_limits(mddev->gendisk, rdev->bdev,
					  rdev->data_offset << 9);

			err = md_integrity_add_rdev(rdev, mddev);
			if (err)
				break;
			spin_lock_irq(&conf->device_lock);
			mddev->degraded--;
			rdev->raid_disk = path;
			set_bit(In_sync, &rdev->flags);
			spin_unlock_irq(&conf->device_lock);
			rcu_assign_pointer(p->rdev, rdev);
			err = 0;
			break;
		}

	print_multipath_conf(conf);

	return err;
}