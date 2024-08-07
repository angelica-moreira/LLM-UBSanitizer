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
typedef  scalar_t__ uint8_t ;
struct xfs_dir2_data_entry {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 scalar_t__ XFS_DIR3_FT_MAX ; 

__attribute__((used)) static void
xfs_dir2_data_put_ftype(
	struct xfs_dir2_data_entry *dep,
	uint8_t			ftype)
{
	ASSERT(ftype < XFS_DIR3_FT_MAX);
}