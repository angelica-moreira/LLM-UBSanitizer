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
struct ttm_tt {scalar_t__ state; int page_flags; TYPE_1__* func; int /*<<< orphan*/ * swap_storage; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* destroy ) (struct ttm_tt*) ;} ;

/* Variables and functions */
 int TTM_PAGE_FLAG_PERSISTENT_SWAP ; 
 int /*<<< orphan*/  fput (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct ttm_tt*) ; 
 scalar_t__ tt_unbound ; 
 int /*<<< orphan*/  ttm_tt_unbind (struct ttm_tt*) ; 
 int /*<<< orphan*/  ttm_tt_unpopulate (struct ttm_tt*) ; 

void ttm_tt_destroy(struct ttm_tt *ttm)
{
	if (ttm == NULL)
		return;

	ttm_tt_unbind(ttm);

	if (ttm->state == tt_unbound)
		ttm_tt_unpopulate(ttm);

	if (!(ttm->page_flags & TTM_PAGE_FLAG_PERSISTENT_SWAP) &&
	    ttm->swap_storage)
		fput(ttm->swap_storage);

	ttm->swap_storage = NULL;
	ttm->func->destroy(ttm);
}