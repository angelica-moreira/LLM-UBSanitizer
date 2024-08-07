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
struct dust_device {int /*<<< orphan*/  fail_read_on_bb; scalar_t__ start; TYPE_1__* dev; } ;
struct dm_target {struct dust_device* private; } ;
struct TYPE_4__ {scalar_t__ bi_sector; } ;
struct bio {TYPE_2__ bi_iter; } ;
struct TYPE_3__ {int /*<<< orphan*/  bdev; } ;

/* Variables and functions */
 scalar_t__ READ ; 
 scalar_t__ bio_data_dir (struct bio*) ; 
 int /*<<< orphan*/  bio_set_dev (struct bio*,int /*<<< orphan*/ ) ; 
 scalar_t__ dm_target_offset (struct dm_target*,scalar_t__) ; 
 int dust_map_read (struct dust_device*,scalar_t__,int /*<<< orphan*/ ) ; 
 int dust_map_write (struct dust_device*,scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int dust_map(struct dm_target *ti, struct bio *bio)
{
	struct dust_device *dd = ti->private;
	int ret;

	bio_set_dev(bio, dd->dev->bdev);
	bio->bi_iter.bi_sector = dd->start + dm_target_offset(ti, bio->bi_iter.bi_sector);

	if (bio_data_dir(bio) == READ)
		ret = dust_map_read(dd, bio->bi_iter.bi_sector, dd->fail_read_on_bb);
	else
		ret = dust_map_write(dd, bio->bi_iter.bi_sector, dd->fail_read_on_bb);

	return ret;
}