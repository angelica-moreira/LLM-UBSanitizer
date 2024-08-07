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
struct ll_disk {int /*<<< orphan*/  tm; int /*<<< orphan*/  bitmap_root; } ;
struct dm_block {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  dm_block_location (struct dm_block*) ; 
 int dm_tm_new_block (int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct dm_block**) ; 
 int /*<<< orphan*/  dm_tm_unlock (int /*<<< orphan*/ ,struct dm_block*) ; 
 int /*<<< orphan*/  index_validator ; 

__attribute__((used)) static int metadata_ll_init_index(struct ll_disk *ll)
{
	int r;
	struct dm_block *b;

	r = dm_tm_new_block(ll->tm, &index_validator, &b);
	if (r < 0)
		return r;

	ll->bitmap_root = dm_block_location(b);

	dm_tm_unlock(ll->tm, b);

	return 0;
}