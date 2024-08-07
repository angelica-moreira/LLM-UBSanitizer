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
struct sock {int /*<<< orphan*/  sk_callback_lock; } ;
struct TYPE_2__ {int /*<<< orphan*/  strp; } ;
struct sk_psock {TYPE_1__ parser; } ;

/* Variables and functions */
 scalar_t__ likely (struct sk_psock*) ; 
 int /*<<< orphan*/  rcu_read_lock () ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 
 struct sk_psock* sk_psock (struct sock*) ; 
 int /*<<< orphan*/  strp_data_ready (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  write_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  write_unlock_bh (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void sk_psock_strp_data_ready(struct sock *sk)
{
	struct sk_psock *psock;

	rcu_read_lock();
	psock = sk_psock(sk);
	if (likely(psock)) {
		write_lock_bh(&sk->sk_callback_lock);
		strp_data_ready(&psock->parser.strp);
		write_unlock_bh(&sk->sk_callback_lock);
	}
	rcu_read_unlock();
}