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
 int EOPNOTSUPP ; 

__attribute__((used)) static inline int
ext2_xattr_set(struct inode *inode, int name_index, const char *name,
	       const void *value, size_t size, int flags)
{
	return -EOPNOTSUPP;
}