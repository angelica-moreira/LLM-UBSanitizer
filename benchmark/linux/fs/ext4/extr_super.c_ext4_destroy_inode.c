#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct inode {int /*<<< orphan*/  i_ino; int /*<<< orphan*/  i_sb; } ;
struct ext4_inode_info {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  i_orphan; } ;

/* Variables and functions */
 int /*<<< orphan*/  DUMP_PREFIX_ADDRESS ; 
 TYPE_1__* EXT4_I (struct inode*) ; 
 int /*<<< orphan*/  KERN_ERR ; 
 int /*<<< orphan*/  KERN_INFO ; 
 int /*<<< orphan*/  dump_stack () ; 
 int /*<<< orphan*/  ext4_msg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  list_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  print_hex_dump (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int,int,TYPE_1__*,int,int) ; 

__attribute__((used)) static void ext4_destroy_inode(struct inode *inode)
{
	if (!list_empty(&(EXT4_I(inode)->i_orphan))) {
		ext4_msg(inode->i_sb, KERN_ERR,
			 "Inode %lu (%p): orphan list check failed!",
			 inode->i_ino, EXT4_I(inode));
		print_hex_dump(KERN_INFO, "", DUMP_PREFIX_ADDRESS, 16, 4,
				EXT4_I(inode), sizeof(struct ext4_inode_info),
				true);
		dump_stack();
	}
}