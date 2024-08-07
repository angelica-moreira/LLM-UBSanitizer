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
struct treepath {int dummy; } ;
struct tree_balance {int /*<<< orphan*/  key; } ;
struct super_block {int dummy; } ;
struct reiserfs_transaction_handle {int /*<<< orphan*/  t_super; int /*<<< orphan*/  t_trans_id; } ;
struct inode {int /*<<< orphan*/  i_uid; struct super_block* i_sb; } ;
struct cpu_key {int /*<<< orphan*/  on_disk_key; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int CARRY_ON ; 
 int EEXIST ; 
 int EIO ; 
 int ENOSPC ; 
 int IO_ERROR ; 
 int /*<<< orphan*/  M_PASTE ; 
 int NO_DISK_SPACE ; 
 int POSITION_FOUND ; 
 int /*<<< orphan*/  PROC_INFO_INC (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REISERFS_DEBUG_CODE ; 
 int REPEAT_SEARCH ; 
 int /*<<< orphan*/  check_research_for_paste (struct treepath*,struct cpu_key const*) ; 
 int /*<<< orphan*/  do_balance (struct tree_balance*,int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ) ; 
 int dquot_alloc_space_nodirty (struct inode*,int) ; 
 int /*<<< orphan*/  dquot_free_space_nodirty (struct inode*,int) ; 
 int fix_nodes (int /*<<< orphan*/ ,struct tree_balance*,int /*<<< orphan*/ *,char const*) ; 
 scalar_t__ fs_changed (int,struct super_block*) ; 
 int get_generation (struct super_block*) ; 
 int /*<<< orphan*/  init_tb_struct (struct reiserfs_transaction_handle*,struct tree_balance*,int /*<<< orphan*/ ,struct treepath*,int) ; 
 int /*<<< orphan*/  key2type (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  paste_into_item_restarted ; 
 int /*<<< orphan*/  pathrelse (struct treepath*) ; 
 int /*<<< orphan*/  reiserfs_debug (struct super_block*,int /*<<< orphan*/ ,char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  reiserfs_warning (struct super_block*,char*,char*,struct cpu_key const*) ; 
 int /*<<< orphan*/  reiserfs_write_lock_nested (struct super_block*,int) ; 
 int reiserfs_write_unlock_nested (struct super_block*) ; 
 int search_for_position_by_key (int /*<<< orphan*/ ,struct cpu_key const*,struct treepath*) ; 
 int /*<<< orphan*/  unfix_nodes (struct tree_balance*) ; 

int reiserfs_paste_into_item(struct reiserfs_transaction_handle *th,
			     /* Path to the pasted item. */
			     struct treepath *search_path,
			     /* Key to search for the needed item. */
			     const struct cpu_key *key,
			     /* Inode item belongs to */
			     struct inode *inode,
			     /* Pointer to the bytes to paste. */
			     const char *body,
			     /* Size of pasted bytes. */
			     int pasted_size)
{
	struct super_block *sb = inode->i_sb;
	struct tree_balance s_paste_balance;
	int retval;
	int fs_gen;
	int depth;

	BUG_ON(!th->t_trans_id);

	fs_gen = get_generation(inode->i_sb);

#ifdef REISERQUOTA_DEBUG
	reiserfs_debug(inode->i_sb, REISERFS_DEBUG_CODE,
		       "reiserquota paste_into_item(): allocating %u id=%u type=%c",
		       pasted_size, inode->i_uid,
		       key2type(&key->on_disk_key));
#endif

	depth = reiserfs_write_unlock_nested(sb);
	retval = dquot_alloc_space_nodirty(inode, pasted_size);
	reiserfs_write_lock_nested(sb, depth);
	if (retval) {
		pathrelse(search_path);
		return retval;
	}
	init_tb_struct(th, &s_paste_balance, th->t_super, search_path,
		       pasted_size);
#ifdef DISPLACE_NEW_PACKING_LOCALITIES
	s_paste_balance.key = key->on_disk_key;
#endif

	/* DQUOT_* can schedule, must check before the fix_nodes */
	if (fs_changed(fs_gen, inode->i_sb)) {
		goto search_again;
	}

	while ((retval =
		fix_nodes(M_PASTE, &s_paste_balance, NULL,
			  body)) == REPEAT_SEARCH) {
search_again:
		/* file system changed while we were in the fix_nodes */
		PROC_INFO_INC(th->t_super, paste_into_item_restarted);
		retval =
		    search_for_position_by_key(th->t_super, key,
					       search_path);
		if (retval == IO_ERROR) {
			retval = -EIO;
			goto error_out;
		}
		if (retval == POSITION_FOUND) {
			reiserfs_warning(inode->i_sb, "PAP-5710",
					 "entry or pasted byte (%K) exists",
					 key);
			retval = -EEXIST;
			goto error_out;
		}
#ifdef CONFIG_REISERFS_CHECK
		check_research_for_paste(search_path, key);
#endif
	}

	/*
	 * Perform balancing after all resources are collected by fix_nodes,
	 * and accessing them will not risk triggering schedule.
	 */
	if (retval == CARRY_ON) {
		do_balance(&s_paste_balance, NULL /*ih */ , body, M_PASTE);
		return 0;
	}
	retval = (retval == NO_DISK_SPACE) ? -ENOSPC : -EIO;
error_out:
	/* this also releases the path */
	unfix_nodes(&s_paste_balance);
#ifdef REISERQUOTA_DEBUG
	reiserfs_debug(inode->i_sb, REISERFS_DEBUG_CODE,
		       "reiserquota paste_into_item(): freeing %u id=%u type=%c",
		       pasted_size, inode->i_uid,
		       key2type(&key->on_disk_key));
#endif
	depth = reiserfs_write_unlock_nested(sb);
	dquot_free_space_nodirty(inode, pasted_size);
	reiserfs_write_lock_nested(sb, depth);
	return retval;
}