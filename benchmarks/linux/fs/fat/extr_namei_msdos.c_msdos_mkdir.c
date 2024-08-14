#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  umode_t ;
struct timespec64 {int dummy; } ;
struct super_block {int dummy; } ;
struct inode {struct super_block* i_sb; } ;
struct fat_slot_info {int /*<<< orphan*/  bh; int /*<<< orphan*/  i_pos; int /*<<< orphan*/  de; } ;
struct TYPE_3__ {char* name; int /*<<< orphan*/  len; } ;
struct dentry {TYPE_1__ d_name; } ;
struct TYPE_4__ {int /*<<< orphan*/  s_lock; int /*<<< orphan*/  options; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ IS_ERR (struct inode*) ; 
 int MSDOS_NAME ; 
 TYPE_2__* MSDOS_SB (struct super_block*) ; 
 int PTR_ERR (struct inode*) ; 
 int S_ATIME ; 
 int S_CTIME ; 
 int S_MTIME ; 
 int /*<<< orphan*/  brelse (int /*<<< orphan*/ ) ; 
 struct timespec64 current_time (struct inode*) ; 
 int /*<<< orphan*/  d_instantiate (struct dentry*,struct inode*) ; 
 int fat_alloc_new_dir (struct inode*,struct timespec64*) ; 
 struct inode* fat_build_inode (struct super_block*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fat_flush_inodes (struct super_block*,struct inode*,struct inode*) ; 
 int /*<<< orphan*/  fat_free_clusters (struct inode*,int) ; 
 int /*<<< orphan*/  fat_scan (struct inode*,unsigned char*,struct fat_slot_info*) ; 
 int /*<<< orphan*/  fat_truncate_time (struct inode*,struct timespec64*,int) ; 
 int /*<<< orphan*/  inc_nlink (struct inode*) ; 
 int msdos_add_entry (struct inode*,unsigned char*,int,int,int,struct timespec64*,struct fat_slot_info*) ; 
 int msdos_format_name (char*,int /*<<< orphan*/ ,unsigned char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  set_nlink (struct inode*,int) ; 

__attribute__((used)) static int msdos_mkdir(struct inode *dir, struct dentry *dentry, umode_t mode)
{
	struct super_block *sb = dir->i_sb;
	struct fat_slot_info sinfo;
	struct inode *inode;
	unsigned char msdos_name[MSDOS_NAME];
	struct timespec64 ts;
	int err, is_hid, cluster;

	mutex_lock(&MSDOS_SB(sb)->s_lock);

	err = msdos_format_name(dentry->d_name.name, dentry->d_name.len,
				msdos_name, &MSDOS_SB(sb)->options);
	if (err)
		goto out;
	is_hid = (dentry->d_name.name[0] == '.') && (msdos_name[0] != '.');
	/* foo vs .foo situation */
	if (!fat_scan(dir, msdos_name, &sinfo)) {
		brelse(sinfo.bh);
		err = -EINVAL;
		goto out;
	}

	ts = current_time(dir);
	cluster = fat_alloc_new_dir(dir, &ts);
	if (cluster < 0) {
		err = cluster;
		goto out;
	}
	err = msdos_add_entry(dir, msdos_name, 1, is_hid, cluster, &ts, &sinfo);
	if (err)
		goto out_free;
	inc_nlink(dir);

	inode = fat_build_inode(sb, sinfo.de, sinfo.i_pos);
	brelse(sinfo.bh);
	if (IS_ERR(inode)) {
		err = PTR_ERR(inode);
		/* the directory was completed, just return a error */
		goto out;
	}
	set_nlink(inode, 2);
	fat_truncate_time(inode, &ts, S_ATIME|S_CTIME|S_MTIME);
	/* timestamp is already written, so mark_inode_dirty() is unneeded. */

	d_instantiate(dentry, inode);

	mutex_unlock(&MSDOS_SB(sb)->s_lock);
	fat_flush_inodes(sb, dir, inode);
	return 0;

out_free:
	fat_free_clusters(dir, cluster);
out:
	mutex_unlock(&MSDOS_SB(sb)->s_lock);
	return err;
}