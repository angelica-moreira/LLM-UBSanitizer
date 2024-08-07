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
typedef  int /*<<< orphan*/  xfs_alloc_rec_t ;
typedef  int /*<<< orphan*/  xfs_alloc_ptr_t ;
typedef  int /*<<< orphan*/  xfs_alloc_key_t ;
struct xfs_mount {int dummy; } ;

/* Variables and functions */
 scalar_t__ XFS_ALLOC_BLOCK_LEN (struct xfs_mount*) ; 

int
xfs_allocbt_maxrecs(
	struct xfs_mount	*mp,
	int			blocklen,
	int			leaf)
{
	blocklen -= XFS_ALLOC_BLOCK_LEN(mp);

	if (leaf)
		return blocklen / sizeof(xfs_alloc_rec_t);
	return blocklen / (sizeof(xfs_alloc_key_t) + sizeof(xfs_alloc_ptr_t));
}