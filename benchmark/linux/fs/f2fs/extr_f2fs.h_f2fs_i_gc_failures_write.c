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
struct inode {int dummy; } ;
struct TYPE_2__ {unsigned int* i_gc_failures; } ;

/* Variables and functions */
 TYPE_1__* F2FS_I (struct inode*) ; 
 size_t GC_FAILURE_PIN ; 
 int /*<<< orphan*/  f2fs_mark_inode_dirty_sync (struct inode*,int) ; 

__attribute__((used)) static inline void f2fs_i_gc_failures_write(struct inode *inode,
					unsigned int count)
{
	F2FS_I(inode)->i_gc_failures[GC_FAILURE_PIN] = count;
	f2fs_mark_inode_dirty_sync(inode, true);
}