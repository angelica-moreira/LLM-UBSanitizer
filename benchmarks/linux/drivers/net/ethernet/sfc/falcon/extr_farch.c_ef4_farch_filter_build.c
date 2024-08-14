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
typedef  int u32 ;
struct ef4_farch_filter_spec {int flags; int dmaq_id; int* data; int /*<<< orphan*/  type; } ;
typedef  int /*<<< orphan*/  ef4_oword_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
 int /*<<< orphan*/  EF4_DWORD_0 ; 
 int /*<<< orphan*/  EF4_DWORD_1 ; 
 int /*<<< orphan*/  EF4_DWORD_2 ; 
 int /*<<< orphan*/  EF4_FARCH_FILTER_MAC_WILD ; 
#define  EF4_FARCH_FILTER_TABLE_RX_IP 130 
#define  EF4_FARCH_FILTER_TABLE_RX_MAC 129 
#define  EF4_FARCH_FILTER_TABLE_TX_MAC 128 
 int /*<<< orphan*/  EF4_FARCH_FILTER_UDP_FULL ; 
 int /*<<< orphan*/  EF4_FARCH_FILTER_UDP_WILD ; 
 int EF4_FILTER_FLAG_RX_RSS ; 
 int EF4_FILTER_FLAG_RX_SCATTER ; 
 int /*<<< orphan*/  EF4_POPULATE_OWORD_5 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  EF4_POPULATE_OWORD_7 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  FRF_BZ_RSS_EN ; 
 int /*<<< orphan*/  FRF_BZ_RXQ_ID ; 
 int /*<<< orphan*/  FRF_BZ_SCATTER_EN ; 
 int /*<<< orphan*/  FRF_BZ_TCP_UDP ; 
 int /*<<< orphan*/  FRF_CZ_RMFT_DEST_MAC_HI ; 
 int /*<<< orphan*/  FRF_CZ_RMFT_DEST_MAC_LO ; 
 int /*<<< orphan*/  FRF_CZ_RMFT_RSS_EN ; 
 int /*<<< orphan*/  FRF_CZ_RMFT_RXQ_ID ; 
 int /*<<< orphan*/  FRF_CZ_RMFT_SCATTER_EN ; 
 int /*<<< orphan*/  FRF_CZ_RMFT_VLAN_ID ; 
 int /*<<< orphan*/  FRF_CZ_RMFT_WILDCARD_MATCH ; 
 int /*<<< orphan*/  FRF_CZ_TMFT_SRC_MAC_HI ; 
 int /*<<< orphan*/  FRF_CZ_TMFT_SRC_MAC_LO ; 
 int /*<<< orphan*/  FRF_CZ_TMFT_TXQ_ID ; 
 int /*<<< orphan*/  FRF_CZ_TMFT_VLAN_ID ; 
 int /*<<< orphan*/  FRF_CZ_TMFT_WILDCARD_MATCH ; 
 int ef4_farch_filter_spec_table_id (struct ef4_farch_filter_spec*) ; 

__attribute__((used)) static u32 ef4_farch_filter_build(ef4_oword_t *filter,
				  struct ef4_farch_filter_spec *spec)
{
	u32 data3;

	switch (ef4_farch_filter_spec_table_id(spec)) {
	case EF4_FARCH_FILTER_TABLE_RX_IP: {
		bool is_udp = (spec->type == EF4_FARCH_FILTER_UDP_FULL ||
			       spec->type == EF4_FARCH_FILTER_UDP_WILD);
		EF4_POPULATE_OWORD_7(
			*filter,
			FRF_BZ_RSS_EN,
			!!(spec->flags & EF4_FILTER_FLAG_RX_RSS),
			FRF_BZ_SCATTER_EN,
			!!(spec->flags & EF4_FILTER_FLAG_RX_SCATTER),
			FRF_BZ_TCP_UDP, is_udp,
			FRF_BZ_RXQ_ID, spec->dmaq_id,
			EF4_DWORD_2, spec->data[2],
			EF4_DWORD_1, spec->data[1],
			EF4_DWORD_0, spec->data[0]);
		data3 = is_udp;
		break;
	}

	case EF4_FARCH_FILTER_TABLE_RX_MAC: {
		bool is_wild = spec->type == EF4_FARCH_FILTER_MAC_WILD;
		EF4_POPULATE_OWORD_7(
			*filter,
			FRF_CZ_RMFT_RSS_EN,
			!!(spec->flags & EF4_FILTER_FLAG_RX_RSS),
			FRF_CZ_RMFT_SCATTER_EN,
			!!(spec->flags & EF4_FILTER_FLAG_RX_SCATTER),
			FRF_CZ_RMFT_RXQ_ID, spec->dmaq_id,
			FRF_CZ_RMFT_WILDCARD_MATCH, is_wild,
			FRF_CZ_RMFT_DEST_MAC_HI, spec->data[2],
			FRF_CZ_RMFT_DEST_MAC_LO, spec->data[1],
			FRF_CZ_RMFT_VLAN_ID, spec->data[0]);
		data3 = is_wild;
		break;
	}

	case EF4_FARCH_FILTER_TABLE_TX_MAC: {
		bool is_wild = spec->type == EF4_FARCH_FILTER_MAC_WILD;
		EF4_POPULATE_OWORD_5(*filter,
				     FRF_CZ_TMFT_TXQ_ID, spec->dmaq_id,
				     FRF_CZ_TMFT_WILDCARD_MATCH, is_wild,
				     FRF_CZ_TMFT_SRC_MAC_HI, spec->data[2],
				     FRF_CZ_TMFT_SRC_MAC_LO, spec->data[1],
				     FRF_CZ_TMFT_VLAN_ID, spec->data[0]);
		data3 = is_wild | spec->dmaq_id << 1;
		break;
	}

	default:
		BUG();
	}

	return spec->data[0] ^ spec->data[1] ^ spec->data[2] ^ data3;
}