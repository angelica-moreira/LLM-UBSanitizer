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
struct seq_file {int /*<<< orphan*/  private; } ;
struct inode {int /*<<< orphan*/  i_private; } ;
struct file {struct seq_file* private_data; } ;

/* Variables and functions */
 int seq_open (struct file*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sge_qinfo_seq_ops ; 

__attribute__((used)) static int sge_qinfo_open(struct inode *inode, struct file *file)
{
	int res = seq_open(file, &sge_qinfo_seq_ops);

	if (!res) {
		struct seq_file *seq = file->private_data;
		seq->private = inode->i_private;
	}
	return res;
}