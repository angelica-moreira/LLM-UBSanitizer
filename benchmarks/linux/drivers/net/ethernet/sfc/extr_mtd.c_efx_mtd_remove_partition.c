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
struct efx_mtd_partition {int /*<<< orphan*/  node; int /*<<< orphan*/  mtd; } ;

/* Variables and functions */
 int EBUSY ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  list_del (int /*<<< orphan*/ *) ; 
 int mtd_device_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ssleep (int) ; 

__attribute__((used)) static void efx_mtd_remove_partition(struct efx_mtd_partition *part)
{
	int rc;

	for (;;) {
		rc = mtd_device_unregister(&part->mtd);
		if (rc != -EBUSY)
			break;
		ssleep(1);
	}
	WARN_ON(rc);
	list_del(&part->node);
}