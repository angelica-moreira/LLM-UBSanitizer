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
struct sock {int /*<<< orphan*/  (* sk_data_ready ) (struct sock*) ;} ;
struct l2cap_chan {struct sock* data; } ;
struct TYPE_2__ {struct sock* parent; } ;

/* Variables and functions */
 TYPE_1__* bt_sk (struct sock*) ; 
 int /*<<< orphan*/  lock_sock (struct sock*) ; 
 int /*<<< orphan*/  release_sock (struct sock*) ; 
 int /*<<< orphan*/  stub1 (struct sock*) ; 

__attribute__((used)) static void l2cap_sock_defer_cb(struct l2cap_chan *chan)
{
	struct sock *parent, *sk = chan->data;

	lock_sock(sk);

	parent = bt_sk(sk)->parent;
	if (parent)
		parent->sk_data_ready(parent);

	release_sock(sk);
}