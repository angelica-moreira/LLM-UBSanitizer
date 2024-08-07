#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
struct TYPE_2__ {int /*<<< orphan*/  net_dev; } ;
struct i2400m {TYPE_1__ wimax_dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  netif_queue_stopped (int /*<<< orphan*/ ) ; 

__attribute__((used)) static
int debugfs_netdev_queue_stopped_get(void *data, u64 *val)
{
	struct i2400m *i2400m = data;
	*val = netif_queue_stopped(i2400m->wimax_dev.net_dev);
	return 0;
}