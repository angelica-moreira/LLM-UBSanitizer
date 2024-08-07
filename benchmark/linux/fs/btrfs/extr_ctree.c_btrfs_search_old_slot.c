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
typedef  int u8 ;
typedef  int /*<<< orphan*/  u64 ;
struct extent_buffer {int dummy; } ;
struct btrfs_root {struct btrfs_fs_info* fs_info; } ;
struct btrfs_path {int lowest_level; int* slots; int /*<<< orphan*/  leave_spinning; struct extent_buffer** nodes; void** locks; scalar_t__ search_commit_root; } ;
struct btrfs_key {int dummy; } ;
struct btrfs_fs_info {int dummy; } ;

/* Variables and functions */
 void* BTRFS_READ_LOCK ; 
 int /*<<< orphan*/  BUG_ON (int /*<<< orphan*/ ) ; 
 int EAGAIN ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  WARN_ON (int /*<<< orphan*/ ) ; 
 int btrfs_header_level (struct extent_buffer*) ; 
 int /*<<< orphan*/  btrfs_release_path (struct btrfs_path*) ; 
 int btrfs_search_slot (int /*<<< orphan*/ *,struct btrfs_root*,struct btrfs_key const*,struct btrfs_path*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  btrfs_set_path_blocking (struct btrfs_path*) ; 
 int /*<<< orphan*/  btrfs_tree_read_lock (struct extent_buffer*) ; 
 int /*<<< orphan*/  btrfs_tree_read_lock_atomic (struct extent_buffer*) ; 
 int /*<<< orphan*/  btrfs_unlock_up_safe (struct btrfs_path*,int) ; 
 struct extent_buffer* get_old_root (struct btrfs_root*,int /*<<< orphan*/ ) ; 
 int key_search (struct extent_buffer*,struct btrfs_key const*,int,int*,int*) ; 
 int read_block_for_search (struct btrfs_root*,struct btrfs_path*,struct extent_buffer**,int,int,struct btrfs_key const*) ; 
 struct extent_buffer* tree_mod_log_rewind (struct btrfs_fs_info*,struct btrfs_path*,struct extent_buffer*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  unlock_up (struct btrfs_path*,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int btrfs_search_old_slot(struct btrfs_root *root, const struct btrfs_key *key,
			  struct btrfs_path *p, u64 time_seq)
{
	struct btrfs_fs_info *fs_info = root->fs_info;
	struct extent_buffer *b;
	int slot;
	int ret;
	int err;
	int level;
	int lowest_unlock = 1;
	u8 lowest_level = 0;
	int prev_cmp = -1;

	lowest_level = p->lowest_level;
	WARN_ON(p->nodes[0] != NULL);

	if (p->search_commit_root) {
		BUG_ON(time_seq);
		return btrfs_search_slot(NULL, root, key, p, 0, 0);
	}

again:
	b = get_old_root(root, time_seq);
	if (!b) {
		ret = -EIO;
		goto done;
	}
	level = btrfs_header_level(b);
	p->locks[level] = BTRFS_READ_LOCK;

	while (b) {
		level = btrfs_header_level(b);
		p->nodes[level] = b;

		/*
		 * we have a lock on b and as long as we aren't changing
		 * the tree, there is no way to for the items in b to change.
		 * It is safe to drop the lock on our parent before we
		 * go through the expensive btree search on b.
		 */
		btrfs_unlock_up_safe(p, level + 1);

		/*
		 * Since we can unwind ebs we want to do a real search every
		 * time.
		 */
		prev_cmp = -1;
		ret = key_search(b, key, level, &prev_cmp, &slot);
		if (ret < 0)
			goto done;

		if (level != 0) {
			int dec = 0;
			if (ret && slot > 0) {
				dec = 1;
				slot -= 1;
			}
			p->slots[level] = slot;
			unlock_up(p, level, lowest_unlock, 0, NULL);

			if (level == lowest_level) {
				if (dec)
					p->slots[level]++;
				goto done;
			}

			err = read_block_for_search(root, p, &b, level,
						    slot, key);
			if (err == -EAGAIN)
				goto again;
			if (err) {
				ret = err;
				goto done;
			}

			level = btrfs_header_level(b);
			if (!btrfs_tree_read_lock_atomic(b)) {
				btrfs_set_path_blocking(p);
				btrfs_tree_read_lock(b);
			}
			b = tree_mod_log_rewind(fs_info, p, b, time_seq);
			if (!b) {
				ret = -ENOMEM;
				goto done;
			}
			p->locks[level] = BTRFS_READ_LOCK;
			p->nodes[level] = b;
		} else {
			p->slots[level] = slot;
			unlock_up(p, level, lowest_unlock, 0, NULL);
			goto done;
		}
	}
	ret = 1;
done:
	if (!p->leave_spinning)
		btrfs_set_path_blocking(p);
	if (ret < 0)
		btrfs_release_path(p);

	return ret;
}