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
struct sock {int dummy; } ;
struct sk_buff {int dummy; } ;
struct llc_conn_state_ev {int /*<<< orphan*/  status; } ;

/* Variables and functions */
 int /*<<< orphan*/  LLC_STATUS_REMOTE_BUSY ; 
 struct llc_conn_state_ev* llc_conn_ev (struct sk_buff*) ; 

int llc_conn_ev_qlfy_set_status_remote_busy(struct sock *sk,
					    struct sk_buff *skb)
{
	struct llc_conn_state_ev *ev = llc_conn_ev(skb);

	ev->status = LLC_STATUS_REMOTE_BUSY;
	return 0;
}