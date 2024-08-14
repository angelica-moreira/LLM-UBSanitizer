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
typedef  int /*<<< orphan*/  u64 ;
struct inode {int dummy; } ;
struct buffer_head {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ocfs2_read_virt_blocks (struct inode*,int /*<<< orphan*/ ,int,struct buffer_head**,int /*<<< orphan*/ ,int (*) (struct super_block*,struct buffer_head*)) ; 
 int /*<<< orphan*/  printk (char*) ; 

__attribute__((used)) static inline int ocfs2_read_virt_block(struct inode *inode, u64 v_block,
					struct buffer_head **bh,
					int (*validate)(struct super_block *sb,
							struct buffer_head *bh))
{
	int status = 0;

	if (bh == NULL) {
		printk("ocfs2: bh == NULL\n");
		status = -EINVAL;
		goto bail;
	}

	status = ocfs2_read_virt_blocks(inode, v_block, 1, bh, 0, validate);

bail:
	return status;
}