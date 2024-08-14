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
typedef  scalar_t__ xfs_failaddr_t ;
struct xfs_mount {int /*<<< orphan*/  m_sb; } ;
struct xfs_buf {struct xfs_mount* b_mount; } ;

/* Variables and functions */
 int /*<<< orphan*/  EFSBADCRC ; 
 int /*<<< orphan*/  EFSCORRUPTED ; 
 int /*<<< orphan*/  XFS_SYMLINK_CRC_OFF ; 
 scalar_t__ __this_address ; 
 int /*<<< orphan*/  xfs_buf_verify_cksum (struct xfs_buf*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xfs_sb_version_hascrc (int /*<<< orphan*/ *) ; 
 scalar_t__ xfs_symlink_verify (struct xfs_buf*) ; 
 int /*<<< orphan*/  xfs_verifier_error (struct xfs_buf*,int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void
xfs_symlink_read_verify(
	struct xfs_buf	*bp)
{
	struct xfs_mount *mp = bp->b_mount;
	xfs_failaddr_t	fa;

	/* no verification of non-crc buffers */
	if (!xfs_sb_version_hascrc(&mp->m_sb))
		return;

	if (!xfs_buf_verify_cksum(bp, XFS_SYMLINK_CRC_OFF))
		xfs_verifier_error(bp, -EFSBADCRC, __this_address);
	else {
		fa = xfs_symlink_verify(bp);
		if (fa)
			xfs_verifier_error(bp, -EFSCORRUPTED, fa);
	}
}