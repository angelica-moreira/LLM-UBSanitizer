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
struct dm_cache_policy {int (* lookup ) (struct dm_cache_policy*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int,int*) ;} ;
typedef  int /*<<< orphan*/  dm_oblock_t ;
typedef  int /*<<< orphan*/  dm_cblock_t ;

/* Variables and functions */
 int stub1 (struct dm_cache_policy*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int,int*) ; 

__attribute__((used)) static inline int policy_lookup(struct dm_cache_policy *p, dm_oblock_t oblock, dm_cblock_t *cblock,
				int data_dir, bool fast_copy, bool *background_queued)
{
	return p->lookup(p, oblock, cblock, data_dir, fast_copy, background_queued);
}