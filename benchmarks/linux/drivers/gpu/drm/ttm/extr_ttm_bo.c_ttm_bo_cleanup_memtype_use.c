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
struct ttm_buffer_object {int /*<<< orphan*/  mem; int /*<<< orphan*/ * ttm; TYPE_2__* bdev; } ;
struct TYPE_4__ {TYPE_1__* driver; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* move_notify ) (struct ttm_buffer_object*,int,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct ttm_buffer_object*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ttm_bo_mem_put (struct ttm_buffer_object*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ttm_tt_destroy (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void ttm_bo_cleanup_memtype_use(struct ttm_buffer_object *bo)
{
	if (bo->bdev->driver->move_notify)
		bo->bdev->driver->move_notify(bo, false, NULL);

	ttm_tt_destroy(bo->ttm);
	bo->ttm = NULL;
	ttm_bo_mem_put(bo, &bo->mem);
}