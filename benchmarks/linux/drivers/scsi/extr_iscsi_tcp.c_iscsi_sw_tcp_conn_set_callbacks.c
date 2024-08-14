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
struct sock {int /*<<< orphan*/  sk_callback_lock; int /*<<< orphan*/  sk_write_space; int /*<<< orphan*/  sk_state_change; int /*<<< orphan*/  sk_data_ready; struct iscsi_conn* sk_user_data; } ;
struct iscsi_tcp_conn {struct iscsi_sw_tcp_conn* dd_data; } ;
struct iscsi_sw_tcp_conn {int /*<<< orphan*/  old_write_space; int /*<<< orphan*/  old_state_change; int /*<<< orphan*/  old_data_ready; TYPE_1__* sock; } ;
struct iscsi_conn {struct iscsi_tcp_conn* dd_data; } ;
struct TYPE_2__ {struct sock* sk; } ;

/* Variables and functions */
 int /*<<< orphan*/  iscsi_sw_tcp_data_ready ; 
 int /*<<< orphan*/  iscsi_sw_tcp_state_change ; 
 int /*<<< orphan*/  iscsi_sw_tcp_write_space ; 
 int /*<<< orphan*/  write_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  write_unlock_bh (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void iscsi_sw_tcp_conn_set_callbacks(struct iscsi_conn *conn)
{
	struct iscsi_tcp_conn *tcp_conn = conn->dd_data;
	struct iscsi_sw_tcp_conn *tcp_sw_conn = tcp_conn->dd_data;
	struct sock *sk = tcp_sw_conn->sock->sk;

	/* assign new callbacks */
	write_lock_bh(&sk->sk_callback_lock);
	sk->sk_user_data = conn;
	tcp_sw_conn->old_data_ready = sk->sk_data_ready;
	tcp_sw_conn->old_state_change = sk->sk_state_change;
	tcp_sw_conn->old_write_space = sk->sk_write_space;
	sk->sk_data_ready = iscsi_sw_tcp_data_ready;
	sk->sk_state_change = iscsi_sw_tcp_state_change;
	sk->sk_write_space = iscsi_sw_tcp_write_space;
	write_unlock_bh(&sk->sk_callback_lock);
}