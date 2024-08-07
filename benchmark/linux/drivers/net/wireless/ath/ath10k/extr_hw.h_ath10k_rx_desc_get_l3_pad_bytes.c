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
struct htt_rx_desc {int dummy; } ;
struct ath10k_hw_params {TYPE_1__* hw_ops; } ;
struct TYPE_2__ {int (* rx_desc_get_l3_pad_bytes ) (struct htt_rx_desc*) ;} ;

/* Variables and functions */
 int stub1 (struct htt_rx_desc*) ; 

__attribute__((used)) static inline int
ath10k_rx_desc_get_l3_pad_bytes(struct ath10k_hw_params *hw,
				struct htt_rx_desc *rxd)
{
	if (hw->hw_ops->rx_desc_get_l3_pad_bytes)
		return hw->hw_ops->rx_desc_get_l3_pad_bytes(rxd);
	return 0;
}