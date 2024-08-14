#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct super_block {struct net* s_fs_info; } ;
struct notifier_block {int dummy; } ;
struct nfs_net {TYPE_1__* bl_device_pipe; } ;
struct net {int dummy; } ;
struct dentry {int dummy; } ;
struct TYPE_3__ {struct dentry* dentry; } ;

/* Variables and functions */
 int ENOTSUPP ; 
 int /*<<< orphan*/  IS_ERR (struct dentry*) ; 
 int PTR_ERR (struct dentry*) ; 
#define  RPC_PIPEFS_MOUNT 129 
#define  RPC_PIPEFS_UMOUNT 128 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 struct nfs_net* net_generic (struct net*,int /*<<< orphan*/ ) ; 
 struct dentry* nfs4blocklayout_register_sb (struct super_block*,TYPE_1__*) ; 
 int /*<<< orphan*/  nfs4blocklayout_unregister_sb (struct super_block*,TYPE_1__*) ; 
 int /*<<< orphan*/  nfs_net_id ; 
 int /*<<< orphan*/  try_module_get (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rpc_pipefs_event(struct notifier_block *nb, unsigned long event,
			   void *ptr)
{
	struct super_block *sb = ptr;
	struct net *net = sb->s_fs_info;
	struct nfs_net *nn = net_generic(net, nfs_net_id);
	struct dentry *dentry;
	int ret = 0;

	if (!try_module_get(THIS_MODULE))
		return 0;

	if (nn->bl_device_pipe == NULL) {
		module_put(THIS_MODULE);
		return 0;
	}

	switch (event) {
	case RPC_PIPEFS_MOUNT:
		dentry = nfs4blocklayout_register_sb(sb, nn->bl_device_pipe);
		if (IS_ERR(dentry)) {
			ret = PTR_ERR(dentry);
			break;
		}
		nn->bl_device_pipe->dentry = dentry;
		break;
	case RPC_PIPEFS_UMOUNT:
		if (nn->bl_device_pipe->dentry)
			nfs4blocklayout_unregister_sb(sb, nn->bl_device_pipe);
		break;
	default:
		ret = -ENOTSUPP;
		break;
	}
	module_put(THIS_MODULE);
	return ret;
}