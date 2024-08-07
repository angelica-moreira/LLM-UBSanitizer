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
struct otm8009a {int /*<<< orphan*/  panel; } ;
struct mipi_dsi_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  drm_panel_remove (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mipi_dsi_detach (struct mipi_dsi_device*) ; 
 struct otm8009a* mipi_dsi_get_drvdata (struct mipi_dsi_device*) ; 

__attribute__((used)) static int otm8009a_remove(struct mipi_dsi_device *dsi)
{
	struct otm8009a *ctx = mipi_dsi_get_drvdata(dsi);

	mipi_dsi_detach(dsi);
	drm_panel_remove(&ctx->panel);

	return 0;
}