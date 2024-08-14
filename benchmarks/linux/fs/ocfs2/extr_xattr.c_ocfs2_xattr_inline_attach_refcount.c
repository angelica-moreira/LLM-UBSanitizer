#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct ocfs2_xattr_value_buf {int /*<<< orphan*/  vb_access; struct buffer_head* vb_bh; } ;
struct ocfs2_xattr_header {int dummy; } ;
struct ocfs2_dinode {int /*<<< orphan*/  i_xattr_inline_size; } ;
struct ocfs2_caching_info {int dummy; } ;
struct ocfs2_cached_dealloc_ctxt {int dummy; } ;
struct inode {TYPE_1__* i_sb; } ;
struct buffer_head {scalar_t__ b_data; } ;
struct TYPE_2__ {scalar_t__ s_blocksize; } ;

/* Variables and functions */
 scalar_t__ le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ocfs2_journal_access_di ; 
 int ocfs2_xattr_attach_refcount_normal (struct inode*,struct ocfs2_xattr_value_buf*,struct ocfs2_xattr_header*,struct ocfs2_caching_info*,struct buffer_head*,struct ocfs2_cached_dealloc_ctxt*) ; 

__attribute__((used)) static int ocfs2_xattr_inline_attach_refcount(struct inode *inode,
				struct buffer_head *fe_bh,
				struct ocfs2_caching_info *ref_ci,
				struct buffer_head *ref_root_bh,
				struct ocfs2_cached_dealloc_ctxt *dealloc)
{
	struct ocfs2_dinode *di = (struct ocfs2_dinode *)fe_bh->b_data;
	struct ocfs2_xattr_header *header = (struct ocfs2_xattr_header *)
				(fe_bh->b_data + inode->i_sb->s_blocksize -
				le16_to_cpu(di->i_xattr_inline_size));
	struct ocfs2_xattr_value_buf vb = {
		.vb_bh = fe_bh,
		.vb_access = ocfs2_journal_access_di,
	};

	return ocfs2_xattr_attach_refcount_normal(inode, &vb, header,
						  ref_ci, ref_root_bh, dealloc);
}