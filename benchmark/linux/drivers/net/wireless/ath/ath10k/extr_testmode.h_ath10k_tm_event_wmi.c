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
typedef  int /*<<< orphan*/  u32 ;
struct sk_buff {int dummy; } ;
struct ath10k {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline bool ath10k_tm_event_wmi(struct ath10k *ar, u32 cmd_id,
				       struct sk_buff *skb)
{
	return false;
}