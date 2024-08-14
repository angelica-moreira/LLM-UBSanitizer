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
struct xensyms {int /*<<< orphan*/  name; } ;
struct seq_file {scalar_t__ private; } ;
struct inode {int dummy; } ;
struct file {struct seq_file* private_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 
 int seq_release_private (struct inode*,struct file*) ; 

__attribute__((used)) static int xensyms_release(struct inode *inode, struct file *file)
{
	struct seq_file *m = file->private_data;
	struct xensyms *xs = (struct xensyms *)m->private;

	kfree(xs->name);
	return seq_release_private(inode, file);
}