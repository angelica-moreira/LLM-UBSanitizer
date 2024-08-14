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
struct dm_block_manager {int dummy; } ;
struct dm_block {int dummy; } ;
typedef  scalar_t__ __le64 ;

/* Variables and functions */
 int /*<<< orphan*/  SUPERBLOCK_LOCATION ; 
 scalar_t__ cpu_to_le64 (int /*<<< orphan*/ ) ; 
 scalar_t__* dm_block_data (struct dm_block*) ; 
 int dm_bm_block_size (struct dm_block_manager*) ; 
 int dm_bm_read_lock (struct dm_block_manager*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct dm_block**) ; 
 int /*<<< orphan*/  dm_bm_unlock (struct dm_block*) ; 

__attribute__((used)) static int superblock_all_zeroes(struct dm_block_manager *bm, bool *result)
{
	int r;
	unsigned i;
	struct dm_block *b;
	__le64 *data_le, zero = cpu_to_le64(0);
	unsigned sb_block_size = dm_bm_block_size(bm) / sizeof(__le64);

	/*
	 * We can't use a validator here - it may be all zeroes.
	 */
	r = dm_bm_read_lock(bm, SUPERBLOCK_LOCATION, NULL, &b);
	if (r)
		return r;

	data_le = dm_block_data(b);
	*result = true;
	for (i = 0; i < sb_block_size; i++) {
		if (data_le[i] != zero) {
			*result = false;
			break;
		}
	}

	dm_bm_unlock(b);

	return 0;
}