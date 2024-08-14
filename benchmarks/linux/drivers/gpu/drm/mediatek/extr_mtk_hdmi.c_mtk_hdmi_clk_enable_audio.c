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
struct mtk_hdmi {int /*<<< orphan*/ * clk; } ;

/* Variables and functions */
 size_t MTK_HDMI_CLK_AUD_BCLK ; 
 size_t MTK_HDMI_CLK_AUD_SPDIF ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mtk_hdmi_clk_enable_audio(struct mtk_hdmi *hdmi)
{
	int ret;

	ret = clk_prepare_enable(hdmi->clk[MTK_HDMI_CLK_AUD_BCLK]);
	if (ret)
		return ret;

	ret = clk_prepare_enable(hdmi->clk[MTK_HDMI_CLK_AUD_SPDIF]);
	if (ret)
		goto err;

	return 0;
err:
	clk_disable_unprepare(hdmi->clk[MTK_HDMI_CLK_AUD_BCLK]);
	return ret;
}