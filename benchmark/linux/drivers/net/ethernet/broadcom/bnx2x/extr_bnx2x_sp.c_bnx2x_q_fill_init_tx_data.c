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
struct TYPE_2__ {void* hi; void* lo; } ;
struct client_init_tx_data {scalar_t__ state; TYPE_1__ tx_bd_page_base; int /*<<< orphan*/  tss_leading_client_id; int /*<<< orphan*/  tx_sb_index_number; int /*<<< orphan*/  tx_status_block_id; int /*<<< orphan*/  tunnel_non_lso_pcsum_location; void* tunnel_lso_inc_ip_id; void* refuse_outband_vlan_flg; void* force_default_pri_flg; void* anti_spoofing_flg; void* tx_switching_flg; void* default_vlan_flg; int /*<<< orphan*/  default_vlan; void* enforce_security_flg; } ;
struct bnx2x_txq_setup_params {int /*<<< orphan*/  dscr_map; int /*<<< orphan*/  tss_leading_cl_id; int /*<<< orphan*/  sb_cq_index; int /*<<< orphan*/  fw_sb_id; int /*<<< orphan*/  default_vlan; } ;
struct bnx2x_queue_sp_obj {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BNX2X_Q_FLG_ANTI_SPOOF ; 
 int /*<<< orphan*/  BNX2X_Q_FLG_DEF_VLAN ; 
 int /*<<< orphan*/  BNX2X_Q_FLG_FORCE_DEFAULT_PRI ; 
 int /*<<< orphan*/  BNX2X_Q_FLG_PCSUM_ON_PKT ; 
 int /*<<< orphan*/  BNX2X_Q_FLG_REFUSE_OUTBAND_VLAN ; 
 int /*<<< orphan*/  BNX2X_Q_FLG_TUN_INC_INNER_IP_ID ; 
 int /*<<< orphan*/  BNX2X_Q_FLG_TX_SEC ; 
 int /*<<< orphan*/  BNX2X_Q_FLG_TX_SWITCH ; 
 int /*<<< orphan*/  CSUM_ON_BD ; 
 int /*<<< orphan*/  CSUM_ON_PKT ; 
 int /*<<< orphan*/  U64_HI (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  U64_LO (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_le16 (int /*<<< orphan*/ ) ; 
 void* cpu_to_le32 (int /*<<< orphan*/ ) ; 
 void* test_bit (int /*<<< orphan*/ ,unsigned long*) ; 

__attribute__((used)) static void bnx2x_q_fill_init_tx_data(struct bnx2x_queue_sp_obj *o,
				struct bnx2x_txq_setup_params *params,
				struct client_init_tx_data *tx_data,
				unsigned long *flags)
{
	tx_data->enforce_security_flg =
		test_bit(BNX2X_Q_FLG_TX_SEC, flags);
	tx_data->default_vlan =
		cpu_to_le16(params->default_vlan);
	tx_data->default_vlan_flg =
		test_bit(BNX2X_Q_FLG_DEF_VLAN, flags);
	tx_data->tx_switching_flg =
		test_bit(BNX2X_Q_FLG_TX_SWITCH, flags);
	tx_data->anti_spoofing_flg =
		test_bit(BNX2X_Q_FLG_ANTI_SPOOF, flags);
	tx_data->force_default_pri_flg =
		test_bit(BNX2X_Q_FLG_FORCE_DEFAULT_PRI, flags);
	tx_data->refuse_outband_vlan_flg =
		test_bit(BNX2X_Q_FLG_REFUSE_OUTBAND_VLAN, flags);
	tx_data->tunnel_lso_inc_ip_id =
		test_bit(BNX2X_Q_FLG_TUN_INC_INNER_IP_ID, flags);
	tx_data->tunnel_non_lso_pcsum_location =
		test_bit(BNX2X_Q_FLG_PCSUM_ON_PKT, flags) ? CSUM_ON_PKT :
							    CSUM_ON_BD;

	tx_data->tx_status_block_id = params->fw_sb_id;
	tx_data->tx_sb_index_number = params->sb_cq_index;
	tx_data->tss_leading_client_id = params->tss_leading_cl_id;

	tx_data->tx_bd_page_base.lo =
		cpu_to_le32(U64_LO(params->dscr_map));
	tx_data->tx_bd_page_base.hi =
		cpu_to_le32(U64_HI(params->dscr_map));

	/* Don't configure any Tx switching mode during queue SETUP */
	tx_data->state = 0;
}