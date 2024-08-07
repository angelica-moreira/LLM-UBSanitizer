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
struct inode {int dummy; } ;
struct dentry {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  __putname (char*) ; 
 char* dentry_name (struct dentry*) ; 
 int do_mkdir (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int hostfs_mkdir(struct inode *ino, struct dentry *dentry, umode_t mode)
{
	char *file;
	int err;

	if ((file = dentry_name(dentry)) == NULL)
		return -ENOMEM;
	err = do_mkdir(file, mode);
	__putname(file);
	return err;
}