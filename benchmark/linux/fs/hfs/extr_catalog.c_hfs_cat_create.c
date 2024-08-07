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
typedef  union hfs_cat_rec {int dummy; } hfs_cat_rec ;
typedef  int /*<<< orphan*/  u32 ;
struct super_block {int dummy; } ;
struct qstr {int /*<<< orphan*/  name; } ;
struct inode {scalar_t__ i_size; int /*<<< orphan*/  i_ctime; int /*<<< orphan*/  i_mtime; int /*<<< orphan*/  i_ino; int /*<<< orphan*/  i_mode; struct super_block* i_sb; int /*<<< orphan*/  i_nlink; } ;
struct hfs_find_data {int /*<<< orphan*/  search_key; TYPE_1__* tree; } ;
struct TYPE_4__ {int /*<<< orphan*/  cat_tree; } ;
struct TYPE_3__ {int depth; } ;

/* Variables and functions */
 int /*<<< orphan*/  CAT_MOD ; 
 int EEXIST ; 
 int ENOENT ; 
 int ENOSPC ; 
 int /*<<< orphan*/  HFS_CDR_FTH ; 
 int /*<<< orphan*/  HFS_CDR_THD ; 
 scalar_t__ HFS_MAX_VALENCE ; 
 TYPE_2__* HFS_SB (struct super_block*) ; 
 scalar_t__ S_ISDIR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  current_time (struct inode*) ; 
 int hfs_bmap_reserve (TYPE_1__*,int) ; 
 int hfs_brec_find (struct hfs_find_data*) ; 
 int hfs_brec_insert (struct hfs_find_data*,union hfs_cat_rec*,int) ; 
 int /*<<< orphan*/  hfs_brec_remove (struct hfs_find_data*) ; 
 int /*<<< orphan*/  hfs_cat_build_key (struct super_block*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct qstr const*) ; 
 int hfs_cat_build_record (union hfs_cat_rec*,int /*<<< orphan*/ ,struct inode*) ; 
 int hfs_cat_build_thread (struct super_block*,union hfs_cat_rec*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct qstr const*) ; 
 int /*<<< orphan*/  hfs_dbg (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hfs_find_exit (struct hfs_find_data*) ; 
 int hfs_find_init (int /*<<< orphan*/ ,struct hfs_find_data*) ; 
 int /*<<< orphan*/  mark_inode_dirty (struct inode*) ; 

int hfs_cat_create(u32 cnid, struct inode *dir, const struct qstr *str, struct inode *inode)
{
	struct hfs_find_data fd;
	struct super_block *sb;
	union hfs_cat_rec entry;
	int entry_size;
	int err;

	hfs_dbg(CAT_MOD, "create_cat: %s,%u(%d)\n",
		str->name, cnid, inode->i_nlink);
	if (dir->i_size >= HFS_MAX_VALENCE)
		return -ENOSPC;

	sb = dir->i_sb;
	err = hfs_find_init(HFS_SB(sb)->cat_tree, &fd);
	if (err)
		return err;

	/*
	 * Fail early and avoid ENOSPC during the btree operations. We may
	 * have to split the root node at most once.
	 */
	err = hfs_bmap_reserve(fd.tree, 2 * fd.tree->depth);
	if (err)
		goto err2;

	hfs_cat_build_key(sb, fd.search_key, cnid, NULL);
	entry_size = hfs_cat_build_thread(sb, &entry, S_ISDIR(inode->i_mode) ?
			HFS_CDR_THD : HFS_CDR_FTH,
			dir->i_ino, str);
	err = hfs_brec_find(&fd);
	if (err != -ENOENT) {
		if (!err)
			err = -EEXIST;
		goto err2;
	}
	err = hfs_brec_insert(&fd, &entry, entry_size);
	if (err)
		goto err2;

	hfs_cat_build_key(sb, fd.search_key, dir->i_ino, str);
	entry_size = hfs_cat_build_record(&entry, cnid, inode);
	err = hfs_brec_find(&fd);
	if (err != -ENOENT) {
		/* panic? */
		if (!err)
			err = -EEXIST;
		goto err1;
	}
	err = hfs_brec_insert(&fd, &entry, entry_size);
	if (err)
		goto err1;

	dir->i_size++;
	dir->i_mtime = dir->i_ctime = current_time(dir);
	mark_inode_dirty(dir);
	hfs_find_exit(&fd);
	return 0;

err1:
	hfs_cat_build_key(sb, fd.search_key, cnid, NULL);
	if (!hfs_brec_find(&fd))
		hfs_brec_remove(&fd);
err2:
	hfs_find_exit(&fd);
	return err;
}