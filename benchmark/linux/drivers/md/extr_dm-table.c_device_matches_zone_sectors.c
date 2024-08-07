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
struct request_queue {int dummy; } ;
struct dm_target {int dummy; } ;
struct dm_dev {int /*<<< orphan*/  bdev; } ;
typedef  int /*<<< orphan*/  sector_t ;

/* Variables and functions */
 struct request_queue* bdev_get_queue (int /*<<< orphan*/ ) ; 
 unsigned int blk_queue_zone_sectors (struct request_queue*) ; 

__attribute__((used)) static int device_matches_zone_sectors(struct dm_target *ti, struct dm_dev *dev,
				       sector_t start, sector_t len, void *data)
{
	struct request_queue *q = bdev_get_queue(dev->bdev);
	unsigned int *zone_sectors = data;

	return q && blk_queue_zone_sectors(q) == *zone_sectors;
}