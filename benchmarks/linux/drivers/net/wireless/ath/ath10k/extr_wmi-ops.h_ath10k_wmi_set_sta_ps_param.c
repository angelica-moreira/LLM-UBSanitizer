#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct sk_buff {int dummy; } ;
struct TYPE_6__ {TYPE_2__* cmd; TYPE_1__* ops; } ;
struct ath10k {TYPE_3__ wmi; } ;
typedef  enum wmi_sta_powersave_param { ____Placeholder_wmi_sta_powersave_param } wmi_sta_powersave_param ;
struct TYPE_5__ {int /*<<< orphan*/  sta_powersave_param_cmdid; } ;
struct TYPE_4__ {struct sk_buff* (* gen_set_sta_ps ) (struct ath10k*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 scalar_t__ IS_ERR (struct sk_buff*) ; 
 int PTR_ERR (struct sk_buff*) ; 
 int ath10k_wmi_cmd_send (struct ath10k*,struct sk_buff*,int /*<<< orphan*/ ) ; 
 struct sk_buff* stub1 (struct ath10k*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int
ath10k_wmi_set_sta_ps_param(struct ath10k *ar, u32 vdev_id,
			    enum wmi_sta_powersave_param param_id, u32 value)
{
	struct sk_buff *skb;

	if (!ar->wmi.ops->gen_set_sta_ps)
		return -EOPNOTSUPP;

	skb = ar->wmi.ops->gen_set_sta_ps(ar, vdev_id, param_id, value);
	if (IS_ERR(skb))
		return PTR_ERR(skb);

	return ath10k_wmi_cmd_send(ar, skb,
				   ar->wmi.cmd->sta_powersave_param_cmdid);
}