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
struct super_block {int dummy; } ;
struct fuse_conn {int /*<<< orphan*/  entry; } ;

/* Variables and functions */
 int /*<<< orphan*/  fuse_conn_put (struct fuse_conn*) ; 
 int /*<<< orphan*/  fuse_ctl_remove_conn (struct fuse_conn*) ; 
 int /*<<< orphan*/  fuse_mutex ; 
 struct fuse_conn* get_fuse_conn_super (struct super_block*) ; 
 int /*<<< orphan*/  list_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void fuse_put_super(struct super_block *sb)
{
	struct fuse_conn *fc = get_fuse_conn_super(sb);

	mutex_lock(&fuse_mutex);
	list_del(&fc->entry);
	fuse_ctl_remove_conn(fc);
	mutex_unlock(&fuse_mutex);

	fuse_conn_put(fc);
}