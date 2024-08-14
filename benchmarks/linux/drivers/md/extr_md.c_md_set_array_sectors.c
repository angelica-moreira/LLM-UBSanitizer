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
struct mddev {int /*<<< orphan*/  array_sectors; scalar_t__ external_size; int /*<<< orphan*/  reconfig_mutex; } ;
typedef  int /*<<< orphan*/  sector_t ;

/* Variables and functions */
 int /*<<< orphan*/  lockdep_assert_held (int /*<<< orphan*/ *) ; 

void md_set_array_sectors(struct mddev *mddev, sector_t array_sectors)
{
	lockdep_assert_held(&mddev->reconfig_mutex);

	if (mddev->external_size)
		return;

	mddev->array_sectors = array_sectors;
}