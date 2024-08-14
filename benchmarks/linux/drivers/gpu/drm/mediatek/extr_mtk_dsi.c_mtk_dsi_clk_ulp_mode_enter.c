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
struct mtk_dsi {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DSI_PHY_LCCON ; 
 int /*<<< orphan*/  LC_HS_TX_EN ; 
 int /*<<< orphan*/  LC_ULPM_EN ; 
 int /*<<< orphan*/  mtk_dsi_mask (struct mtk_dsi*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void mtk_dsi_clk_ulp_mode_enter(struct mtk_dsi *dsi)
{
	mtk_dsi_mask(dsi, DSI_PHY_LCCON, LC_HS_TX_EN, 0);
	mtk_dsi_mask(dsi, DSI_PHY_LCCON, LC_ULPM_EN, 0);
}