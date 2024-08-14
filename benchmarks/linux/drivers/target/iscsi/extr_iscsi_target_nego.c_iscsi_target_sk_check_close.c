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
struct iscsi_conn {int /*<<< orphan*/  login_flags; TYPE_1__* sock; } ;
struct TYPE_2__ {struct sock* sk; } ;

/* Variables and functions */
 int /*<<< orphan*/  LOGIN_FLAGS_CLOSED ; 
 scalar_t__ __iscsi_target_sk_check_close (struct sock*) ; 
 int /*<<< orphan*/  read_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  read_unlock_bh (int /*<<< orphan*/ *) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static bool iscsi_target_sk_check_close(struct iscsi_conn *conn)
{
	bool state = false;

	if (conn->sock) {
		struct sock *sk = conn->sock->sk;

		read_lock_bh(&sk->sk_callback_lock);
		state = (__iscsi_target_sk_check_close(sk) ||
			 test_bit(LOGIN_FLAGS_CLOSED, &conn->login_flags));
		read_unlock_bh(&sk->sk_callback_lock);
	}
	return state;
}