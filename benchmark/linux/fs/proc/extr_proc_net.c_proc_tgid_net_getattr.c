#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct path {int /*<<< orphan*/  dentry; } ;
struct net {TYPE_1__* proc_net; } ;
struct kstat {int /*<<< orphan*/  nlink; } ;
struct inode {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  nlink; } ;

/* Variables and functions */
 struct inode* d_inode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  generic_fillattr (struct inode*,struct kstat*) ; 
 struct net* get_proc_task_net (struct inode*) ; 
 int /*<<< orphan*/  put_net (struct net*) ; 

__attribute__((used)) static int proc_tgid_net_getattr(const struct path *path, struct kstat *stat,
				 u32 request_mask, unsigned int query_flags)
{
	struct inode *inode = d_inode(path->dentry);
	struct net *net;

	net = get_proc_task_net(inode);

	generic_fillattr(inode, stat);

	if (net != NULL) {
		stat->nlink = net->proc_net->nlink;
		put_net(net);
	}

	return 0;
}