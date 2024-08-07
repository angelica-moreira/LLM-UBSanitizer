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
struct sk_buff {int dummy; } ;
struct ath10k {int dummy; } ;

/* Variables and functions */
 int ath10k_htt_t2h_msg_handler (struct ath10k*,struct sk_buff*) ; 
 int /*<<< orphan*/  dev_kfree_skb_any (struct sk_buff*) ; 

void ath10k_htt_htc_t2h_msg_handler(struct ath10k *ar, struct sk_buff *skb)
{
	bool release;

	release = ath10k_htt_t2h_msg_handler(ar, skb);

	/* Free the indication buffer */
	if (release)
		dev_kfree_skb_any(skb);
}