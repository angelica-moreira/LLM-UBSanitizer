#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_7__ ;
typedef  struct TYPE_20__   TYPE_4__ ;
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;
typedef  struct TYPE_16__   TYPE_14__ ;

/* Type definitions */
struct TYPE_19__ {scalar_t__ t_frextents_delta; TYPE_4__* t_mountp; } ;
typedef  TYPE_3__ xfs_trans_t ;
typedef  int /*<<< orphan*/  xfs_rtblock_t ;
struct TYPE_17__ {scalar_t__ sb_frextents; scalar_t__ sb_rextents; } ;
struct TYPE_20__ {TYPE_7__* m_rbmip; TYPE_1__ m_sb; } ;
typedef  TYPE_4__ xfs_mount_t ;
typedef  int /*<<< orphan*/  xfs_fsblock_t ;
typedef  scalar_t__ xfs_extlen_t ;
typedef  int /*<<< orphan*/  xfs_buf_t ;
typedef  scalar_t__ uint64_t ;
struct TYPE_18__ {int di_flags; } ;
struct TYPE_21__ {TYPE_2__ i_d; int /*<<< orphan*/ * i_itemp; } ;
struct TYPE_16__ {int /*<<< orphan*/  i_atime; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int /*<<< orphan*/ ) ; 
 TYPE_14__* VFS_I (TYPE_7__*) ; 
 int XFS_DIFLAG_NEWRTBM ; 
 int /*<<< orphan*/  XFS_ILOCK_EXCL ; 
 int /*<<< orphan*/  XFS_ILOG_CORE ; 
 int /*<<< orphan*/  XFS_TRANS_SB_FREXTENTS ; 
 int /*<<< orphan*/  xfs_isilocked (TYPE_7__*,int /*<<< orphan*/ ) ; 
 int xfs_rtcheck_alloc_range (TYPE_4__*,TYPE_3__*,int /*<<< orphan*/ ,scalar_t__) ; 
 int xfs_rtfree_range (TYPE_4__*,TYPE_3__*,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xfs_trans_log_inode (TYPE_3__*,TYPE_7__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xfs_trans_mod_sb (TYPE_3__*,int /*<<< orphan*/ ,long) ; 

int					/* error */
xfs_rtfree_extent(
	xfs_trans_t	*tp,		/* transaction pointer */
	xfs_rtblock_t	bno,		/* starting block number to free */
	xfs_extlen_t	len)		/* length of extent freed */
{
	int		error;		/* error value */
	xfs_mount_t	*mp;		/* file system mount structure */
	xfs_fsblock_t	sb;		/* summary file block number */
	xfs_buf_t	*sumbp = NULL;	/* summary file block buffer */

	mp = tp->t_mountp;

	ASSERT(mp->m_rbmip->i_itemp != NULL);
	ASSERT(xfs_isilocked(mp->m_rbmip, XFS_ILOCK_EXCL));

	error = xfs_rtcheck_alloc_range(mp, tp, bno, len);
	if (error)
		return error;

	/*
	 * Free the range of realtime blocks.
	 */
	error = xfs_rtfree_range(mp, tp, bno, len, &sumbp, &sb);
	if (error) {
		return error;
	}
	/*
	 * Mark more blocks free in the superblock.
	 */
	xfs_trans_mod_sb(tp, XFS_TRANS_SB_FREXTENTS, (long)len);
	/*
	 * If we've now freed all the blocks, reset the file sequence
	 * number to 0.
	 */
	if (tp->t_frextents_delta + mp->m_sb.sb_frextents ==
	    mp->m_sb.sb_rextents) {
		if (!(mp->m_rbmip->i_d.di_flags & XFS_DIFLAG_NEWRTBM))
			mp->m_rbmip->i_d.di_flags |= XFS_DIFLAG_NEWRTBM;
		*(uint64_t *)&VFS_I(mp->m_rbmip)->i_atime = 0;
		xfs_trans_log_inode(tp, mp->m_rbmip, XFS_ILOG_CORE);
	}
	return 0;
}