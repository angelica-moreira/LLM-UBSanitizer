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
typedef  int /*<<< orphan*/  xfs_agnumber_t ;
typedef  int /*<<< orphan*/  xfs_agblock_t ;
struct xfs_scrub {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  XFS_SCRUB_OFLAG_XFAIL ; 
 int /*<<< orphan*/  __return_address ; 
 int __xchk_process_error (struct xfs_scrub*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

bool
xchk_xref_process_error(
	struct xfs_scrub	*sc,
	xfs_agnumber_t		agno,
	xfs_agblock_t		bno,
	int			*error)
{
	return __xchk_process_error(sc, agno, bno, error,
			XFS_SCRUB_OFLAG_XFAIL, __return_address);
}