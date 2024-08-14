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
struct task_struct {int dummy; } ;
struct TYPE_2__ {scalar_t__ len; int /*<<< orphan*/ * response; } ;
struct TCP_Server_Info {scalar_t__ srv_count; int /*<<< orphan*/  tsk; TYPE_1__ session_key; int /*<<< orphan*/  tcpStatus; int /*<<< orphan*/  reconnect; int /*<<< orphan*/  echo; int /*<<< orphan*/  tcp_ses_list; } ;

/* Variables and functions */
 int /*<<< orphan*/  CifsExiting ; 
 int /*<<< orphan*/  GlobalMid_Lock ; 
 int /*<<< orphan*/  SIGKILL ; 
 int /*<<< orphan*/  cancel_delayed_work (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cancel_delayed_work_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cifs_crypto_secmech_release (struct TCP_Server_Info*) ; 
 int /*<<< orphan*/  cifs_fscache_release_client_cookie (struct TCP_Server_Info*) ; 
 int /*<<< orphan*/  cifs_net_ns (struct TCP_Server_Info*) ; 
 int /*<<< orphan*/  cifs_tcp_ses_lock ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_del_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  put_net (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  send_sig (int /*<<< orphan*/ ,struct task_struct*,int) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 struct task_struct* xchg (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

void
cifs_put_tcp_session(struct TCP_Server_Info *server, int from_reconnect)
{
	struct task_struct *task;

	spin_lock(&cifs_tcp_ses_lock);
	if (--server->srv_count > 0) {
		spin_unlock(&cifs_tcp_ses_lock);
		return;
	}

	put_net(cifs_net_ns(server));

	list_del_init(&server->tcp_ses_list);
	spin_unlock(&cifs_tcp_ses_lock);

	cancel_delayed_work_sync(&server->echo);

	if (from_reconnect)
		/*
		 * Avoid deadlock here: reconnect work calls
		 * cifs_put_tcp_session() at its end. Need to be sure
		 * that reconnect work does nothing with server pointer after
		 * that step.
		 */
		cancel_delayed_work(&server->reconnect);
	else
		cancel_delayed_work_sync(&server->reconnect);

	spin_lock(&GlobalMid_Lock);
	server->tcpStatus = CifsExiting;
	spin_unlock(&GlobalMid_Lock);

	cifs_crypto_secmech_release(server);
	cifs_fscache_release_client_cookie(server);

	kfree(server->session_key.response);
	server->session_key.response = NULL;
	server->session_key.len = 0;

	task = xchg(&server->tsk, NULL);
	if (task)
		send_sig(SIGKILL, task, 1);
}