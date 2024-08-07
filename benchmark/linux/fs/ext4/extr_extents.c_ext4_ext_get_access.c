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
struct inode {int dummy; } ;
struct ext4_ext_path {scalar_t__ p_bh; } ;
typedef  int /*<<< orphan*/  handle_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUFFER_TRACE (scalar_t__,char*) ; 
 int ext4_journal_get_write_access (int /*<<< orphan*/ *,scalar_t__) ; 

__attribute__((used)) static int ext4_ext_get_access(handle_t *handle, struct inode *inode,
				struct ext4_ext_path *path)
{
	if (path->p_bh) {
		/* path points to block */
		BUFFER_TRACE(path->p_bh, "get_write_access");
		return ext4_journal_get_write_access(handle, path->p_bh);
	}
	/* path points to leaf/index in inode body */
	/* we use in-core data, no need to protect them */
	return 0;
}