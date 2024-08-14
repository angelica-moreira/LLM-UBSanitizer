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
struct panel_drv_data {int ulps_enabled; int /*<<< orphan*/  ext_te_gpio; TYPE_3__* pdev; int /*<<< orphan*/  channel; struct omap_dss_device* in; } ;
struct TYPE_5__ {TYPE_1__* dsi; } ;
struct omap_dss_device {TYPE_2__ ops; } ;
struct TYPE_6__ {int /*<<< orphan*/  dev; } ;
struct TYPE_4__ {int (* enable ) (struct omap_dss_device*) ;int /*<<< orphan*/  (* enable_hs ) (struct omap_dss_device*,int /*<<< orphan*/ ,int) ;} ;

/* Variables and functions */
 int _dsicm_enable_te (struct panel_drv_data*,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int dsicm_panel_reset (struct panel_drv_data*) ; 
 int /*<<< orphan*/  dsicm_queue_ulps_work (struct panel_drv_data*) ; 
 int /*<<< orphan*/  enable_irq (int /*<<< orphan*/ ) ; 
 scalar_t__ gpio_is_valid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_to_irq (int /*<<< orphan*/ ) ; 
 int stub1 (struct omap_dss_device*) ; 
 int /*<<< orphan*/  stub2 (struct omap_dss_device*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int dsicm_exit_ulps(struct panel_drv_data *ddata)
{
	struct omap_dss_device *in = ddata->in;
	int r;

	if (!ddata->ulps_enabled)
		return 0;

	r = in->ops.dsi->enable(in);
	if (r) {
		dev_err(&ddata->pdev->dev, "failed to enable DSI\n");
		goto err1;
	}

	in->ops.dsi->enable_hs(in, ddata->channel, true);

	r = _dsicm_enable_te(ddata, true);
	if (r) {
		dev_err(&ddata->pdev->dev, "failed to re-enable TE");
		goto err2;
	}

	if (gpio_is_valid(ddata->ext_te_gpio))
		enable_irq(gpio_to_irq(ddata->ext_te_gpio));

	dsicm_queue_ulps_work(ddata);

	ddata->ulps_enabled = false;

	return 0;

err2:
	dev_err(&ddata->pdev->dev, "failed to exit ULPS");

	r = dsicm_panel_reset(ddata);
	if (!r) {
		if (gpio_is_valid(ddata->ext_te_gpio))
			enable_irq(gpio_to_irq(ddata->ext_te_gpio));
		ddata->ulps_enabled = false;
	}
err1:
	dsicm_queue_ulps_work(ddata);

	return r;
}