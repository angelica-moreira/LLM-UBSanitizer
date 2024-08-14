#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct sdi_clk_calc_ctx {unsigned long fck; int /*<<< orphan*/  pck_max; int /*<<< orphan*/  pck_min; TYPE_2__* sdi; } ;
struct TYPE_4__ {TYPE_1__* dss; } ;
struct TYPE_3__ {int /*<<< orphan*/  dispc; } ;

/* Variables and functions */
 int dispc_div_calc (int /*<<< orphan*/ ,unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct sdi_clk_calc_ctx*) ; 
 int /*<<< orphan*/  dpi_calc_dispc_cb ; 

__attribute__((used)) static bool dpi_calc_dss_cb(unsigned long fck, void *data)
{
	struct sdi_clk_calc_ctx *ctx = data;

	ctx->fck = fck;

	return dispc_div_calc(ctx->sdi->dss->dispc, fck,
			      ctx->pck_min, ctx->pck_max,
			      dpi_calc_dispc_cb, ctx);
}