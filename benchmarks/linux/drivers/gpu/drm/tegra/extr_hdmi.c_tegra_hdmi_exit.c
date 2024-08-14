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
struct tegra_hdmi {int /*<<< orphan*/  hdmi; int /*<<< orphan*/  pll; int /*<<< orphan*/  vdd; int /*<<< orphan*/  output; } ;
struct host1x_client {int dummy; } ;

/* Variables and functions */
 struct tegra_hdmi* host1x_client_to_hdmi (struct host1x_client*) ; 
 int /*<<< orphan*/  regulator_disable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tegra_output_exit (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int tegra_hdmi_exit(struct host1x_client *client)
{
	struct tegra_hdmi *hdmi = host1x_client_to_hdmi(client);

	tegra_output_exit(&hdmi->output);

	regulator_disable(hdmi->vdd);
	regulator_disable(hdmi->pll);
	regulator_disable(hdmi->hdmi);

	return 0;
}