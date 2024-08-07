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
struct sock {TYPE_1__* sk_socket; } ;
struct dn_scp {scalar_t__ state; int /*<<< orphan*/  segsize_loc; } ;
typedef  int /*<<< orphan*/  gfp_t ;
struct TYPE_2__ {int /*<<< orphan*/  state; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEFINE_WAIT (int /*<<< orphan*/ ) ; 
 scalar_t__ DN_CC ; 
 scalar_t__ DN_CR ; 
 scalar_t__ DN_RUN ; 
 struct dn_scp* DN_SK (struct sock*) ; 
 int EAGAIN ; 
 int EINVAL ; 
 int /*<<< orphan*/  SS_CONNECTED ; 
 int /*<<< orphan*/  SS_UNCONNECTED ; 
 int /*<<< orphan*/  TASK_INTERRUPTIBLE ; 
 int /*<<< orphan*/  __sk_dst_get (struct sock*) ; 
 int /*<<< orphan*/  current ; 
 int /*<<< orphan*/  dn_send_conn_conf (struct sock*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dst_metric_advmss (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  finish_wait (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lock_sock (struct sock*) ; 
 int /*<<< orphan*/  prepare_to_wait (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  release_sock (struct sock*) ; 
 long schedule_timeout (long) ; 
 scalar_t__ signal_pending (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sk_sleep (struct sock*) ; 
 int sock_error (struct sock*) ; 
 int sock_intr_errno (long) ; 
 int /*<<< orphan*/  wait ; 

__attribute__((used)) static int dn_confirm_accept(struct sock *sk, long *timeo, gfp_t allocation)
{
	struct dn_scp *scp = DN_SK(sk);
	DEFINE_WAIT(wait);
	int err;

	if (scp->state != DN_CR)
		return -EINVAL;

	scp->state = DN_CC;
	scp->segsize_loc = dst_metric_advmss(__sk_dst_get(sk));
	dn_send_conn_conf(sk, allocation);

	prepare_to_wait(sk_sleep(sk), &wait, TASK_INTERRUPTIBLE);
	for(;;) {
		release_sock(sk);
		if (scp->state == DN_CC)
			*timeo = schedule_timeout(*timeo);
		lock_sock(sk);
		err = 0;
		if (scp->state == DN_RUN)
			break;
		err = sock_error(sk);
		if (err)
			break;
		err = sock_intr_errno(*timeo);
		if (signal_pending(current))
			break;
		err = -EAGAIN;
		if (!*timeo)
			break;
		prepare_to_wait(sk_sleep(sk), &wait, TASK_INTERRUPTIBLE);
	}
	finish_wait(sk_sleep(sk), &wait);
	if (err == 0) {
		sk->sk_socket->state = SS_CONNECTED;
	} else if (scp->state != DN_CC) {
		sk->sk_socket->state = SS_UNCONNECTED;
	}
	return err;
}