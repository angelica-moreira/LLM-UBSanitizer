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
struct ef4_nic {struct ef4_farch_filter_state* filter_state; } ;
struct ef4_farch_filter_table {scalar_t__* search_limit; scalar_t__ size; } ;
struct ef4_farch_filter_state {struct ef4_farch_filter_table* table; } ;
typedef  int /*<<< orphan*/  ef4_oword_t ;

/* Variables and functions */
 scalar_t__ EF4_FARCH_FILTER_CTL_SRCH_FUDGE_FULL ; 
 scalar_t__ EF4_FARCH_FILTER_CTL_SRCH_FUDGE_WILD ; 
 size_t EF4_FARCH_FILTER_MAC_FULL ; 
 size_t EF4_FARCH_FILTER_MAC_WILD ; 
 size_t EF4_FARCH_FILTER_TABLE_TX_MAC ; 
 int /*<<< orphan*/  EF4_SET_OWORD_FIELD (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  FRF_CZ_TX_ETH_FILTER_FULL_SEARCH_RANGE ; 
 int /*<<< orphan*/  FRF_CZ_TX_ETH_FILTER_WILD_SEARCH_RANGE ; 
 int /*<<< orphan*/  FR_AZ_TX_CFG ; 
 int /*<<< orphan*/  ef4_reado (struct ef4_nic*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ef4_writeo (struct ef4_nic*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ef4_farch_filter_push_tx_limits(struct ef4_nic *efx)
{
	struct ef4_farch_filter_state *state = efx->filter_state;
	struct ef4_farch_filter_table *table;
	ef4_oword_t tx_cfg;

	ef4_reado(efx, &tx_cfg, FR_AZ_TX_CFG);

	table = &state->table[EF4_FARCH_FILTER_TABLE_TX_MAC];
	if (table->size) {
		EF4_SET_OWORD_FIELD(
			tx_cfg, FRF_CZ_TX_ETH_FILTER_FULL_SEARCH_RANGE,
			table->search_limit[EF4_FARCH_FILTER_MAC_FULL] +
			EF4_FARCH_FILTER_CTL_SRCH_FUDGE_FULL);
		EF4_SET_OWORD_FIELD(
			tx_cfg, FRF_CZ_TX_ETH_FILTER_WILD_SEARCH_RANGE,
			table->search_limit[EF4_FARCH_FILTER_MAC_WILD] +
			EF4_FARCH_FILTER_CTL_SRCH_FUDGE_WILD);
	}

	ef4_writeo(efx, &tx_cfg, FR_AZ_TX_CFG);
}