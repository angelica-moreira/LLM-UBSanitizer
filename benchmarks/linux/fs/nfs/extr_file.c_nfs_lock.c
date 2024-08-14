#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct inode {int dummy; } ;
struct file_lock {scalar_t__ fl_type; scalar_t__ fl_end; scalar_t__ fl_start; int /*<<< orphan*/  fl_flags; } ;
struct file {TYPE_1__* f_mapping; } ;
struct TYPE_6__ {int (* lock_check_bounds ) (struct file_lock*) ;} ;
struct TYPE_5__ {int flags; } ;
struct TYPE_4__ {struct inode* host; } ;

/* Variables and functions */
 int ENOLCK ; 
 scalar_t__ F_UNLCK ; 
 scalar_t__ IS_GETLK (int) ; 
 int /*<<< orphan*/  NFSIOS_VFSLOCK ; 
 int NFS_MOUNT_LOCAL_FCNTL ; 
 TYPE_3__* NFS_PROTO (struct inode*) ; 
 TYPE_2__* NFS_SERVER (struct inode*) ; 
 scalar_t__ __mandatory_lock (struct inode*) ; 
 int do_getlk (struct file*,int,struct file_lock*,int) ; 
 int do_setlk (struct file*,int,struct file_lock*,int) ; 
 int do_unlk (struct file*,int,struct file_lock*,int) ; 
 int /*<<< orphan*/  dprintk (char*,struct file*,scalar_t__,int /*<<< orphan*/ ,long long,long long) ; 
 int /*<<< orphan*/  nfs_inc_stats (struct inode*,int /*<<< orphan*/ ) ; 
 int stub1 (struct file_lock*) ; 

int nfs_lock(struct file *filp, int cmd, struct file_lock *fl)
{
	struct inode *inode = filp->f_mapping->host;
	int ret = -ENOLCK;
	int is_local = 0;

	dprintk("NFS: lock(%pD2, t=%x, fl=%x, r=%lld:%lld)\n",
			filp, fl->fl_type, fl->fl_flags,
			(long long)fl->fl_start, (long long)fl->fl_end);

	nfs_inc_stats(inode, NFSIOS_VFSLOCK);

	/* No mandatory locks over NFS */
	if (__mandatory_lock(inode) && fl->fl_type != F_UNLCK)
		goto out_err;

	if (NFS_SERVER(inode)->flags & NFS_MOUNT_LOCAL_FCNTL)
		is_local = 1;

	if (NFS_PROTO(inode)->lock_check_bounds != NULL) {
		ret = NFS_PROTO(inode)->lock_check_bounds(fl);
		if (ret < 0)
			goto out_err;
	}

	if (IS_GETLK(cmd))
		ret = do_getlk(filp, cmd, fl, is_local);
	else if (fl->fl_type == F_UNLCK)
		ret = do_unlk(filp, cmd, fl, is_local);
	else
		ret = do_setlk(filp, cmd, fl, is_local);
out_err:
	return ret;
}