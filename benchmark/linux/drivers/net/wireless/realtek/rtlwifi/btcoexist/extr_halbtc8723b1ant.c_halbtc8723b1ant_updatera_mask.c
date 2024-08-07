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
typedef  scalar_t__ u32 ;
struct btc_coexist {int /*<<< orphan*/  (* btc_set ) (struct btc_coexist*,int /*<<< orphan*/ ,scalar_t__*) ;} ;
struct TYPE_2__ {scalar_t__ curra_mask; scalar_t__ prera_mask; } ;

/* Variables and functions */
 int /*<<< orphan*/  BTC_SET_ACT_UPDATE_RAMASK ; 
 TYPE_1__* coex_dm ; 
 int /*<<< orphan*/  stub1 (struct btc_coexist*,int /*<<< orphan*/ ,scalar_t__*) ; 

__attribute__((used)) static void halbtc8723b1ant_updatera_mask(struct btc_coexist *btcoexist,
					  bool force_exec, u32 dis_rate_mask)
{
	coex_dm->curra_mask = dis_rate_mask;

	if (force_exec || (coex_dm->prera_mask != coex_dm->curra_mask))
		btcoexist->btc_set(btcoexist, BTC_SET_ACT_UPDATE_RAMASK,
				   &coex_dm->curra_mask);

	coex_dm->prera_mask = coex_dm->curra_mask;
}