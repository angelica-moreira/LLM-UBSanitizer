#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_5__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
struct page {scalar_t__ index; } ;
struct ocfs2_write_ctxt {int w_num_pages; unsigned int w_target_from; unsigned int w_target_to; scalar_t__ w_type; TYPE_1__* w_di_bh; int /*<<< orphan*/  w_dealloc; struct page* w_target_page; struct page** w_pages; int /*<<< orphan*/  w_unwritten_list; int /*<<< orphan*/ * w_handle; } ;
struct ocfs2_super {int dummy; } ;
struct ocfs2_dinode {int /*<<< orphan*/  i_ctime_nsec; int /*<<< orphan*/  i_mtime_nsec; void* i_ctime; void* i_mtime; void* i_size; } ;
struct TYPE_7__ {int /*<<< orphan*/  tv_nsec; int /*<<< orphan*/  tv_sec; } ;
struct inode {TYPE_3__ i_mtime; TYPE_3__ i_ctime; int /*<<< orphan*/  i_blocks; int /*<<< orphan*/  i_sb; } ;
struct address_space {struct inode* host; } ;
typedef  int loff_t ;
typedef  int /*<<< orphan*/  handle_t ;
struct TYPE_8__ {int ip_dyn_features; } ;
struct TYPE_6__ {scalar_t__ b_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  INODE_CACHE (struct inode*) ; 
 TYPE_5__* OCFS2_I (struct inode*) ; 
 int OCFS2_INLINE_DATA_FL ; 
 int /*<<< orphan*/  OCFS2_JOURNAL_ACCESS_WRITE ; 
 struct ocfs2_super* OCFS2_SB (int /*<<< orphan*/ ) ; 
 scalar_t__ OCFS2_WRITE_DIRECT ; 
 int PAGE_SHIFT ; 
 int PAGE_SIZE ; 
 int /*<<< orphan*/  PageUptodate (struct page*) ; 
 int /*<<< orphan*/  block_commit_write (struct page*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  brelse (TYPE_1__*) ; 
 int /*<<< orphan*/  cpu_to_le32 (int /*<<< orphan*/ ) ; 
 void* cpu_to_le64 (int /*<<< orphan*/ ) ; 
 TYPE_3__ current_time (struct inode*) ; 
 int /*<<< orphan*/  flush_dcache_page (struct page*) ; 
 int i_size_read (struct inode*) ; 
 int /*<<< orphan*/  i_size_write (struct inode*,int) ; 
 int /*<<< orphan*/  kfree (struct ocfs2_write_ctxt*) ; 
 int /*<<< orphan*/  list_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mark_inode_dirty (struct inode*) ; 
 int /*<<< orphan*/  mlog_errno (int) ; 
 int /*<<< orphan*/  ocfs2_commit_trans (struct ocfs2_super*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ocfs2_inode_sector_count (struct inode*) ; 
 int /*<<< orphan*/  ocfs2_jbd2_inode_add_write (int /*<<< orphan*/ *,struct inode*,int,int) ; 
 int ocfs2_journal_access_di (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ocfs2_journal_dirty (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  ocfs2_run_deallocs (struct ocfs2_super*,int /*<<< orphan*/ *) ; 
 scalar_t__ ocfs2_should_order_data (struct inode*) ; 
 int /*<<< orphan*/  ocfs2_unlock_pages (struct ocfs2_write_ctxt*) ; 
 int /*<<< orphan*/  ocfs2_update_inode_fsync_trans (int /*<<< orphan*/ *,struct inode*,int) ; 
 int /*<<< orphan*/  ocfs2_write_end_inline (struct inode*,int,unsigned int,unsigned int*,struct ocfs2_dinode*,struct ocfs2_write_ctxt*) ; 
 int /*<<< orphan*/  ocfs2_zero_new_buffers (struct page*,unsigned int,unsigned int) ; 
 scalar_t__ page_has_buffers (struct page*) ; 
 scalar_t__ unlikely (int) ; 

int ocfs2_write_end_nolock(struct address_space *mapping,
			   loff_t pos, unsigned len, unsigned copied, void *fsdata)
{
	int i, ret;
	unsigned from, to, start = pos & (PAGE_SIZE - 1);
	struct inode *inode = mapping->host;
	struct ocfs2_super *osb = OCFS2_SB(inode->i_sb);
	struct ocfs2_write_ctxt *wc = fsdata;
	struct ocfs2_dinode *di = (struct ocfs2_dinode *)wc->w_di_bh->b_data;
	handle_t *handle = wc->w_handle;
	struct page *tmppage;

	BUG_ON(!list_empty(&wc->w_unwritten_list));

	if (handle) {
		ret = ocfs2_journal_access_di(handle, INODE_CACHE(inode),
				wc->w_di_bh, OCFS2_JOURNAL_ACCESS_WRITE);
		if (ret) {
			copied = ret;
			mlog_errno(ret);
			goto out;
		}
	}

	if (OCFS2_I(inode)->ip_dyn_features & OCFS2_INLINE_DATA_FL) {
		ocfs2_write_end_inline(inode, pos, len, &copied, di, wc);
		goto out_write_size;
	}

	if (unlikely(copied < len) && wc->w_target_page) {
		if (!PageUptodate(wc->w_target_page))
			copied = 0;

		ocfs2_zero_new_buffers(wc->w_target_page, start+copied,
				       start+len);
	}
	if (wc->w_target_page)
		flush_dcache_page(wc->w_target_page);

	for(i = 0; i < wc->w_num_pages; i++) {
		tmppage = wc->w_pages[i];

		/* This is the direct io target page. */
		if (tmppage == NULL)
			continue;

		if (tmppage == wc->w_target_page) {
			from = wc->w_target_from;
			to = wc->w_target_to;

			BUG_ON(from > PAGE_SIZE ||
			       to > PAGE_SIZE ||
			       to < from);
		} else {
			/*
			 * Pages adjacent to the target (if any) imply
			 * a hole-filling write in which case we want
			 * to flush their entire range.
			 */
			from = 0;
			to = PAGE_SIZE;
		}

		if (page_has_buffers(tmppage)) {
			if (handle && ocfs2_should_order_data(inode)) {
				loff_t start_byte =
					((loff_t)tmppage->index << PAGE_SHIFT) +
					from;
				loff_t length = to - from;
				ocfs2_jbd2_inode_add_write(handle, inode,
							   start_byte, length);
			}
			block_commit_write(tmppage, from, to);
		}
	}

out_write_size:
	/* Direct io do not update i_size here. */
	if (wc->w_type != OCFS2_WRITE_DIRECT) {
		pos += copied;
		if (pos > i_size_read(inode)) {
			i_size_write(inode, pos);
			mark_inode_dirty(inode);
		}
		inode->i_blocks = ocfs2_inode_sector_count(inode);
		di->i_size = cpu_to_le64((u64)i_size_read(inode));
		inode->i_mtime = inode->i_ctime = current_time(inode);
		di->i_mtime = di->i_ctime = cpu_to_le64(inode->i_mtime.tv_sec);
		di->i_mtime_nsec = di->i_ctime_nsec = cpu_to_le32(inode->i_mtime.tv_nsec);
		if (handle)
			ocfs2_update_inode_fsync_trans(handle, inode, 1);
	}
	if (handle)
		ocfs2_journal_dirty(handle, wc->w_di_bh);

out:
	/* unlock pages before dealloc since it needs acquiring j_trans_barrier
	 * lock, or it will cause a deadlock since journal commit threads holds
	 * this lock and will ask for the page lock when flushing the data.
	 * put it here to preserve the unlock order.
	 */
	ocfs2_unlock_pages(wc);

	if (handle)
		ocfs2_commit_trans(osb, handle);

	ocfs2_run_deallocs(osb, &wc->w_dealloc);

	brelse(wc->w_di_bh);
	kfree(wc);

	return copied;
}