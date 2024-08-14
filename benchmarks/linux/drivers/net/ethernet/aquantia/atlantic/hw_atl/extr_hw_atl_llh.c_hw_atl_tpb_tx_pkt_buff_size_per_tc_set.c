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
struct aq_hw_s {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  HW_ATL_TPB_TXBBUF_SIZE_ADR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HW_ATL_TPB_TXBBUF_SIZE_MSK ; 
 int /*<<< orphan*/  HW_ATL_TPB_TXBBUF_SIZE_SHIFT ; 
 int /*<<< orphan*/  aq_hw_write_reg_bit (struct aq_hw_s*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void hw_atl_tpb_tx_pkt_buff_size_per_tc_set(struct aq_hw_s *aq_hw,
					    u32 tx_pkt_buff_size_per_tc, u32 buffer)
{
	aq_hw_write_reg_bit(aq_hw, HW_ATL_TPB_TXBBUF_SIZE_ADR(buffer),
			    HW_ATL_TPB_TXBBUF_SIZE_MSK,
			    HW_ATL_TPB_TXBBUF_SIZE_SHIFT,
			    tx_pkt_buff_size_per_tc);
}