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
struct sock {int dummy; } ;
struct x25_sock {struct sock sk; } ;
struct timer_list {int dummy; } ;
struct TYPE_2__ {scalar_t__ state; } ;

/* Variables and functions */
 scalar_t__ X25_STATE_3 ; 
 int /*<<< orphan*/  bh_lock_sock (struct sock*) ; 
 int /*<<< orphan*/  bh_unlock_sock (struct sock*) ; 
 struct x25_sock* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 scalar_t__ sock_owned_by_user (struct sock*) ; 
 int /*<<< orphan*/  timer ; 
 struct x25_sock* x25 ; 
 int /*<<< orphan*/  x25_do_timer_expiry (struct sock*) ; 
 TYPE_1__* x25_sk (struct sock*) ; 
 int /*<<< orphan*/  x25_start_t2timer (struct sock*) ; 

__attribute__((used)) static void x25_timer_expiry(struct timer_list *t)
{
	struct x25_sock *x25 = from_timer(x25, t, timer);
	struct sock *sk = &x25->sk;

	bh_lock_sock(sk);
	if (sock_owned_by_user(sk)) { /* can currently only occur in state 3 */
		if (x25_sk(sk)->state == X25_STATE_3)
			x25_start_t2timer(sk);
	} else
		x25_do_timer_expiry(sk);
	bh_unlock_sock(sk);
}