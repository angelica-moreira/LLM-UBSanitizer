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
struct privcmd_data {int dummy; } ;
struct inode {int dummy; } ;
struct file {struct privcmd_data* private_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct privcmd_data*) ; 

__attribute__((used)) static int privcmd_release(struct inode *ino, struct file *file)
{
	struct privcmd_data *data = file->private_data;

	kfree(data);
	return 0;
}