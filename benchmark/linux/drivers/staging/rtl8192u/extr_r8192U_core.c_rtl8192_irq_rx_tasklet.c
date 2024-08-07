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
struct sk_buff {scalar_t__ cb; } ;
struct rtl8192_rx_info {int out_pipe; } ;
struct r8192_priv {int /*<<< orphan*/  IrpPendingCount; int /*<<< orphan*/  skb_queue; } ;

/* Variables and functions */
 int /*<<< orphan*/  COMP_ERR ; 
 int /*<<< orphan*/  COMP_RECV ; 
 int /*<<< orphan*/  RT_TRACE (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  dev_kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  rtl8192_rx_cmd (struct sk_buff*) ; 
 int /*<<< orphan*/  rtl8192_rx_nomal (struct sk_buff*) ; 
 struct sk_buff* skb_dequeue (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void rtl8192_irq_rx_tasklet(struct r8192_priv *priv)
{
	struct sk_buff *skb;
	struct rtl8192_rx_info *info;

	while (NULL != (skb = skb_dequeue(&priv->skb_queue))) {
		info = (struct rtl8192_rx_info *)skb->cb;
		switch (info->out_pipe) {
		/* Nomal packet pipe */
		case 3:
			priv->IrpPendingCount--;
			rtl8192_rx_nomal(skb);
			break;

		/* Command packet pipe */
		case 9:
			RT_TRACE(COMP_RECV, "command in-pipe index(%d)\n",
				 info->out_pipe);

			rtl8192_rx_cmd(skb);
			break;

		default: /* should never get here! */
			RT_TRACE(COMP_ERR, "Unknown in-pipe index(%d)\n",
				 info->out_pipe);
			dev_kfree_skb(skb);
			break;
		}
	}
}