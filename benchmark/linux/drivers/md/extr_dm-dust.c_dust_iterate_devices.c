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
struct dust_device {int /*<<< orphan*/  start; int /*<<< orphan*/  dev; } ;
struct dm_target {int /*<<< orphan*/  len; struct dust_device* private; } ;
typedef  int (* iterate_devices_callout_fn ) (struct dm_target*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ;

/* Variables and functions */

__attribute__((used)) static int dust_iterate_devices(struct dm_target *ti, iterate_devices_callout_fn fn,
				void *data)
{
	struct dust_device *dd = ti->private;

	return fn(ti, dd->dev, dd->start, ti->len, data);
}