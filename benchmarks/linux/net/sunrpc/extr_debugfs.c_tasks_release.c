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
struct seq_file {struct rpc_clnt* private; } ;
struct rpc_clnt {int dummy; } ;
struct inode {int dummy; } ;
struct file {struct seq_file* private_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  rpc_release_client (struct rpc_clnt*) ; 
 int seq_release (struct inode*,struct file*) ; 

__attribute__((used)) static int
tasks_release(struct inode *inode, struct file *filp)
{
	struct seq_file *seq = filp->private_data;
	struct rpc_clnt *clnt = seq->private;

	rpc_release_client(clnt);
	return seq_release(inode, filp);
}