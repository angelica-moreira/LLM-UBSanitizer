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
struct TYPE_2__ {int /*<<< orphan*/  addr; } ;
struct wmi_ready_event {TYPE_1__ mac_addr; int /*<<< orphan*/  status; int /*<<< orphan*/  abi_version; int /*<<< orphan*/  sw_version; } ;
struct wmi_rdy_ev_arg {int /*<<< orphan*/  mac_addr; int /*<<< orphan*/  status; int /*<<< orphan*/  abi_version; int /*<<< orphan*/  sw_version; } ;
struct sk_buff {int len; scalar_t__ data; } ;
struct ath10k {int dummy; } ;

/* Variables and functions */
 int EPROTO ; 
 int /*<<< orphan*/  skb_pull (struct sk_buff*,int) ; 

__attribute__((used)) static int ath10k_wmi_op_pull_rdy_ev(struct ath10k *ar, struct sk_buff *skb,
				     struct wmi_rdy_ev_arg *arg)
{
	struct wmi_ready_event *ev = (void *)skb->data;

	if (skb->len < sizeof(*ev))
		return -EPROTO;

	skb_pull(skb, sizeof(*ev));
	arg->sw_version = ev->sw_version;
	arg->abi_version = ev->abi_version;
	arg->status = ev->status;
	arg->mac_addr = ev->mac_addr.addr;

	return 0;
}