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
struct omap_dss_device {int dummy; } ;
struct dsi_data {int te_enabled; } ;

/* Variables and functions */
 struct dsi_data* to_dsi_data (struct omap_dss_device*) ; 

__attribute__((used)) static int dsi_enable_te(struct omap_dss_device *dssdev, bool enable)
{
	struct dsi_data *dsi = to_dsi_data(dssdev);

	dsi->te_enabled = enable;
	return 0;
}