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
struct dc {int /*<<< orphan*/  hwseq; TYPE_2__* res_pool; } ;
struct TYPE_4__ {TYPE_1__* funcs; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* destroy ) (TYPE_2__**) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__**) ; 

void dc_destroy_resource_pool(struct dc  *dc)
{
	if (dc) {
		if (dc->res_pool)
			dc->res_pool->funcs->destroy(&dc->res_pool);

		kfree(dc->hwseq);
	}
}