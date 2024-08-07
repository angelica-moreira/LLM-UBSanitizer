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
struct dm_bio_prison_v2 {int /*<<< orphan*/  cell_pool; } ;
struct dm_bio_prison_cell_v2 {int dummy; } ;
typedef  int /*<<< orphan*/  gfp_t ;

/* Variables and functions */
 struct dm_bio_prison_cell_v2* mempool_alloc (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

struct dm_bio_prison_cell_v2 *dm_bio_prison_alloc_cell_v2(struct dm_bio_prison_v2 *prison, gfp_t gfp)
{
	return mempool_alloc(&prison->cell_pool, gfp);
}