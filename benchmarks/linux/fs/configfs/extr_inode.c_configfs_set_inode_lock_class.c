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
struct configfs_dirent {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static void configfs_set_inode_lock_class(struct configfs_dirent *sd,
					  struct inode *inode)
{
}