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
struct gendisk {int dummy; } ;
struct block_device {int /*<<< orphan*/  bd_mutex; struct block_device* bd_contains; struct gendisk* bd_disk; } ;

/* Variables and functions */
 int /*<<< orphan*/  CAP_SYS_ADMIN ; 
 int EACCES ; 
 int EINVAL ; 
 int /*<<< orphan*/  capable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  disk_part_scan_enabled (struct gendisk*) ; 
 int /*<<< orphan*/  lockdep_assert_held (int /*<<< orphan*/ *) ; 
 int rescan_partitions (struct gendisk*,struct block_device*) ; 

int __blkdev_reread_part(struct block_device *bdev)
{
	struct gendisk *disk = bdev->bd_disk;

	if (!disk_part_scan_enabled(disk) || bdev != bdev->bd_contains)
		return -EINVAL;
	if (!capable(CAP_SYS_ADMIN))
		return -EACCES;

	lockdep_assert_held(&bdev->bd_mutex);

	return rescan_partitions(disk, bdev);
}