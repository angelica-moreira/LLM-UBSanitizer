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
struct file_system_type {int dummy; } ;
struct dentry {int dummy; } ;

/* Variables and functions */
 struct dentry* mount_bdev (struct file_system_type*,int,char const*,void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vfat_fill_super ; 

__attribute__((used)) static struct dentry *vfat_mount(struct file_system_type *fs_type,
		       int flags, const char *dev_name,
		       void *data)
{
	return mount_bdev(fs_type, flags, dev_name, data, vfat_fill_super);
}