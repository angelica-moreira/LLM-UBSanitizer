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
struct seq_file {int dummy; } ;
struct inode {int dummy; } ;
struct file {struct seq_file* private_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  put_net (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  seq_file_net (struct seq_file*) ; 
 int /*<<< orphan*/  seq_release_private (struct inode*,struct file*) ; 

__attribute__((used)) static int seq_release_net(struct inode *ino, struct file *f)
{
	struct seq_file *seq = f->private_data;

	put_net(seq_file_net(seq));
	seq_release_private(ino, f);
	return 0;
}