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
typedef  int /*<<< orphan*/  xfs_failaddr_t ;
struct xfs_buf {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  XFS_CORRUPTION_DUMP_LEN ; 
 int /*<<< orphan*/  xfs_buf_offset (struct xfs_buf*,int /*<<< orphan*/ ) ; 
 void xfs_buf_verifier_error (struct xfs_buf*,int,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
xfs_verifier_error(
	struct xfs_buf		*bp,
	int			error,
	xfs_failaddr_t		failaddr)
{
	return xfs_buf_verifier_error(bp, error, "", xfs_buf_offset(bp, 0),
			XFS_CORRUPTION_DUMP_LEN, failaddr);
}