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
struct xfs_scrub {int dummy; } ;
struct xfs_btree_cur {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  XFS_SCRUB_OFLAG_XFAIL ; 
 int /*<<< orphan*/  __return_address ; 
 int __xchk_btree_process_error (struct xfs_scrub*,struct xfs_btree_cur*,int,int*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

bool
xchk_btree_xref_process_error(
	struct xfs_scrub	*sc,
	struct xfs_btree_cur	*cur,
	int			level,
	int			*error)
{
	return __xchk_btree_process_error(sc, cur, level, error,
			XFS_SCRUB_OFLAG_XFAIL, __return_address);
}