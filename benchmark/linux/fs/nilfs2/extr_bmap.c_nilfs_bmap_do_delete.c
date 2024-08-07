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
struct TYPE_3__ {int /*<<< orphan*/  u_flags; } ;
struct nilfs_bmap {TYPE_2__* b_ops; TYPE_1__ b_u; } ;
typedef  int /*<<< orphan*/  __u64 ;
struct TYPE_4__ {int (* bop_check_delete ) (struct nilfs_bmap*,int /*<<< orphan*/ ) ;int (* bop_gather_data ) (struct nilfs_bmap*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ;int (* bop_delete ) (struct nilfs_bmap*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  NILFS_BMAP_LARGE ; 
 int NILFS_BMAP_LARGE_LOW ; 
 int nilfs_direct_delete_and_convert (struct nilfs_bmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int stub1 (struct nilfs_bmap*,int /*<<< orphan*/ ) ; 
 int stub2 (struct nilfs_bmap*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int stub3 (struct nilfs_bmap*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int nilfs_bmap_do_delete(struct nilfs_bmap *bmap, __u64 key)
{
	__u64 keys[NILFS_BMAP_LARGE_LOW + 1];
	__u64 ptrs[NILFS_BMAP_LARGE_LOW + 1];
	int ret, n;

	if (bmap->b_ops->bop_check_delete != NULL) {
		ret = bmap->b_ops->bop_check_delete(bmap, key);
		if (ret > 0) {
			n = bmap->b_ops->bop_gather_data(
				bmap, keys, ptrs, NILFS_BMAP_LARGE_LOW + 1);
			if (n < 0)
				return n;
			ret = nilfs_direct_delete_and_convert(
				bmap, key, keys, ptrs, n);
			if (ret == 0)
				bmap->b_u.u_flags &= ~NILFS_BMAP_LARGE;

			return ret;
		} else if (ret < 0)
			return ret;
	}

	return bmap->b_ops->bop_delete(bmap, key);
}