#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct key {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  rtt; } ;
struct afs_server {TYPE_2__ probe; int /*<<< orphan*/  probe_outstanding; int /*<<< orphan*/  fs_lock; int /*<<< orphan*/  addresses; int /*<<< orphan*/  uuid; } ;
struct afs_net {int dummy; } ;
struct afs_error {int dummy; } ;
struct afs_call {int dummy; } ;
struct afs_addr_cursor {scalar_t__ index; int /*<<< orphan*/  abort_code; TYPE_1__* alist; } ;
struct TYPE_3__ {scalar_t__ nr_addrs; } ;

/* Variables and functions */
 int /*<<< orphan*/  IS_ERR (struct afs_call*) ; 
 int /*<<< orphan*/  PTR_ERR (struct afs_call*) ; 
 int /*<<< orphan*/  UINT_MAX ; 
 int /*<<< orphan*/  _enter (char*,int /*<<< orphan*/ *) ; 
 struct afs_call* afs_fs_get_capabilities (struct afs_net*,struct afs_server*,struct afs_addr_cursor*,struct key*,unsigned int) ; 
 int /*<<< orphan*/  afs_fs_probe_done (struct afs_server*) ; 
 int /*<<< orphan*/  afs_prioritise_error (struct afs_error*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  afs_put_call (struct afs_call*) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  lockdep_is_held (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 TYPE_1__* rcu_dereference_protected (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  read_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  read_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int afs_do_probe_fileserver(struct afs_net *net,
				   struct afs_server *server,
				   struct key *key,
				   unsigned int server_index,
				   struct afs_error *_e)
{
	struct afs_addr_cursor ac = {
		.index = 0,
	};
	struct afs_call *call;
	bool in_progress = false;

	_enter("%pU", &server->uuid);

	read_lock(&server->fs_lock);
	ac.alist = rcu_dereference_protected(server->addresses,
					     lockdep_is_held(&server->fs_lock));
	read_unlock(&server->fs_lock);

	atomic_set(&server->probe_outstanding, ac.alist->nr_addrs);
	memset(&server->probe, 0, sizeof(server->probe));
	server->probe.rtt = UINT_MAX;

	for (ac.index = 0; ac.index < ac.alist->nr_addrs; ac.index++) {
		call = afs_fs_get_capabilities(net, server, &ac, key, server_index);
		if (!IS_ERR(call)) {
			afs_put_call(call);
			in_progress = true;
		} else {
			afs_prioritise_error(_e, PTR_ERR(call), ac.abort_code);
		}
	}

	if (!in_progress)
		afs_fs_probe_done(server);
	return in_progress;
}