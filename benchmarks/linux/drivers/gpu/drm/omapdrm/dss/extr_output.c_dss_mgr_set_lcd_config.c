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
struct omap_dss_device {int /*<<< orphan*/  dispc_channel; TYPE_2__* dss; } ;
struct dss_lcd_mgr_config {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  mgr_ops_priv; TYPE_1__* mgr_ops; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* set_lcd_config ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct dss_lcd_mgr_config const*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct dss_lcd_mgr_config const*) ; 

void dss_mgr_set_lcd_config(struct omap_dss_device *dssdev,
		const struct dss_lcd_mgr_config *config)
{
	dssdev->dss->mgr_ops->set_lcd_config(dssdev->dss->mgr_ops_priv,
					     dssdev->dispc_channel, config);
}