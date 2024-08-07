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
struct TYPE_5__ {int lck_div; int pck_div; } ;
struct TYPE_4__ {TYPE_2__ clock_info; } ;
struct dpi_data {TYPE_1__ mgr_config; int /*<<< orphan*/  pll; } ;
struct TYPE_6__ {unsigned long* clkout; } ;
struct dpi_clk_calc_ctx {TYPE_2__ dispc_cinfo; TYPE_3__ dsi_cinfo; } ;
typedef  enum omap_channel { ____Placeholder_omap_channel } omap_channel ;

/* Variables and functions */
 int EINVAL ; 
 size_t HSDIV_DISPC ; 
 int dpi_dsi_clk_calc (struct dpi_data*,unsigned long,struct dpi_clk_calc_ctx*) ; 
 int /*<<< orphan*/  dpi_get_alt_clk_src (int) ; 
 int dss_pll_set_config (int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  dss_select_lcd_clk_source (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int dpi_set_dsi_clk(struct dpi_data *dpi, enum omap_channel channel,
		unsigned long pck_req, unsigned long *fck, int *lck_div,
		int *pck_div)
{
	struct dpi_clk_calc_ctx ctx;
	int r;
	bool ok;

	ok = dpi_dsi_clk_calc(dpi, pck_req, &ctx);
	if (!ok)
		return -EINVAL;

	r = dss_pll_set_config(dpi->pll, &ctx.dsi_cinfo);
	if (r)
		return r;

	dss_select_lcd_clk_source(channel,
			dpi_get_alt_clk_src(channel));

	dpi->mgr_config.clock_info = ctx.dispc_cinfo;

	*fck = ctx.dsi_cinfo.clkout[HSDIV_DISPC];
	*lck_div = ctx.dispc_cinfo.lck_div;
	*pck_div = ctx.dispc_cinfo.pck_div;

	return 0;
}