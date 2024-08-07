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
struct inode {int /*<<< orphan*/  i_data; int /*<<< orphan*/  i_mapping; } ;
struct file_lock {scalar_t__ fl_type; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOLCK ; 
 scalar_t__ F_UNLCK ; 
 scalar_t__ IS_GETLK (int) ; 
 scalar_t__ IS_SETLK (int) ; 
 scalar_t__ IS_SETLKW (int) ; 
 int /*<<< orphan*/  P9_DEBUG_VFS ; 
 scalar_t__ __mandatory_lock (struct inode*) ; 
 struct inode* file_inode (struct file*) ; 
 int /*<<< orphan*/  filemap_write_and_wait (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  invalidate_mapping_pages (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  p9_debug (int /*<<< orphan*/ ,char*,struct file*,int,struct file_lock*,struct file*) ; 
 int v9fs_file_do_lock (struct file*,int,struct file_lock*) ; 
 int v9fs_file_getlock (struct file*,struct file_lock*) ; 

__attribute__((used)) static int v9fs_file_lock_dotl(struct file *filp, int cmd, struct file_lock *fl)
{
	struct inode *inode = file_inode(filp);
	int ret = -ENOLCK;

	p9_debug(P9_DEBUG_VFS, "filp: %p cmd:%d lock: %p name: %pD\n",
		 filp, cmd, fl, filp);

	/* No mandatory locks */
	if (__mandatory_lock(inode) && fl->fl_type != F_UNLCK)
		goto out_err;

	if ((IS_SETLK(cmd) || IS_SETLKW(cmd)) && fl->fl_type != F_UNLCK) {
		filemap_write_and_wait(inode->i_mapping);
		invalidate_mapping_pages(&inode->i_data, 0, -1);
	}

	if (IS_SETLK(cmd) || IS_SETLKW(cmd))
		ret = v9fs_file_do_lock(filp, cmd, fl);
	else if (IS_GETLK(cmd))
		ret = v9fs_file_getlock(filp, fl);
	else
		ret = -EINVAL;
out_err:
	return ret;
}