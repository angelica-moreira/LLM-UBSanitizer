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
typedef  scalar_t__ u32 ;
struct wmi_vdev_set_param_cmd {void* param_value; void* param_id; void* vdev_id; } ;
struct sk_buff {scalar_t__ data; } ;
struct ath10k {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ATH10K_DBG_WMI ; 
 int /*<<< orphan*/  ENOMEM ; 
 int /*<<< orphan*/  EOPNOTSUPP ; 
 struct sk_buff* ERR_PTR (int /*<<< orphan*/ ) ; 
 scalar_t__ WMI_VDEV_PARAM_UNSUPPORTED ; 
 void* __cpu_to_le32 (scalar_t__) ; 
 int /*<<< orphan*/  ath10k_dbg (struct ath10k*,int /*<<< orphan*/ ,char*,scalar_t__,...) ; 
 struct sk_buff* ath10k_wmi_alloc_skb (struct ath10k*,int) ; 

__attribute__((used)) static struct sk_buff *
ath10k_wmi_op_gen_vdev_set_param(struct ath10k *ar, u32 vdev_id,
				 u32 param_id, u32 param_value)
{
	struct wmi_vdev_set_param_cmd *cmd;
	struct sk_buff *skb;

	if (param_id == WMI_VDEV_PARAM_UNSUPPORTED) {
		ath10k_dbg(ar, ATH10K_DBG_WMI,
			   "vdev param %d not supported by firmware\n",
			    param_id);
		return ERR_PTR(-EOPNOTSUPP);
	}

	skb = ath10k_wmi_alloc_skb(ar, sizeof(*cmd));
	if (!skb)
		return ERR_PTR(-ENOMEM);

	cmd = (struct wmi_vdev_set_param_cmd *)skb->data;
	cmd->vdev_id     = __cpu_to_le32(vdev_id);
	cmd->param_id    = __cpu_to_le32(param_id);
	cmd->param_value = __cpu_to_le32(param_value);

	ath10k_dbg(ar, ATH10K_DBG_WMI,
		   "wmi vdev id 0x%x set param %d value %d\n",
		   vdev_id, param_id, param_value);
	return skb;
}