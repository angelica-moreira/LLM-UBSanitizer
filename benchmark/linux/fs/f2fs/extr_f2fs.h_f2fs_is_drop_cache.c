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
struct inode {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  FI_DROP_CACHE ; 
 int is_inode_flag_set (struct inode*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool f2fs_is_drop_cache(struct inode *inode)
{
	return is_inode_flag_set(inode, FI_DROP_CACHE);
}