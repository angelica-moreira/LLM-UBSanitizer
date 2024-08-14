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
struct efx_nic {int /*<<< orphan*/  mtd_list; TYPE_1__* type; } ;
struct TYPE_4__ {int writesize; int flags; int /*<<< orphan*/  _sync; int /*<<< orphan*/  _write; int /*<<< orphan*/  _read; int /*<<< orphan*/  _erase; int /*<<< orphan*/  name; struct efx_nic* priv; int /*<<< orphan*/  owner; } ;
struct efx_mtd_partition {int /*<<< orphan*/  node; TYPE_2__ mtd; int /*<<< orphan*/  name; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* mtd_rename ) (struct efx_mtd_partition*) ;int /*<<< orphan*/  mtd_write; int /*<<< orphan*/  mtd_read; } ;

/* Variables and functions */
 int ENOMEM ; 
 int MTD_NO_ERASE ; 
 int MTD_WRITEABLE ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  efx_mtd_erase ; 
 int /*<<< orphan*/  efx_mtd_remove_partition (struct efx_mtd_partition*) ; 
 int /*<<< orphan*/  efx_mtd_sync ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ mtd_device_register (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct efx_mtd_partition*) ; 

int efx_mtd_add(struct efx_nic *efx, struct efx_mtd_partition *parts,
		size_t n_parts, size_t sizeof_part)
{
	struct efx_mtd_partition *part;
	size_t i;

	for (i = 0; i < n_parts; i++) {
		part = (struct efx_mtd_partition *)((char *)parts +
						    i * sizeof_part);

		part->mtd.writesize = 1;

		if (!(part->mtd.flags & MTD_NO_ERASE))
			part->mtd.flags |= MTD_WRITEABLE;

		part->mtd.owner = THIS_MODULE;
		part->mtd.priv = efx;
		part->mtd.name = part->name;
		part->mtd._erase = efx_mtd_erase;
		part->mtd._read = efx->type->mtd_read;
		part->mtd._write = efx->type->mtd_write;
		part->mtd._sync = efx_mtd_sync;

		efx->type->mtd_rename(part);

		if (mtd_device_register(&part->mtd, NULL, 0))
			goto fail;

		/* Add to list in order - efx_mtd_remove() depends on this */
		list_add_tail(&part->node, &efx->mtd_list);
	}

	return 0;

fail:
	while (i--) {
		part = (struct efx_mtd_partition *)((char *)parts +
						    i * sizeof_part);
		efx_mtd_remove_partition(part);
	}
	/* Failure is unlikely here, but probably means we're out of memory */
	return -ENOMEM;
}