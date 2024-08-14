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
struct vxfs_direct {int /*<<< orphan*/  d_ino; } ;
struct page {int dummy; } ;
struct inode {int /*<<< orphan*/  i_sb; } ;
struct dentry {int dummy; } ;
typedef  int /*<<< orphan*/  ino_t ;

/* Variables and functions */
 int /*<<< orphan*/  VXFS_SBI (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fs32_to_cpu (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kunmap (struct page*) ; 
 int /*<<< orphan*/  put_page (struct page*) ; 
 struct vxfs_direct* vxfs_find_entry (struct inode*,struct dentry*,struct page**) ; 

__attribute__((used)) static ino_t
vxfs_inode_by_name(struct inode *dip, struct dentry *dp)
{
	struct vxfs_direct		*de;
	struct page			*pp;
	ino_t				ino = 0;

	de = vxfs_find_entry(dip, dp, &pp);
	if (de) {
		ino = fs32_to_cpu(VXFS_SBI(dip->i_sb), de->d_ino);
		kunmap(pp);
		put_page(pp);
	}
	
	return (ino);
}