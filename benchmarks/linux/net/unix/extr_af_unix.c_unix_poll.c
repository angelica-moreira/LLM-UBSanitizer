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
struct socket {struct sock* sk; } ;
struct sock {int sk_shutdown; scalar_t__ sk_type; scalar_t__ sk_state; int /*<<< orphan*/  sk_receive_queue; scalar_t__ sk_err; } ;
struct file {int dummy; } ;
typedef  int /*<<< orphan*/  poll_table ;
typedef  int __poll_t ;

/* Variables and functions */
 int EPOLLERR ; 
 int EPOLLHUP ; 
 int EPOLLIN ; 
 int EPOLLOUT ; 
 int EPOLLRDHUP ; 
 int EPOLLRDNORM ; 
 int EPOLLWRBAND ; 
 int EPOLLWRNORM ; 
 int RCV_SHUTDOWN ; 
 int SHUTDOWN_MASK ; 
 scalar_t__ SOCK_SEQPACKET ; 
 scalar_t__ SOCK_STREAM ; 
 scalar_t__ TCP_CLOSE ; 
 int /*<<< orphan*/  skb_queue_empty_lockless (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sock_poll_wait (struct file*,struct socket*,int /*<<< orphan*/ *) ; 
 scalar_t__ unix_writable (struct sock*) ; 

__attribute__((used)) static __poll_t unix_poll(struct file *file, struct socket *sock, poll_table *wait)
{
	struct sock *sk = sock->sk;
	__poll_t mask;

	sock_poll_wait(file, sock, wait);
	mask = 0;

	/* exceptional events? */
	if (sk->sk_err)
		mask |= EPOLLERR;
	if (sk->sk_shutdown == SHUTDOWN_MASK)
		mask |= EPOLLHUP;
	if (sk->sk_shutdown & RCV_SHUTDOWN)
		mask |= EPOLLRDHUP | EPOLLIN | EPOLLRDNORM;

	/* readable? */
	if (!skb_queue_empty_lockless(&sk->sk_receive_queue))
		mask |= EPOLLIN | EPOLLRDNORM;

	/* Connection-based need to check for termination and startup */
	if ((sk->sk_type == SOCK_STREAM || sk->sk_type == SOCK_SEQPACKET) &&
	    sk->sk_state == TCP_CLOSE)
		mask |= EPOLLHUP;

	/*
	 * we set writable also when the other side has shut down the
	 * connection. This prevents stuck sockets.
	 */
	if (unix_writable(sk))
		mask |= EPOLLOUT | EPOLLWRNORM | EPOLLWRBAND;

	return mask;
}