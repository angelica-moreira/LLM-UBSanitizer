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
typedef  int /*<<< orphan*/  umode_t ;
struct file_operations {int dummy; } ;
struct dentry {int dummy; } ;

/* Variables and functions */
 struct dentry* aafs_create (char const*,int /*<<< orphan*/ ,struct dentry*,void*,int /*<<< orphan*/ *,struct file_operations const*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static struct dentry *aafs_create_file(const char *name, umode_t mode,
				       struct dentry *parent, void *data,
				       const struct file_operations *fops)
{
	return aafs_create(name, mode, parent, data, NULL, fops, NULL);
}