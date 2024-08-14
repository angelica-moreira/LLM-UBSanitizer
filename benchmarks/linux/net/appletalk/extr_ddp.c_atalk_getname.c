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
struct socket {struct sock* sk; } ;
struct TYPE_2__ {int /*<<< orphan*/  s_node; int /*<<< orphan*/  s_net; } ;
struct sockaddr_at {int /*<<< orphan*/  sat_family; int /*<<< orphan*/  sat_port; TYPE_1__ sat_addr; } ;
struct sockaddr {int dummy; } ;
struct sock {scalar_t__ sk_state; } ;
struct atalk_sock {int /*<<< orphan*/  src_port; int /*<<< orphan*/  src_node; int /*<<< orphan*/  src_net; int /*<<< orphan*/  dest_port; int /*<<< orphan*/  dest_node; int /*<<< orphan*/  dest_net; } ;
typedef  int /*<<< orphan*/  sat ;

/* Variables and functions */
 int /*<<< orphan*/  AF_APPLETALK ; 
 int ENOBUFS ; 
 int ENOTCONN ; 
 int /*<<< orphan*/  SOCK_ZAPPED ; 
 scalar_t__ TCP_ESTABLISHED ; 
 struct atalk_sock* at_sk (struct sock*) ; 
 scalar_t__ atalk_autobind (struct sock*) ; 
 int /*<<< orphan*/  lock_sock (struct sock*) ; 
 int /*<<< orphan*/  memcpy (struct sockaddr*,struct sockaddr_at*,int) ; 
 int /*<<< orphan*/  memset (struct sockaddr_at*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  release_sock (struct sock*) ; 
 scalar_t__ sock_flag (struct sock*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int atalk_getname(struct socket *sock, struct sockaddr *uaddr,
			 int peer)
{
	struct sockaddr_at sat;
	struct sock *sk = sock->sk;
	struct atalk_sock *at = at_sk(sk);
	int err;

	lock_sock(sk);
	err = -ENOBUFS;
	if (sock_flag(sk, SOCK_ZAPPED))
		if (atalk_autobind(sk) < 0)
			goto out;

	memset(&sat, 0, sizeof(sat));

	if (peer) {
		err = -ENOTCONN;
		if (sk->sk_state != TCP_ESTABLISHED)
			goto out;

		sat.sat_addr.s_net  = at->dest_net;
		sat.sat_addr.s_node = at->dest_node;
		sat.sat_port	    = at->dest_port;
	} else {
		sat.sat_addr.s_net  = at->src_net;
		sat.sat_addr.s_node = at->src_node;
		sat.sat_port	    = at->src_port;
	}

	sat.sat_family = AF_APPLETALK;
	memcpy(uaddr, &sat, sizeof(sat));
	err = sizeof(struct sockaddr_at);

out:
	release_sock(sk);
	return err;
}